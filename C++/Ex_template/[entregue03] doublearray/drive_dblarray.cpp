#include <iostream>    
using std::cout; 
using std::cin; 
using std::cerr; 
using std::endl; 

#include <vector>
using std::vector;

#include <new>
using std::bad_alloc;

#include <cassert> 

#include "doublearray.h"

// Read an arbitrary number of items, sort and print them.
int main( )
{
    int x;                   // An item to read
    int nReadElements = 0;
    int *vpiArray;       // The array
    int viArrLen = 5;

    try { 
      vpiArray = new int [ viArrLen ];
    }
    catch ( bad_alloc exception ) {
      cerr << "\n[main()]:Error during allocation of original array!\n";
      assert ( false );
    }
    
    cout << ">>> Enter items: " << endl;
    while( cin >> x ) {
      
      if ( ++nReadElements >= viArrLen ) {
	cout << ">>> Doubling array size from " << viArrLen << " to ";
	DoubleArray ( vpiArray, viArrLen );
	cout << ">>> New size is: " << viArrLen << endl;
      }
      vpiArray[ nReadElements - 1 ] = x;
    }
    
    
    cout << ">>> Items are: [";
    for( auto i( 0 ) ; i < nReadElements ; ++i )
    {
      cout << vpiArray[ i ] << " ";
    }
    cout << "]\n";
    
   
    delete [] vpiArray;
    return 0;
}


/* ------------------- [ End of the StackAr.cpp source ] ------------------- */
/* ========================================================================= */
