#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "Uteis.h"

template <typename TIPO, int TAM>
void bubbleSort(TIPO lista[TAM], DadosParaAnalise dados[5] ){

    dados[0].vezesFuncao++;

    TIPO auxiliar;//variável para ajudar na hora de trocar o valor

    for (int j=0;j<TAM;j++) {//laço para repetir o processo para garantir a ordenação
        for (int i = 0; i < TAM - 1; i++) {// laço para percorrer a lista
            if (lista[i] > lista[i + 1]) {//condições para testar se o valor quantidade na posição i é maior que seu ascendente
                auxiliar = lista[i]; // copia o valor da posição i para uma variável auxiliar
                lista[i] = lista[i + 1];// copia o valor da posição i + 1 para a posição i
                lista[i + 1] = auxiliar;// copia o valor da variável auxiliar para a posição i+1
            }
            dados[0].vezesLaco++;
        }
        dados[0].vezesLaco++;
    }
}

template<typename TIPO, int TAM>
void selectionSort(TIPO lista[TAM], DadosParaAnalise dados[5]){

    dados[1].vezesFuncao++;


    int posMenor; // variável para guardar a posição do menor valor
    TIPO valorMenor; // variável para guardar o valor da posição a ser trocada

    for (int j = 0; j<TAM;j++) {//laço para repetir o processo para garantir a ordenação
        posMenor = j; // inicia a variável posMenor com o valor de j

        for (int i = j; i < TAM; i++) {//laÃ§o para repetir o processo para garantir a ordenação
            if (lista[i] < lista[posMenor]) {// continuaÃ§Ã£o para verificar se o valor da posição i é menor que a da
                posMenor = i;                // posição do menor anterior, se sim ele guarda a posição i em posMenor
            }
            dados[1].vezesLaco++;
        }

        valorMenor = lista[posMenor];// grava o valor da posição posMenor em valorMenor para realizar a troca
        lista[posMenor] = lista[j];//  copia o valor da posição j para a posição posMenor
        lista[j] = valorMenor;// copia o valor da variável valorMenor para a posição j da lista

        dados[1].vezesLaco++;
    }
}


template <typename  TIPO, int TAM>
void insertionSort(TIPO lista[TAM],DadosParaAnalise dados[5]){

    dados[2].vezesFuncao++;

    TIPO variavelTemporaria;// variável temporária para fazer o teste do menor

    for(int i = 1; i<TAM;i++){ // laço para percorrer a lista

        variavelTemporaria = lista[i]; // grava o valor da posição i na variável temporária

        for (int j = i-1;variavelTemporaria<lista[j] and j >= 0;j--){ // laço para percorrer de trás para frente
            // atÃ© achar um maior que o valor da
            // variÃ¡vel temporÃ¡ria
            lista[j+1] = lista[j];// avanÃ§ando o valor da posição j para uma posição à frente

            lista[j] = variavelTemporaria;// grava o valor da variável temporária na posição j

            dados[2].vezesLaco++;
        }
        dados[2].vezesLaco++;
    }
}
template <typename TIPO, int TAM>
int particionar(TIPO lista[TAM], int inicio, int fim,DadosParaAnalise dados[5]){

    TIPO variavelAuxiliar;// variável para auxiliar na troca de valores

    TIPO pivo = lista[fim];// variável para armazenar o valor do pivô

    int i = inicio;// Ã­ndice para  alocar os valores menores que o pivô

    for (int j = inicio; j < fim; j++ ){// laÃ§o para percorrer a lista para procurar valores maiores que o pivô
        if (lista[j]<=pivo){// verifica a condição do pivô ser maior que o valor em j
            variavelAuxiliar = lista[i];// guarda o valor da posição i na variável auxiliar
            lista[i] = lista[j];// copia o valor da posição j para i
            lista[j] = variavelAuxiliar;// copia o valor da variável auxiliar para j
            i++; // avançando o índice do inínio para mais 1
        }
        dados[3].vezesLaco++;
    }

    variavelAuxiliar = lista[i];// guarda o valor de i na variável auxiliar .
    lista[i] = lista[fim]; // copia o valor do fim nesse caso o pivô para i.
    lista[fim] = variavelAuxiliar;// copia o valor da variável auxiliar para fim.

    return i;//retorna um novo índice para o pivô
}

