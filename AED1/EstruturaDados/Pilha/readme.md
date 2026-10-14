- Faça um programa que armazene a informação de várias pessoas numa pilha.</br>

typedef struct {</br>
&emsp;char nome[30];</br>
&emsp;int idade;</br>
} Pessoa;
</br></br>

- O programa deve possuir um menu:
0. Inserir pessoa;
1. Deletar pessoa do topo;
2. Deletar pessoa por nome;
3. Limpar a pilha;
4. Listar na tela as pessoas;
5. Sair do programa;
</br></br>

Dentro do main você só pode utilizar as funções POP, PUSH, RESET, CLEAR. Não podendo acessar variáveis topo, base e pilha fora dessas funções.