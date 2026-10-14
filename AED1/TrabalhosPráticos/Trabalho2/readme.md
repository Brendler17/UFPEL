<h1 align="center"> Algoritmos e Estrutura de Dados 1 </h1>
<h2 align="center"> Trabalho Prático 2 - Estrutura de Dados </h2>
<br>

<h3 align="justify"> Reservation Manager</h3>

<p align="justify">
Design a system that manages the reservation state of <b>n</b> seats that are numbered from <b>1</b> to <b>n</b>.
<br>
Implement the <b>SeatManager</b> class:
<br>
- <b>SeatManager(int n)</b> Initializes a <b>SeatManager</b> object that will manage <b>n</b> seats numbered from <b>1</b> to <b>n</b>. All seats are initially available<br>
- <b>int reserve()</b> Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.<br>
- <b>void unreserve(int seatNumber)</b> Unreserves the seat with the given <b>seatNumber</b>.<br>


This problem was taken from <a href=https://leetcode.com/problems/seat-reservation-manager/description/ >LeetCode</a>
</p>

<br>

<h3>
<a href="https://github.com/Brendler17/AED1/blob/main/TrabalhosPráticos/Trabalho2/src/main.c">
Original Code
</a>
-> Stack (12 / 69 testcases passed)
-> Complexity O(n)
</h3>

<h3>
<a href="https://github.com/Brendler17/AED1/blob/main/TrabalhosPráticos/Trabalho2/src/newMain.c">
Complemented Code 
</a>
-> MinHeap (69 / 69 testcases passed)
-> Complexity O(n log n)
</h3>