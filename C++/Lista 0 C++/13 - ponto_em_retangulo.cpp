/*
* Programa que acha as raízes de uma função de segundo grau do tipo ax² + bx + c = 0
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float px, py, x1, y1, x2, y2;
	bool limX, limY, denX, denY;

	std::cout << "Insira o x e y do primeiro ponto.\n";
	std::cin >> x1;
	std::cin >> y1;

	std::cout << "Insira o x e y do segundo ponto.\n";
	std::cin >> x2;
	std::cin >> y2;

	std::cout << "Insira o x e y do ponto a ser testado.\n";
	std::cin >> px;
	std::cin >> py;

	if(x1 == x2 && y1 == y2){
		std::cout << "Os dois pontos nao constituem um retangulo valido.\nEncerrando o programa...\n";
		return 0;
	}

	if(x1 > x2)
		std::swap(x1, x2);
	if(y1 > y2)
		std::swap(y1, y2);

	limX = ((px == x1) || (px == x2));
	limY = ((py == y1) || (py == y2));
	denX = ((px > x1) && (px < x2));
	denY = ((py > y1) && (py < y2));

	if(denX && denY)
		std::cout << "O ponto esta dentro do retangulo.\n";
	else if((limX && denY) || (limY && denX) || (limX && limY))
		std::cout << "O ponto esta na borda do retangulo.\n";
	else
		std::cout << "O ponto esta fora do retangulo.\n";

}
