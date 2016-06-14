#include <iostream>

using namespace std;

int main()
{
	int input, count(0);
	std::cout << "Digite 5 numeros.\n";
	for(int i = 0; i < 5; i++)
	{
		std::cin >> input;
		if(input < 0) count++;
	}

	std::cout << "Foram digitados " << count << " numeros negativos.\n";
	return 0;
}
