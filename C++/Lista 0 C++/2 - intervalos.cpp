#include <iostream>

using namespace std;

int main()
{
	int input, total(0), inter1(0), inter2(0), inter3(0), inter4(0);
	std::cout << "Entre com valores inteiros (Ctrl+d p/ encerrar): \n";

	while(std::cin >> input)
	{
		if(input < 0 || input > 100){
			std::cout << "Digite um numero entre 0 e 100\n";
			continue;
		}else if(input < 25) inter1++;
		else if(input < 50) inter2++;
		else if(input < 75) inter3++;
		else if(input <= 100) inter4++;
		total++;
		std::cout << "Numero recebido(Ctrl+d p/ encerrar)\n";

	}

	std::cout << (double) inter1/total*100 << "% dos numeros foram entre 0 e 24\n";
	std::cout << (double) inter2/total*100 << "% dos numeros foram 25 e 49\n";
	std::cout << (double) inter3/total*100 << "% dos numeros foram 50 e 74\n";
	std::cout << (double) inter4/total*100 << "% dos numeros foram 75 e 100\n";

	return 0;
}
