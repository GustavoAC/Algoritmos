#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bib/global.h"
#include "bib/functions.h"
#include "bib/effects.h"

int main(){
	FILE *imagepath;
	intro();

	scanf("%s", name);
	strcpy(nameFile, name);
	strcat(nameFile, ".ppm");
	imagepath = fopen(nameFile, "r");

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

	fgets(filetype, 3, imagepath);
	fscanf(imagepath, "%i %i %i", &width, &height, &clrRange);
	if(height > width) lat = height;
	else lat = width;
	Pixel image[lat][lat];
	read_image(image, imagepath);
    
	choose_options(image);

	return 0;
}
