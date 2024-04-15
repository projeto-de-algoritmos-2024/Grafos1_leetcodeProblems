# 765. Couples Holding Hands

Problema: [Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/description/)

**Descrição:** <br>
There are n couples sitting in 2n seats arranged in a row and want to hold hands.

The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).

Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

**Example 1:**

Input: row = [0,2,1,3] <br>
Output: 1 <br>
Explanation: We only need to swap the second (row[1]) and third (row[2]) person. <br>

**Example 2:**

Input: row = [3,2,0,1] <br>
Output: 0 <br>
Explanation: All couples are already seated side by side. <br>

## Solução

Para este problema, será considerado cada par de elementos do vetor como um **vértice** no grafo. Sendo assim, para saber a qual casal o elemento pertence é só dividir por 2 (se par), ou subtrair 1 do elemento e depois dividir por 2 (se ímpar).

**Exemplo:**
```C++
if (row[i]%2 == 0)
    node->n1 = row[i]/2;
else node->n1 = (row[i])/2;
```
A Struct “couple” é composta por n1 e n2 (par de casal), prox1 e prox2 (para quem o n1 está apontando e para quem o n2 está apontando, seus casais), e por fim o booleano “used” (Define se o casal foi ou não usado na BFS).

**Struct couple:**
```C++
typedef struct couple{
   int n1;
   int n2;
   bool used;
   int prox1;
   int prox2;
} couple;
```
Para a construção das conexões do grafo, é varrido o vetor couples e se um dos elementos for igual, o prox correspondente apontará para a posição “i” do vetor.

**Criação das conexões:**
```C++
if (couples[j]->n1 == node->n1){
    couples[j]->prox1 = i;
    node->prox1 = j;
} else if (couples[j]->n2 == node->n1){
    couples[j]->prox2 = i;
    node->prox1 = j;
}
```


Depois de criado o grafo Couples, é feito uma BFS a partir de um vértice qualquer ainda não usado. Nessa BFS, terá um inteiro “counter” que conta quantas vezes uma aresta é adicionada. Sendo que, o resultado desse “counter” representa a quantidade de arestas na árvore, e também representa a quantidade mínima de swaps que deverá ser feita para colocar todos os elementos juntos com seus casais.

Por fim, é feita uma chamada recursiva na BFS, para garantir que todas as árvores foram contadas.
