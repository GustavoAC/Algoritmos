#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.

using namespace std;

void PrintReset(int vet[], int *tam, char name){
    std::cout << "Vetor " << name << ":\n[ ";
    for (int i = 0; i < *tam; ++i)
        std::cout << vet[i] << ' ';
    std::cout << "]\n";
    *tam = 0;
}

int main()
{
    std::ifstream inputFile;
    std::string dataLine;
    int A[5], B[5];
    int ASize(0), BSize(0), total(0), temp;

    // Open the input file and assign it to the stream.
    inputFile.open( "data.in" );
    // Process all the data from the input file.
    if ( inputFile.is_open() )
    {
        // Read all data from input file until the limit of the array.
        while ( std::getline( inputFile, dataLine ) && total++ < 30 )
        {
            // Using a stringstream to extract an integer from the string into our array.
            std::stringstream( dataLine ) >> temp; // Remeber to increase the count variable.
            if(temp%2 == 0)
                B[BSize++] = temp;
            else
                A[ASize++] = temp;

            if(ASize == 5)
                PrintReset(A, &ASize, 'A');
            if(BSize == 5)
                PrintReset(B, &BSize, 'B');

        }
        inputFile.close(); // Close the file stream, no more data to read.

        std::cout << "\nFim dos numeros, o resto final dos vetores é:\n";
        PrintReset(A, &ASize, 'A');
        PrintReset(B, &BSize, 'B');
    }
}
