#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.

using namespace std;

int main()
{
    std::ifstream inputFile;    // Stream object to handle the input file.
    std::string dataLine;       // String corresponding to the current input line
    int vet[20];                // Array that stores the 20 numbers read from file.
    int vetSize(0);             // The array's current size.

    // Open the input file and assign it to the stream.
    inputFile.open( "data.in" );
    // Process all the data from the input file.
    if ( inputFile.is_open() )
    {
        std::cout << ">>> Array BEFORE processing...\n >>> [ ";
        // Read all data from input file until the limit of the array.
        while ( std::getline( inputFile, dataLine ) && vetSize < 20 )
        {
            // Using a stringstream to extract an integer from the string into our array.
            std::stringstream( dataLine ) >> vet[ vetSize++ ]; // Remeber to increase the count variable.

            // Print just to keep track of what's going on.
            std::cout << vet[ vetSize-1 ] << " ";
        }
        inputFile.close(); // Close the file stream, no more data to read.
        std::cout << "]\n\n";
    }

    for (int i = 0; i < 10; i++)
    {
        std::swap(vet[i], vet[19-i]);
    }

    for (int i = 0; i < 20; i++)
    {
        cout << vet[i] << endl;
    }
}

