/**
* \file main.c
* \author Gustavo Araujo Carvalho
* \author Yuri Alessandro D. T. Martins
* \brief Ponto de inicio do programa. Lê a imagem, verifica sua existência e chama as outras funções.
*/

#include <stdio.h>				
#include <string.h>
#include <stdlib.h>
#include "bib/global.h"
#include "bib/functions.h"
#include "bib/effects.h"

/**
 * Função principal do programa:\n
 * Executa passos importantes para a leitura do arquivo e chama as funções que irão tratá-lo.*/
int main(){
	FILE *imagepath;
	
	/* Chama a função que dá as boas-vindas ao usuário.*/
	intro();

	/* Abre o arquivo com nome digitado pelo usuário.*/
	scanf("%s", name);
	strcpy(nameFile, name);
	strcat(nameFile, ".ppm");
	imagepath = fopen(nameFile, "r");

	/* Caso falhe, verifica se o arquivo está compactado. Se falhar novamente, exibe uma mensagem
	 * indicando que o arquivo não foi encontrado.*/
	if(imagepath == NULL){
		strcpy(nameFile, name);
		strcat(nameFile, ".ppmc");
		imagepath = fopen(nameFile, "r");
			if(imagepath != NULL){
				decompress_img(imagepath);
			}else{
				system("clear");
				printf("Esse arquivo não foi encontrado.\n");
				exit(1);
			}
	}

	/* Lê os valores que definem a matriz: Tipo de arquivo, largura, altura e color range.*/
	fgets(filetype, 3, imagepath);
	fscanf(imagepath, "%i %i %i", &width, &height, &clrRange);
	if(height > width) lat = height;
	else lat = width;
	
	/* Declara a matriz de pixels.*/
	Pixel image[lat][lat];
	
	/* Lê os valores do arquivo e os põe na matriz de pixels.*/
	read_image(image, imagepath);
    
    /* Exibe as opções do programa ao usuário.*/
	choose_options(image);

	return 0;
}
