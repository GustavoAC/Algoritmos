#include <iostream>

using namespace std;

int main()
{
	int m(1), n(1), soma(0);
	while(m != 0 && n != 0){
		std::cout << "Insira dois numeros inteiros (0 e 0 para parar)\n";
		std::cin >> m;
		std::cin >> n;

		for (int i = 0; i < n; i++)
		{
			soma += m;
			m++;
		}

		std::cout << "A soma dos " << n << " numeros consecutivos a partir de "
		<< m-n << " eh " << soma << endl;
		soma = 0;
	}

	std::cout << "Fim do programa";
}
