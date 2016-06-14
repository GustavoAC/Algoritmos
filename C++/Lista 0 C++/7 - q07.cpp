/**
 *  This program provides a solution to the question 07 from the warming up list of exercise.
 *  This solution is based on reading input data from a file, rather than asking from the terminal.
 *
 *  @author Selan R. dos Santos
 *
 *  To compile: g++ -Wall -std=c++11 q07.cpp -o q07
 */

#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.

using namespace std;

int main()
{
    std::ifstream inputFile;    // Stream object to handle the input file.
    std::string dataLine;       // String corresponding to the current input line
    int B[20];                  // Array that stores the 20 numbers read from file.
    auto BSize(0);              // The array's current size.

    // Open the input file and assign it to the stream.
    inputFile.open( "data.in" );
    // Process all the data from the input file.
    if ( inputFile.is_open() )
    {
        std::cout << ">>> Array BEFORE processing...\n >>> [ ";
        // Read all data from input file until the limit of the array.
        while ( std::getline( inputFile, dataLine ) && BSize < 20 )
        {
            // Using a stringstream to extract an integer from the string into our array.
            std::stringstream( dataLine ) >> B[ BSize++ ]; // Remeber to increase the count variable.

            // Print just to keep track of what's going on.
            std::cout << B[ BSize-1 ] << " ";
        }
        inputFile.close(); // Close the file stream, no more data to read.
        std::cout << "]\n\n";

        // Now, run through the array swapping itens between adjacent odd/even position.
        auto i( 1 );
        while ( i < BSize ) // Notice that we go until the array's size, which may be less than 20.
        {
            // Swap numbers at even-odd location within the array. 
            std::swap( B[ i-1 ], B[ i ] );
            // Skip 2, to process the next pair of itens.
            i+=2;
        }

        // Printing out the final result on the screen.
        std::cout << ">>> Array AFTER processing...\n >>> [ ";
        for (i=0 ; i < BSize ; ++i )
            std::cout << B[i] << " ";
        std::cout << "]\n\n";
    }

    std::cout <<  "\n>>> Normal exiting...\n\n";
    return EXIT_SUCCESS;
}

