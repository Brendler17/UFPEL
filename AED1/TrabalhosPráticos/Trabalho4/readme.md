<h1 align="center"> Algoritmos e Estrutura de Dados 1 </h1>
<h2 align="center"> Trabalho Prático 4 - Ordenação </h2>
<h3 align="center"> Gustavo Marcos Brendler </h2>
<br>

<h3 align="justify"> Smallest Subtree with all the Deepest Nodes</h3>

<p align="justify">
You have <b>n</b> jobs and <b>m</b> workers. You are given three arrays: <u><b>difficulty</b></u>, <u><b>profit</b></u>, and <u><b>worker</b></u> where:
<br>
- difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
<br>
- worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
<br>
Every worker can be assigned at most one job, but one job can be completed multiple times.
<br>
- For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
<br>
Return the maximum profit we can achieve after assigning the workers to the jobs.
<br>

This problem was taken from <a href=https://leetcode.com/problems/most-profit-assigning-work/description/ >LeetCode</a>.
</p>

<br>
<h3>

<a href="https://github.com/Brendler17/AED1/blob/main/TrabalhosPráticos/Trabalho4/src/main.c">
Original Code
</a>
-> 60/ 60 testcases passed
-> Complexity O(N log N + M log M)
</h3>

<h3>Submit do Leetcode</h3>
<p align="center">
  <img src="https://i.ibb.co/7xG8Nb9H/imagem-2025-03-16-191157818.png" alt="Submit do Leetcode" border="0" width="100%">
</p>