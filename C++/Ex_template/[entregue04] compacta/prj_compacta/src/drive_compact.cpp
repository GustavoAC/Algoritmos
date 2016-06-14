#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>
#include <functional>
#include <limits>

#include "compact.h"

//
// Constant expressions.
//
constexpr auto N_DEFAULT( 20u );        // Default number of elements.
constexpr auto N_MAX( 100u );   // Max number of elements in the array.


//
// Function prototypes.
//
void randomFill( std::vector<int> &, const int, const int, const unsigned int );


// *** AQUI EH O CLIENTE!!!
bool predicateNegatives( int _a )
{
    return ( _a < 0 );
}

bool predicateLess50 ( int _a )
{
    return ( _a < 50 );
}

//#ifdef WORK_ONLY_WITH_TEMPLATES
bool vingadores ( const std::string &_hero )
{
    std::vector< std::string > avengers = { "capitão américa", "falcão", "hulk", "thor", "homem de ferro", "visão", "viúva negra" };

    auto result = std::find( avengers.begin(), avengers.end(), _hero );

    return ( result != avengers.end( ) );
}
//#endif

// *************


//
// Main program.
//
int main( int argc, char * argv[] )
{
    auto arrSz( N_DEFAULT ); // Initialize vector size.

    // Process any command line arguments.
    if ( argc > 1 ) // In case the user has provided a value for us.
    {
        std::stringstream( argv[1] ) >> arrSz;
    }

    // Do we have a valid array size so far?
    if ( arrSz <= 0  || arrSz > N_MAX )
    {
        std::cout << "\n\n>>> Invalid argument provided!\n"
                  << "    Correct sintax: " << argv[0] << " [N > 0 and N <= " << N_MAX << "]\n"
                  << "    Assuming N = " << N_DEFAULT << " for this run.\n";
        arrSz = N_DEFAULT; // Back to the default value.
    }

    std::cout << "\n\n>>> Required array size is: " << arrSz << "\n\n";

    // Store the data.
    std::vector< int > V( arrSz );

    // Seed with a real random value, if available.
    std::random_device r;
    // Fill it up with random integers.
    randomFill( V, -100, 100, r() );
       
    // Printing out the array, just to make sure we've got random integers.
    std::cout << ">>> ORIGINAL Vet = [ ";
    std::for_each(V.begin(), V.end(), [](const int &i){ std::cout << i << ' '; });
    std::cout << "], Size = " << arrSz << "\n\n";

    //================================================================================
    std::cout << ">>> Compacting now...\n\n";
    compact( V, predicateLess50 );
    //compact( V, predicateNegatives);
    //================================================================================
        
    // Printing compacted array.
    std::cout << ">>> COMPACTED Vet = [ ";
    for( const auto &e : V ) std::cout << e << " ";
    std::cout << "], Size = " << V.size() << "\n\n";


//#ifdef WORK_ONLY_WITH_TEMPLATES
    //===============================================================================
    //
    // Second type of array.
    //
    //===============================================================================
    std::vector< std::string > V2 = { "aquamen", "batman", 
        "capitão américa", "demolidor", "falcão", "hulk", "thor", "deadpool" };

    std::cout << ">>> ORIGINAL Vet = [ ";
    for( const auto &e : V2 ) std::cout << "'" << e << "' ";
    std::cout << "], Size = " << V2.size() << "\n\n";

    //--------------------------------------------------------------------------------
    std::cout << ">>> Compacting now...\n\n";
    compact( V2, vingadores );
    //--------------------------------------------------------------------------------

    std::cout << ">>> COMPACTED Vet = [ ";
    for( const auto &e : V2 ) std::cout << "'" << e << "' ";
    std::cout << "], Size = " << V2.size() << "\n\n";
//#endif

    return EXIT_SUCCESS;
}



//Fill a vector with random numbers in the range [lower, upper]
void randomFill( std::vector<int> &V, const int lower, const int upper, const unsigned int seed)
{

    //use the default random engine and an uniform distribution
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(lower, upper);

    // Fill up vector
    for( auto &elem : V)
        elem = distr(eng);
}
