#include <iostream>
using namespace::std;


template <typename Obj>
int buscaBin( Obj V[],
            Obj &x,
            int low,
            int high,
            int (* comp)( const Obj&, const Obj& ) )
{
    if ( high < low ) // Caso base da recursao
        return -1; // indice invalido, indicando que nao achou.

    // Determinar o elemento no centro do vetor.
    int mid = ( low + high ) / 2;

    cout << " >>> Procurando em [" << low << ", " << high << " ]\n";
    int compR = comp( x, V[ mid ] );
    cout << " >>> Resultado comp: " << compR << endl;
    // Sera que o do meio eh o procurado?
    if ( compR == 0 )
    {   // sucesso
        return mid;
    }
    else if ( compR > 0 ) // Procurar na metade direita.
    {
        cout << " >>> Going right... [" << mid+1 << ", " << high << "]\n";
        return buscaBin( V, x, mid+1, high, comp );
    }
    else // Procurar na metade esquerda.
    {
        cout << " >>> Going left... [" << low << ", " << mid-1 << "]\n";
        return buscaBin( V, x, low, mid-1, comp );
    }
}

template <typename Obj>
void
printArray( Obj V[], int sz )
{
    cout << ">>> [ ";
    for ( int i(0); i < sz; ++i )
        cout << V[ i ] << " ";
    cout << "]\n";
}

template <typename T>
int compara( const T & a, const T & b )
{
    if ( a == b ) return 0;
    else if ( a > b ) return 1;
    else return -1;

    //return (a - b); // legal, mas não é tao versatil quanto a de cima.
}

int main( )
{
    // Vetor de inteiros
    int V[] = { 2, 4, 6, 8, 10, 12, 14 };
    int x = 14; // Elemento a ser procurado.
    char V2[] = { 'a', 'c', 'e', 'g', 'h', 'j', 'k'};
    char x2 = 'c'; // Elemento a ser procurado.
    string V3[] = { "aquamen", "batman", "capitão", "demolidor", "falcão", "hulk", "thor" };
    string x3 = "hulk"; // Elemento a ser procurado.
    // Tamanho dos vetores
    int sz = 7;

    cout << ">>> Vetor original: \n";
    printArray( V, sz );

    cout << ">>> Procurar pelo elemento: " << x << endl;
    cout << ">>> Resultado da busca: \n" << buscaBin( V, x, 0, sz-1, compara ) << endl;

#ifdef WORK_ONLY_WITH_TEMPLATE
    cout << ">>> Vetor original: \n";
    printArray( V2, sz );
    cout << ">>> Procurar pelo elemento: " << x2 << endl;
    cout << ">>> Resultado da busca: \n" << buscaBin( V2, x2, 0, sz-1, compara ) << endl;

    cout << ">>> Vetor original: \n";
    printArray( V3, sz );
    cout << ">>> Procurar pelo elemento: " << x3 << endl;
    cout << ">>> Resultado da busca: \n" << buscaBin( V3, x3, 0, sz-1, compara ) << endl;
#endif

    return EXIT_SUCCESS;
}




