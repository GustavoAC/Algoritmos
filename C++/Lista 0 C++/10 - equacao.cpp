/*
* Programa que acha as raízes de uma função de segundo grau do tipo ax² + bx + c = 0
*/

#include <iostream>
#include <cmath>

using namespace std;

int raizes(float a, float b, float c, float *x1, float *x2){
	float delta = b*b -4*a*c;

	if(delta < 0){
		*x1 = 0;
		*x2 = 0;
		return 0;
	}

	*x1 = (-b - sqrt(delta))/2*a;

	if(delta == 0){
		*x2 = *x1;
		return 1;
	}else{
		*x2 = (-b + sqrt(delta))/2*a;
		if(*x1 > *x2)
			std::swap(*x1, *x2);
		return 2;
	}

}

int main(){
	float a, b, c, x1, x2;
	int numRaz;

	std::cout << "Insira o a, b, e c da funcao de segundo grau.\n";
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	numRaz = raizes(a, b, c, &x1, &x2);

	std::cout << "A equacao tem " << numRaz << " raizes reais (" << x1 << ", " << x2 << ").\n";

}
