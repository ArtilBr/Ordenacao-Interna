#include "selecao.h"
#include "bolha.h"
#include "insercao.h"
#include "geracao.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>



//--------------------------------------------------------------//
void teste(unsigned long long int n, char ordem){

   //Delcaracao de variaveis
    //int n = (argc < 2) ? 10000 : atoi(argv[1]);
    unsigned long long int  *array = (unsigned long long int*) malloc(n*sizeof(unsigned long long int));

    if(array == NULL){
      printf("NAO TEM MEMORIA\n");
      exit(0);
    }else{
      printf("TEM MEMORIA\n");
    }

    // VARIAVEIS PARA CALCULAR O TEMPO
    clock_t inicio, fim;
    double total;


    //Geracao do conjunto a ser ordenado
    switch(ordem){
      case 'C': crescente2(array, n);
      break;
      //case 'D': decrescente(array, n);
      //break;
      //case 'A':  aleatorio(array, n);
      //break;
      //default: aleatorio(array, n);
    }

    //Mostrar o conjunto a ser ordenado
	 //mostrar(array, n);


    //Execucao do algoritmo de ordenacao
	 inicio = clock();
     //bolha(array, n);
    //insercao(array, n);
    selecao(array, n);
	 fim = clock();
     total = ((fim - inicio) / (double)CLOCKS_PER_SEC);


    //Mostrar o conjunto ordenado, tempo de execucao e status da ordenacao
	 //algoritmo.mostrar(array, n);
	 printf(" -Tempo: %f s -Ordenacao: %c.\n", total, ordem);
	 printf("EstaOrdenado: %s\n\n", isOrdenado(array, n) ? "true" : "false");

    //Desalocar o espaco de memoria do array
    free(array);

}





//=============================================================================




int main(int argc, char **argv) {

  //int v[] = {33, 10, 75, 18, 29, 42};
    //bolha(v, 6);

    for(unsigned long long int i=1000; i<=1024000; i=i*2){

        teste(i, 'C');
        //teste(i, 'D');
        //teste(i, 'A');
    }



    return 0;
}
