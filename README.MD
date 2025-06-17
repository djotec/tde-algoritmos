# Algoritmo para Cálculo de Equações do 1º e 2º Grau  
## TRABALHO DISCENTE EFETIVO (TDE) – CONSTRUÇÃO DE ALGORITMOS  
**Professor:** Nayron Morais Almeida   

---

## Descrição

Este projeto tem como objetivo o desenvolvimento de um algoritmo em linguagem C capaz de identificar e resolver equações de primeiro e segundo grau, considerando casos com e sem soluções reais. O programa foi construído com foco em modularização, clareza e eficiência, utilizando estruturas como funções, ponteiros, laços de repetição e condicionais.

A aplicação opera via linha de comando (CLI), permitindo ao usuário inserir os coeficientes da equação e receber o resultado de forma prática e automatizada.


## Funcionalidades

- Identificação automática do grau da equação (1º ou 2º grau)  
- Cálculo do discriminante (Δ) e verificação da existência de raízes reais  
- Resolução de equações lineares e quadráticas  
- Estrutura modular com funções separadas para cada etapa do processo  
- Repetição do processo conforme escolha do usuário  



## Metodologia

A estrutura do código segue uma lógica bem definida:

- `limpaEspacos(char* str)` – Remove espaços da string da equação  
- `extrairCoeficientes(const char* equacao, int* a, int* b, int* c)` – Extrai os coeficientes `a`, `b` e `c` da equação  
- `resolverEquacao(int a, int b, int c)` – Determina o tipo da equação e realiza o cálculo das raízes  
- `main()` – Gerencia o fluxo do programa, entrada e saída de dados  

A linguagem C foi escolhida por sua eficiência e por ser base do ensino de algoritmos, reforçando o domínio sobre lógica de programação e manipulação de memória.

## Exemplos de Uso

**Exemplo 1** – Equação do 2º grau com uma raiz real (Δ = 0):  
- Resultado: x = -1

**Exemplo 2** – Equação do 2º grau com duas raízes reais (Δ > 0):  
- Resultado: x₁ = -2, x₂ = 2

**Exemplo 3** – Equação do 1º grau:  
- Resultado: x = -1.67

**Exemplo 4** – Equação do 2º grau sem raízes reais (Δ < 0):  
- Resultado: “Não há raízes reais.”

## Como Executar

### Compilação

```bash
gcc main.c -o main.exe
````

### Execução

```bash
./main.exe
```


## Conclusão

Este projeto reforçou a aplicação de conteúdos essenciais da programação em C, como o uso de funções, ponteiros, estruturas condicionais e laços de repetição. Esses conceitos foram integrados em uma aplicação prática voltada à resolução de equações matemáticas do 1º e 2º grau.

O conhecimento prático resultou em um programa funcional e intuitivo, que atende tanto aos critérios da avaliação quanto ao uso real na solução de problemas matemáticos. A experiência proporcionada pelo projeto contribui para a construção de uma base sólida na prática da programação, não apenas em C, mas também como preparação para o desenvolvimento de softwares em outras linguagens.

---

## Autor

**Jó Pimentel**