#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int fib(int a){
	if(a <= 1) return a;
	else return fib(a-1) + fib(a-2);
}

void NesimoFib(int n){
	for (int i = 1; i <= n; ++i)
		std::cout << fib(i) << " ";
	std::cout << endl;
}

void FibMenorL(int L){
	for (int i = 1; fib(i) < L; ++i)
		std::cout << fib(i) << " ";
	std::cout << endl;

}

void PiramideFib(int h){
	int colunas = h;
	int linhas = 2*h;

	for (int i = 1; i < linhas; i++){
		for (int j = 0; j < abs(colunas - i); j++)
			std::cout << "   ";
		for (int k = colunas - abs(colunas - i); k > 0; k--){
			std::cout << setw(3) << fib(k);
		}
		cout << endl;
	}

}

int main()
{
    int a;
    std::cout << "Teste de void NesimoFib:";
    std::cin >> a;
    NesimoFib(a);

    std::cout << "Teste de void FibMenorL:";
    std::cin >> a;
    FibMenorL(a);

    std::cout << "Teste de void PiramideFib:";
    std::cin >> a;
    PiramideFib(a);
}
