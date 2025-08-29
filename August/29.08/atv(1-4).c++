/*

1. Explique a diferença entre estruturas de seleção simples, composta e encadeada.
Dê um exemplo de aplicação real para cada uma.

R: Seleção Simples (if):
A lógica executa um código se a condição for verdade.
Exemplo: Se estiver chovendo, usar o guarda-chuva.

Seleção Composta (if-else):
Análisa o código se for verdadeiro ou se for falso.
Exemplo: Se tiver dinheiro, comprarei um lanche, senão, buscar dinheiro.

Seleção Encadeada (if-elif-else):
Serve para testar um monte de condições em sequência.
Exemplo:
Se nota for maior que 9 → "A"
Senão, se for maior que 7 → "B"
Senão, se for maior que 5 → "C"
Senão → "Reprovado"


2. Descreva as diferenças entre passagem por valor e por referência em C++. Em quais
situações cada uma é mais indicada?

R: Passagem por valor: Uma cópia do valor é passada para a função.
Modificações dentro da função não alteram a variável original.
Recomendado para tipos pequenos (int, float) ou quando não se deseja alterar o original.

Passagem por referência: A função recebe uma referência (acesso direto) à variável original.
Modificações dentro da função alteram a variável original.
Recomendado para tipos grandes (vetores, objetos) ou quando é necessário modificar o original.
 


3. Liste e explique pelo menos três vantagens da utilização de arquivos .h e .cpp na
construção de programas em C++.

R: 
a) ORGANIZAÇÃO E CLAREZA: Facilita a leitura e manutenção, separando a interface da implementação.
b) COMPILAÇÃO MODULAR: Reduz tempo de compilação em projetos grandes.
c) REUTILIZAÇÃO DE CÓDIGO:Headers podem ser incluídos em múltiplos arquivos .cpp, permitindo reutilizar declarações sem repetir código.


4. Explique a diferença entre memória alocada estaticamente e dinamicamente em
C++. Cite um exemplo prático de uso de cada tipo.

R:    Memória Estática:
Tamanho fixo, definido antes da execução.
Gerenciada automaticamente pelo sistema.
Exemplo: array com 5 posições.


      Memória Dinâmica:
Tamanho variável, definido durante a execução.
Gerenciada manualmente pelo programador.
Exemplo: lista de dados lidos de um arquivo (tamanho desconhecido).


*/