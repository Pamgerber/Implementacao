#ifndef UTEIS_H
#define UTEIS_H

#include <iostream>
#include<time.h>

using namespace std;

struct DadosParaAnalise{

    string tipo;
    long int tempoDeExecucao= 0;
    long int vezesLaco= 0;
    int vezesFuncao= 0;

};

template<int TAM>
void criarValoresAleatorio(int lista[TAM]){// função para alocar valores aleatórios na lista

    srand(time(NULL));

    for (int i = 0; i<TAM;i++){
        lista[i] = rand() % TAM*2;
    }
}

template<int TAM>
void copiarLista(int listaOrigen[TAM], int listaDestino[TAM]){

    for (int i = 0; i < TAM; i++) {
         listaDestino[i] = listaOrigen[i];
    }

}


void mostrarDados(DadosParaAnalise dados[5]){

    for(int i = 0; i<5; i++){
        cout<<"\n******"<<dados[i].tipo<<"******\nTempo de execucao: "<<(double) dados[i].tempoDeExecucao/CLOCKS_PER_SEC<<
                "\nLacos de repeticao: "<<dados[i].vezesLaco<<"\nRecursoes feitas: "<<dados[i].vezesFuncao-1<<"\n";

    }


}

#endif // UTEIS_H
