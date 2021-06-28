#include <iostream>
#include "Ordenacao.h"
#include "Uteis.h"

using namespace std;

const int TAM = 10;//para testar uma lista de tamanho diferente, terá que mudar o valor do elemento


int main()
{
    DadosParaAnalise dados[5];

       //criando os vetores e inserindo os valores
       int vetorBub[TAM];
       criarValoresAleatorio<TAM>(vetorBub);
       int vetorSel[TAM];
       copiarLista<TAM>(vetorBub,vetorSel);
       int vetorIns[TAM];
       copiarLista<TAM>(vetorBub,vetorBub);
       int vetorQui[TAM];
       copiarLista<TAM>(vetorBub,vetorQui);
       int vetorMer[TAM];
       copiarLista<TAM>(vetorBub,vetorMer);

       //executando e medindo o tempo de resposta
        dados[0].tipo = "Bubble Sort";
        dados[0].tempoDeExecucao = clock();
        bubbleSort<int,TAM>(vetorBub,dados);
        dados[0].tempoDeExecucao = clock() - dados[0].tempoDeExecucao;

        dados[1].tipo = "Selection Sort";
        dados[1].tempoDeExecucao = clock();
        selectionSort<int,TAM>(vetorSel,dados);
        dados[1].tempoDeExecucao = clock() - dados[1].tempoDeExecucao;

        dados[2].tipo = "Insertion Sort";
        dados[2].tempoDeExecucao = clock();
        insertionSort<int,TAM>(vetorIns,dados);
        dados[2].tempoDeExecucao = clock() - dados[2].tempoDeExecucao;

        dados[3].tipo = "Quick Sort";
        dados[3].tempoDeExecucao = clock();
        quickSort<int,TAM>(vetorQui,dados);
        dados[3].tempoDeExecucao = clock() - dados[3].tempoDeExecucao;

        dados[4].tipo = "Merge Sort";
        dados[4].tempoDeExecucao = clock();
        mergeSort<int,TAM>(vetorMer,dados);
        dados[4].tempoDeExecucao = clock() - dados[4].tempoDeExecucao;

        //chama a função para mostra os dados coletados

        mostrarDados(dados);

        return 0;

    }
