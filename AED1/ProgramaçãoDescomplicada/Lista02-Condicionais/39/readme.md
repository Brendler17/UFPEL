Uma empresa decide dar um aumento aos seus funcionários de acordo com uma tabela que considera o salário atual e o tempo de serviço de cada funcionário.
Os funcionários com menor salário terão um aumento proporcionalmente maior do que os funcionários com um salario maior, 
e conforme o tempo de serviço na empresa, cada funcionário irá receber um bônus adicional de salário.
Faça um programa que leia:
• o valor do salário atual do funcionário;
• o tempo de serviço desse funcionário na empresa (número de anos de trabalhos).
Use as tabelas abaixo para calcular o salário reajustado deste funcionário e imprima o valor do salario final reajustado, 
ou uma mensagem caso o funcionário não tenha direito a nenhum aumento.

<table>
  <thead>
    <tr>
      <th>Salário Atual</th>
      <th>Reajuste(%)</th>
      <th>Tempo de Serviço</th>
      <th>Bônus</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Até 500,00</td>
      <td>25%</td>
      <td>Abaixo de 1 ano</td>
      <td>Sem bônus</td>
    </tr>
    <tr>
      <td>Até 1000,00</td>
      <td>20%</td>
      <td>De 1 a 3 anos</td>
      <td>100,00</td>
    </tr>
    <tr>
      <td>Até 1500,00</td>
      <td>15%</td>
      <td>De 4 a 6 anos</td>
      <td>200,00</td>
    </tr>
    <tr>
      <td>Até 2000,00</td>
      <td>10%</td>
      <td>De 7 a 10 anos</td>
      <td>300,00</td>
    </tr>
    <tr>
      <td>Acima de 2000,00</td>
      <td>Sem reajuste</td>
      <td>Mais de 10 anos</td>
      <td>500,00</td>
    </tr>
  </tbody>
</table>