#include <vector>
#include <random>
#include <algorithm>
#include "functions.h"

//Busca Sequencial Iterativa
int bus_seq_it( std::vector<long int> &V, long int k, long int l, long int r ){
    for(/* empty */; l <= r; l++){
        if (V.at( l ) == k ) return l;
    }
    return -1;
}

//Busca Sequencial Recursiva
int bus_seq_rec( std::vector<long int> &V, long int k, long int l, long int r ){
    if ( l > r ) return -1;
    else if (V.at( l ) == k) return l;
    else return bus_seq_rec( V, k, l+1, r );

}

//Busca Binária Iterativa
int bus_bin_it( std::vector<long int> &V, long int k, long int l, long int r ){
    int m;

    while( l <= r ){
        m = ( l + r )/2;
        
        if( V.at( m ) == k ) return m;
        else if (k > V.at( m ) ) l = m+1;
        else r = m-1;
    }

    return -1;
}

//Busca Binária Recursiva
int bus_bin_rec( std::vector<long int> &V, long int k, long int l, long int r ){
    if ( l > r ) return -1;

    int m = ( l + r )/2;
    if ( k == V.at( m ) ) return m;

    else if ( k > V.at( m ) ) return bus_bin_rec( V, k, m+1, r );
    else return bus_bin_rec( V, k, l, m-1 );
}

//Busca Ternária Iterativa
int bus_ter_it( std::vector<long int> &V, long int k, long int l, long int r ){
    int t1, t2;

    while ( l <= r ){
        t1 = ( 2*l + r ) / 3;
        t2 = ( l + 2*r ) / 3;

        if ( V.at( t1 ) == k ) return t1;
        else if ( V.at( t2 ) == k ) return t2;
        else if ( k < V.at( t1 ) ) r = t1-1;
        else if ( k > V.at( t2 ) ) l = t2+1;
        else{
            l = t1+1;
            r = t2-1;
        }

    }

    return -1;
}

//Busca Ternária Recursiva
int bus_ter_rec( std::vector<long int> &V, long int k, long int l, long int r ){
    if ( l > r ) return -1;
    
    int t1 = ( 2*l + r ) / 3;
    int t2 = ( l + 2*r ) / 3;

    if ( V.at( t1 ) == k ) return t1;
    if ( V.at( t2 ) == k ) return t2;
    if ( k < V.at( t1 ) ) return bus_ter_rec( V, k, l, t1-1 );
    if ( k > V.at( t2 ) ) return bus_ter_rec( V, k, t2+1, r );
    
    return bus_ter_rec( V, k, t1+1, t2-1 );
}

//Wrapper para o std::bsearch
int wrap_sys_bsearch( std::vector<long int> &V, long int k, long int l, long int r ){
    long int *p = V.data();                                                             //"Converte" Vector para Array comum
    long int *res = (long int *) std::bsearch(&k, p, r+1, sizeof(V.at(0)), compare);
    if (res){
        return res - p;
    }
    return -1;
}

//Wrapper para o std::search
int wrap_sys_search( std::vector<long int> &V, long int k, long int l, long int r ){
    std::vector<long int>::iterator it;
    long int key[1] = { k };
    it = std::search( V.begin()+l, V.begin()+r+1, key, key+1);
    if (it != V.end())
        return it-V.begin();
    else
        return -1;
}

//Função compare para o std::bsearch
int compare (const void* a, const void* b){
    const long int *A = static_cast< const long int *> ( a );
    const long int *B = static_cast< const long int *> ( b );

    if (*A < *B)        return -1;
    else if (*A == *B)  return 0;
    else                return 1;
}

//Função wrapper universal. Sempre encontra o primeiro elemento
// procurado no vetor e trata a busca pelo terceiro elemento no caso 3.
int wrapper ( std::vector<long int> &V,
             long int key,
             long int l,
             long int r,
             int times,
             int funcType,
             int (*func) ( std::vector<long int>&, long int, long int, long int ) ){

    int res;
    //Se a função é linear
    if( funcType <= 2 ){
        res = -1;
        int i = 0;
        do{
            res = func( V, key, res+1, r );
        }while ( res >= 0 && ++i < times );

        return res;

    //Se a função é logarítmica (necessita ordenação)
    }else{

        //Começa com o vetor inteiro e repete até o primeiro
        //valor ser encontrado.
        int lastRes = 0;
        int range = r;

        do{
            res = lastRes;
            lastRes = func( V, key, 0, range );
            range = lastRes;
        }while( lastRes > -1 && res != lastRes );

        if ( ( res + times -1 <= r ) && ( V[res + times-1] == key ) ){
            return res + times-1;
        }else
            return -1;
    }
    
}

//Preenche o vetor com números aleatórios no range [lower, upper]
void randomFill( std::vector<long int> &V, const int lower, const int upper, const unsigned long int seed) {

    //Usa uma distribuição uniforme para preencher o vetor
    std::default_random_engine eng( seed );
    std::uniform_real_distribution<double> distr( lower, upper );

    for ( auto &elem : V ){
        elem = distr( eng );
    }

}

//Faz as preparações necessárias para o teste de terceiro caso,
// incluindo geração de números aleatórios e ordenação caso necessário.
long int casethree( std::vector<long int> &V,
                const int upper,
                const unsigned long int seed, 
                const int funcType){

    std::default_random_engine eng( seed - upper );

    //Nova chave aleatória
    std::uniform_int_distribution<long int> distr( 0, upper );
    long int key = distr( eng );

    //Posição aleatória para o terceiro elemento
    std::uniform_int_distribution<int> RNG( 2, upper );
    int randomNumber = RNG( eng );
    
    /* Caso o vetor precise ser ordenado, será gerada uma chave dentro do range
    *  comum do vetor, logo os valores poderão estar em qualquer lugar após a ordernação.
    */
    if( funcType > 2 ){
        
        V.at( 0 ) = key;
        V.at( 1 ) = key;
        V.at( randomNumber ) = key;

        std::sort ( V.begin(), V.begin() + upper );

    /* Caso o vetor não precise ser ordenado, será gerada uma chave que não estava antes
    *  no vetor. Como somente o último caso dita o tempo de execução do algoritmo, os
    *  dois primeiros valores do vetor recebem a chave enquanto a terceira posição
    *  é aleatória.
    */
    }else{
        
        key *= -1;

        V.at( 0 ) = key;
        V.at( 1 ) = key;
        V.at( randomNumber ) = key;

    }

    return key;
}