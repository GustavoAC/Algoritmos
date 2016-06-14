#include <iostream>
using namespace::std;

template <typename Obj>
Obj myMax( Obj a, Obj b ) {
    return (a > b ? a : b);
}

int main( ) {
    int x = 5, y = 7;
    double a = 2.3, b = 4.5;
    char r = 'a', s = 'z';

    cout << "(x,y) = (" << x << "," << y << ")\n";
    cout << "(a,b) = (" << a << "," << b << ")\n";
    cout << "(s,r) = (" << s << "," << r << ")\n";

    cout << ">>> Max (x,y) = " << myMax( x, y ) << endl;
    cout << ">>> Max (a,b) = " << myMax( a, b ) << endl;
    cout << ">>> Max (s,r) = " << myMax( s, r ) << endl;


    return EXIT_SUCCESS;
}
