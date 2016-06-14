#include <iostream>
using namespace::std;

/*
void SwapInt( int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void SwapInt( double &x, double &y){
    double temp = x;
    x = y;
    y = temp;
}
*/

template <typename T>
void Swap( T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

int main( ) {
    int x = 5, y = 7;
    double a = 2.3, b = 4.5;

    cout << "Antes da troca:\n";
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;

    Swap( x, y );  // troca inteiros
    Swap( a, b );  // troca números em ponto flutuante

    cout << "Depois da troca:\n";
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;

    return EXIT_SUCCESS;
}
