Implemente uma função que calcule as raízes de uma equação do segundo grau do tipo Ax² + Bx + C = 0. 
Lembrando que:
X = (−B ± √∆) / 2A
Onde:
∆ = B² − 4AC

A variável A tem que ser diferente de zero.
• Se ∆ < 0 não existe real.
• Se ∆ = 0 existe uma raiz real.
• Se ∆ ≥ 0 existem duas raízes reais.

Essa função deve obedecer ao seguinte protótipo:
int raizes(float A,float B,float C,float * X1,float * X2);

Essa função deve ter como valor de retorno o número de raízes reais e distintas da equação. 
Se existirem raízes reais, seus valores devem ser armazenados nas variáveis apontadas por X1 e X2.