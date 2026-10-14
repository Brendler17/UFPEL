Faça um programa que leia números do teclado e os armazene em um vetor alocado dinamicamente.
O usuario irá digitar uma sequência de números, sem limite de quantidade. Os numeros serão 
digitados um a um e, sendo que caso ele deseje encerrar a entrada de dados, ele irá digitar o número ZERO. Os dados devem ser armazenados na memória deste modo:
• Inicie com um vetor de tamanho 10 alocado dinamicamente;
• Após, caso o vetor alocado esteja cheio, aloque um novo vetor do tamanho do vetor anterior,
adicionado espaço para mais 10 valores (tamanho N+10, onde N inicia com 10);
• Copie os valores já digitados da área inicial para esta área maior e libere a memória da área inicial;
• Repita este procedimento de expandir dinamicamente com mais 10 valores o vetor alocado cada vez que o mesmo estiver cheio. Assim o vetor irá ser ’expandido’ de 10 em 10 valores.
Ao final, exiba o vetor lido. Nao use a função REALLOC.