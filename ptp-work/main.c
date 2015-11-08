#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "functions.h"

int main(){
	FILE *imagepath;
	header();

	scanf("%s", nome);
	strcpy(nomeArq, nome);
	strcat(nomeArq, ".ppm");
	imagepath = fopen(nomeArq, "r");

	if(imagepath == NULL){
		system("clear");
		printf("Esse arquivo não foi encontrado.\n");
		exit(1);
	}

	fgets(filetype, 3, imagepath);
	fscanf(imagepath, "%i %i %i", &height, &width, &clrRange);
	Pixel image[height][width];
	read_image(image, imagepath);
    
	choose_options(image);

	create_new_file(image);

	return 0;
}
