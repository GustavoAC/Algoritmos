#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "functions.h"
#define N 268435456
#define TEST_TYPE 1
#define FUNCTION 0
#define SEED 123451234512345
/* DONE
* Todas as funções funcionam completamente
* Instruções do usuário
* Wrapper funcionando perfeitamente (Agora sim)
* Implementação completa de números aleatórios
* Caso 3 implementado
*/

/* TODO
* Organizar #includes e arquitetura de código (Quebrei tudo de novo)
* Organizar convenções de código ( espaço entre parentes e etc )
* Rodar os testes (2hard)
*/

int main( int argc, char * argv[] ) {
//    int res;
    auto arrSz( 0ul );
    int functionType;
    int testType;
    long int key;
    int numTimes = 1;

    if ( argc == 4 ){

        std::stringstream( argv[1] ) >> arrSz;
        std::stringstream( argv[2] ) >> testType;
        std::stringstream( argv[3] ) >> functionType;

    }else{

        arrSz = N;
        testType = TEST_TYPE;
        functionType = FUNCTION;

    }

    // Para armazenar os dados.
    std::vector<long int> V(arrSz);

// Para realizar todos os testes em sequência (exceto sequencial recursiva)
#ifdef ALL_TESTS

for (int testType_Loop = 1; testType_Loop <= 2; ++testType_Loop){
    for (int functionType_Loop = 0; functionType_Loop <= 7; ++functionType_Loop){
        if (functionType_Loop == 1) continue;

    testType = testType_Loop;
    functionType = functionType_Loop;

    std::cout << "TEST_TYPE = " << testType << "\nFUNCTION_TYPE = " << functionType << "\n\n";

#endif

    //Declara um arranjo de ponteiros de função
    int (*funcs[8])( std::vector<long int>&, long int, long int, long int );
    funcs[0] = bus_seq_it;
    funcs[1] = bus_seq_rec;
    funcs[2] = wrap_sys_search;
    funcs[3] = bus_bin_it;
    funcs[4] = bus_bin_rec;
    funcs[5] = bus_ter_it;
    funcs[6] = bus_ter_rec;
    funcs[7] = wrap_sys_bsearch;

#ifdef ALL_TESTS
        std::cout << "TEST_TYPE = " << testType << "\nFUNCTION_TYPE = " << functionType << "\n\n";

    if ( functionType == 0 || testType == 3 )
#endif
    //Preenche o vetor com inteiros aleatórios
        randomFill( V, 0, 2*arrSz, SEED );
    
#ifdef ALL_TESTS
    if( functionType == 3 && testType !=3 )
#endif
    //Ordena o vetor
        std::sort ( V.begin(), V.end() );


    std::chrono::duration<double> media (0.0);

    for (unsigned int i = 16; i <= arrSz; i *= 2){
        
        switch (testType){
            case 1:                         // Pior caso: Fora do Vetor
                key = arrSz*2 + 1;
                break;
                
            case 2:                         // Caso dos 3/4 do inicio do vetor
                key = V.at( ( i-1 ) * 3/4);
                break;
                
            case 3:                         // A k-ésima ocorrência (k = 3)
                numTimes = 3;
                key = casethree( V, i, SEED, functionType );
                break;
                
        }
      
        media = std::chrono::steady_clock::duration::zero();

        for (int j = 1; j <= 100; j++){
            auto start = std::chrono::steady_clock::now();
            
            /*res = */wrapper ( V, key, 0, i-1, numTimes, functionType, funcs[functionType]);
            
            auto end = std::chrono::steady_clock::now();
            media = media + ((end - start) - media) / static_cast<double> (j);
        }

        std::cout << i << " " << std::chrono::duration <double, std::milli> (media).count() << std::endl;
    }


#ifdef ALL_TESTS
    std::cout << "\n\n\n";
    }
}
#endif

    return EXIT_SUCCESS;


}
