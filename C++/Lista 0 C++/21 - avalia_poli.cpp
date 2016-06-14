#include <iostream>
#include <cmath>

using namespace std;

void avalia(float c1, float x1, float c2, float x2, float c3, float x3, float c4, float x4, float in){
	float resul;
	resul = (c1*pow(in,x1)) + (c2*pow(in,x2)) + (c3*pow(in,x3)) + (c4*pow(in,x4));

	std::cout << "f(x) =";
	if(c1 != 0){
		std::cout << " " << c1;
		if(x1 == 1)
			std::cout << "x";
		else if(x1 > 1)
			std::cout << "x^" << x1;
	}
	if(c2 != 0){
		if(c2 > 0)
			std::cout << " +";
		std::cout << " " << c2;
		if(x2 == 1)
			std::cout << "x";
		else if(x2 > 1)
			std::cout << "x^" << x2;
	}
	if(c3 != 0){
        if(c3 > 0)
            std::cout << " +";
		std::cout << " " << c3;
		if(x3 == 1)
			std::cout << "x";
		else if(x3 > 1)
			std::cout << "x^" << x3;
	}
	if(c4 != 0){
		if(c4 > 0)
			std::cout << " +";
		std::cout << " " << c4;
		if(x4 == 1)
			std::cout << "x";
		else if(x4 > 1)
			std::cout << "x^" << x4;
	}

	std::cout << ", f(" << in << ") = " << resul << endl;

}

int main(){
	float c1, x1, c2, x2, c3, x3, c4, x4, in;
	std::cout << "Digite 4 pares de coeficiente e potencia de X, e por ultimo o valor a ser encontrado\n";
	std::cin >> c1 >> x1 >> c2 >> x2 >> c3 >> x3 >> c4 >> x4 >> in;

	avalia(c1, x1, c2, x2, c3, x3, c4, x4, in);
	return 0;
}
