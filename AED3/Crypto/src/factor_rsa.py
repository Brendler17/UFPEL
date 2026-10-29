"""Fatoracao de N (modulo RSA pequeno, ~384 bits) para reconstruir a chave privada.
Estrategias, em ordem: fatores pequenos (trial), Fermat (primos proximos),
Pollard p-1, Pollard rho (Brent). Retorna (p, q).
Tambem utilizavel como: python factor_rsa.py <N>
"""
import sys, math, random

def trial(n, lim=1_000_000):
    f = []
    for p in (2,3,5,7,11,13,17,19,23,29,31,37):
        while n % p == 0:
            f.append(p); n//=p
    i = 41
    while i < lim and i*i <= n:
        while n % i == 0:
            f.append(i); n//=i
        i += 2
    return f, n

def isqrt(n):
    return math.isqrt(n)

def fermat(n, maxiter=10_000_000):
    a = isqrt(n)
    if a*a < n: a += 1
    for _ in range(maxiter):
        b2 = a*a - n
        b = isqrt(b2)
        if b*b == b2:
            return (a-b, a+b)
        a += 1
    return None

def pollard_pm1(n, bound=100000):
    a = 2
    for j in range(2, bound):
        a = pow(a, j, n)
        if j % 100 == 0:
            d = math.gcd(a-1, n)
            if 1 < d < n:
                return d
    d = math.gcd(a-1, n)
    return d if 1 < d < n else None

def brent(n):
    if n % 2 == 0: return 2
    if n == 1: return 1
    while True:
        y = random.randrange(1, n-1)
        c = random.randrange(1, n-1)
        m = 128; g = q = r = 1
        while g == 1:
            x = y
            for _ in range(r): y = (y*y + c) % n
            k = 0
            while k < r and g == 1:
                ys = y
                for _ in range(min(m, r-k)):
                    y = (y*y + c) % n
                    q = (q * abs(x-y)) % n
                g = math.gcd(q, n); k += m
            r *= 2
        if g == n:
            g = 1
            while g == 1:
                ys = (ys*ys + c) % n
                g = math.gcd(abs(x-ys), n)
        if g != n:
            return g

def is_probable_prime(n):
    if n < 2: return False
    for p in (2,3,5,7,11,13,17,19,23,29,31,37):
        if n % p == 0: return n == p
    d = n-1; r = 0
    while d % 2 == 0: d//=2; r+=1
    for a in (2,3,5,7,11,13,17,19,23,29,31,37):
        x = pow(a, d, n)
        if x in (1, n-1): continue
        for _ in range(r-1):
            x = x*x % n
            if x == n-1: break
        else:
            return False
    return True

def factor(n):
    # 1) fatores pequenos
    fs, rem = trial(n, 100000)
    if rem == 1 and len(fs) == 2:
        return fs[0], fs[1]
    if fs and is_probable_prime(rem):
        return fs[0], rem
    n2 = rem if rem > 1 else n
    # 2) Fermat (primos proximos) - rapido se p~q
    f = fermat(n2, maxiter=2_000_000)
    if f and f[0] > 1 and f[0]*f[1] == n2:
        return f
    # 3) p-1
    d = pollard_pm1(n2)
    if d and n2 % d == 0:
        return d, n2//d
    # 4) rho (Brent)
    d = brent(n2)
    if d and 1 < d < n2 and n2 % d == 0:
        return d, n2//d
    return None

if __name__ == "__main__":
    if len(sys.argv) > 1:
        N = int(sys.argv[1])
        print("fatorando N de", N.bit_length(), "bits...")
        r = factor(N)
        print("resultado:", r)
        if r: print("verifica:", r[0]*r[1] == N, "primos?", is_probable_prime(r[0]), is_probable_prime(r[1]))
