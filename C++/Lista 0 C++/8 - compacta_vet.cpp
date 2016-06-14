#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.

using namespace std;

void limpar_pos(int vet[], int i, int vetSize){
    for (int j = i; j < vetSize; j++)
    {
        vet[j] = vet[j+1];
    }
}

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

    if(vet[vetSize-1] <= 0) vetSize--;

    for(int i = 0; i < vetSize-1; )
    {
        if(vet[i] <= 0)
            limpar_pos(vet, i, --vetSize);
        else
            i++;
    }

    for (int i = 0; i < vetSize; i++)
    {
        cout << vet[i] << endl;
    }

}

