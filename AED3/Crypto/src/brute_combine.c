/* Combinador de 2 palavras (passphrase) em C + OpenMP, SHA-256.
 * candidato = maword [+ conector] + word, minusculo, sem espaco.
 * Conectores: "", "de", "da", "do", "e". Terminadores: "" e "\n".
 * Uso: ./brute_combine <arq_mawords> <arq_words> [minlen]
 * Compilar: gcc -O3 -fopenmp -o brute_combine brute_combine.c
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/* ---- SHA-256 (bloco unico, msg < 56 bytes) ---- */
static const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

#define ROR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

static void sha256_blk(const uint8_t *msg, size_t len, uint8_t out[32]) {
    uint8_t b[64];
    for (int i = 0; i < 64; i++)
        b[i] = 0;
    for (size_t i = 0; i < len; i++)
        b[i] = msg[i];
    b[len] = 0x80;

    uint64_t bits = (uint64_t)len * 8;
    for (int i = 0; i < 8; i++)
        b[63 - i] = (bits >> (i * 8)) & 0xff;

    uint32_t s[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint32_t w[64];
    for (int i = 0; i < 16; i++)
        w[i] = (b[i*4] << 24) | (b[i*4+1] << 16) | (b[i*4+2] << 8) | b[i*4+3];
    for (int i = 16; i < 64; i++) {
        uint32_t s0 = ROR(w[i-15], 7) ^ ROR(w[i-15], 18) ^ (w[i-15] >> 3);
        uint32_t s1 = ROR(w[i-2], 17) ^ ROR(w[i-2], 19) ^ (w[i-2] >> 10);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }

    uint32_t a = s[0], bb = s[1], c = s[2], d = s[3];
    uint32_t e = s[4], f = s[5], g = s[6], h = s[7];
    uint32_t t1, t2;
    for (int i = 0; i < 64; i++) {
        uint32_t S1 = ROR(e, 6) ^ ROR(e, 11) ^ ROR(e, 25);
        uint32_t ch = (e & f) ^ (~e & g);
        t1 = h + S1 + ch + K[i] + w[i];
        uint32_t S0 = ROR(a, 2) ^ ROR(a, 13) ^ ROR(a, 22);
        uint32_t mj = (a & bb) ^ (a & c) ^ (bb & c);
        t2 = S0 + mj;
        h = g; g = f; f = e; e = d + t1;
        d = c; c = bb; bb = a; a = t1 + t2;
    }

    s[0] += a; s[1] += bb; s[2] += c; s[3] += d;
    s[4] += e; s[5] += f; s[6] += g; s[7] += h;
    for (int i = 0; i < 8; i++) {
        out[i*4]   = s[i] >> 24;
        out[i*4+1] = s[i] >> 16;
        out[i*4+2] = s[i] >> 8;
        out[i*4+3] = s[i];
    }
}

static const char *THEX =
    "1b78cdb61662342d53da0544a38c87579c4ca0e9b171ad2979f165a6b3e28cce";
static uint8_t TARGET[32];

static void hex2bin(const char *h, uint8_t *o) {
    for (int i = 0; i < 32; i++) {
        unsigned v;
        sscanf(h + i*2, "%2x", &v);
        o[i] = v;
    }
}

static int eq(const uint8_t *a, const uint8_t *b) {
    for (int i = 0; i < 32; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

static char **load(const char *path, int *cnt) {
    FILE *f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "erro abrindo %s\n", path);
        exit(1);
    }
    int cap = 1024, n = 0;
    char **arr = malloc(cap * sizeof(char *));
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        int L = strlen(line);
        while (L > 0 && (line[L-1] == '\n' || line[L-1] == '\r'))
            line[--L] = 0;
        if (L == 0 || L > 40)
            continue;
        if (n >= cap) {
            cap *= 2;
            arr = realloc(arr, cap * sizeof(char *));
        }
        arr[n] = strdup(line);
        n++;
    }
    fclose(f);
    *cnt = n;
    return arr;
}

static const char *CONN[5] = {"", "de", "da", "do", "e"};
static volatile int FOUND = 0;

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "uso: %s <mawords> <words> [minlen]\n", argv[0]);
        return 1;
    }
    int minlen = argc > 3 ? atoi(argv[3]) : 10;
    hex2bin(THEX, TARGET);

    int n1, n2;
    char **ma = load(argv[1], &n1);
    char **wd = load(argv[2], &n2);
    printf("mawords=%d words=%d minlen=%d\n", n1, n2, minlen);
    fflush(stdout);

    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < n1; i++) {
        if (FOUND)
            continue;
        char buf[128];
        int la = strlen(ma[i]);
        memcpy(buf, ma[i], la);
        for (int j = 0; j < n2; j++) {
            int lw = strlen(wd[j]);
            for (int ci = 0; ci < 5; ci++) {
                int lc = strlen(CONN[ci]);
                int total = la + lc + lw;
                if (total < minlen || total > 55)
                    continue;
                memcpy(buf + la, CONN[ci], lc);
                memcpy(buf + la + lc, wd[j], lw);

                uint8_t d[32];
                sha256_blk((uint8_t *)buf, total, d);
                if (eq(d, TARGET)) {
                    buf[total] = 0;
                    #pragma omp critical
                    {
                        printf("\n>>> ACHOU (sem term) senha=%s\n", buf);
                        fflush(stdout);
                        FOUND = 1;
                    }
                }
                buf[total] = '\n';
                sha256_blk((uint8_t *)buf, total + 1, d);
                if (eq(d, TARGET)) {
                    buf[total] = 0;
                    #pragma omp critical
                    {
                        printf("\n>>> ACHOU (\\n) senha=%s\n", buf);
                        fflush(stdout);
                        FOUND = 1;
                    }
                }
            }
        }
    }

    if (!FOUND) {
        printf("nada.\n");
        return 2;
    }
    return 0;
}