template<typename TIPO, int TAM>
void quickSort(TIPO lista[TAM],DadosParaAnalise dados[5] , int inicio = 0, int fim = TAM-1) {

    dados[3].vezesFuncao++;

    if (inicio < fim) {// verifica se a lista não possui um único elemento

        int pivo = particionar<TIPO, TAM>(lista, inicio, fim,dados);//chama a função para particionar a lista
        quickSort<TIPO, TAM>(lista,dados, inicio, pivo - 1); // ordernar o lado esquerdo do pivô
        quickSort<TIPO, TAM>(lista,dados ,pivo + 1, fim); // ordenar o lado direito do pivô

    }

}
template<typename TIPO, int TAM>
void merge(TIPO lista[TAM],int inicio,int meio,int fim, DadosParaAnalise dados[5]){// função para juntar e ordenar novamente a lista

    TIPO esquerdo[meio-inicio];// lista que irão guardar a parte esquerda da lista completa
    TIPO direito[fim-meio];// lista que irão guardar a parte esquerda da lista completa

    int j = inicio;// variável usada como índice para a lista original, ela recebe o início da lista como valor
    for (int i = 0;i < meio-inicio;++i){//laço para gravar os valores da lista origem na lista da esquerda
            esquerdo[i] = lista[j];
            ++j;
            dados[4].vezesLaco++;
        }

        j = meio;// j recebe o meio da lista como valor
        for (int i = 0;i < fim-meio;++i){//laço para gravar os valores da lista origem na lista da direita
            direito[i] = lista[j];
            ++j;
            dados[4].vezesLaco++;
        }


    int topoL = 0, topoR = 0; // variáveis que armazena os índices do topo da lista esquerda e direita

    for(int i = inicio; i < fim; ++i){//laço para percorrer a lista origem
        if(topoL>=meio-inicio){// Verifica se o índice do topo do lado esquerdo já não é maior que o tamanho da lista
            lista[i] = direito[topoR];
            ++topoR;
        } else if (topoR>=fim-meio){// Verifica se o indice do topo do lado direito já não é maior que o tamanho da lista
            lista[i] = esquerdo[topoL];
            ++topoL;
        }else if (esquerdo[topoL] < direito[topoR]){ //caso o valor do topo do lado esquerdo for menor que o topo do direito
            lista[i] = esquerdo[topoL];// e gravado na posição i da lista de origem o valor do topo do lado esquerdo
            ++topoL;
        } else {
            lista[i] = direito[topoR];// caso se for maior então o topo da lista direita passa para a posição i da lista
            ++topoR;
        }
        dados[4].vezesLaco++;

    }
}


template<typename TIPO, int TAM>
void mergeSort(TIPO lista[TAM], DadosParaAnalise dados[5], int inicio= 0, int fim = TAM){

    dados[4].vezesFuncao++;

    if ((fim-inicio)>1){//verifica o tamanho da lista para fazer a divisão
        int  meio = ((inicio+fim)/2);// encontra o meio da divisão e guarda na variável meio
        mergeSort<TIPO,TAM>(lista,dados,inicio,meio);// chama a função de mergeSort para a parte esquerda da lista
        mergeSort<TIPO,TAM>(lista,dados,meio,fim);// chama a função de mergeSort para a parte direita da lista
        merge<TIPO,TAM>(lista,inicio,meio,fim,dados);// chama a função responsável por juntar e ordenar a lista
    }
}

#endif // ORDENACAO_H
