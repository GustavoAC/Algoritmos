#include <stdio.h>
#include <string.h>

/*
&TODO:
- Evitar erros com nomes de arquivo muito grandes
- Melhorar leitura da primeira linha do arquivo
- Separar em funções e bibliotecas diferentes
- Convencionar o uso das funções (seguir padrões de projeto ao invés de usar Ex: fgets E fscanf)
- Separar em funções urgentemente
*/

typedef struct{
	int red;
	int green;
	int blue;
} Pixel;


int main(){

	FILE *imagepath;
	int height, width, i, j, clrRange;
	char filetype[3], nome[50];
	scanf("%s", nome);
	strcat(nome, ".ppm");

	imagepath = fopen(nome, "r");

	if(imagepath == NULL){
        printf("Nem abriu");
        return 0;
	}

	fgets(filetype, 3, imagepath);
	fscanf(imagepath, "%i %i %i", &height, &width, &clrRange);
	Pixel image[height][width];

    if(filetype[0] == 'P' && filetype[1] == '3')
        for(i = 0; i < height; i++)
            for(j = 0; j < height; j++)
                fscanf(imagepath, "%i %i %i", &image[i][j].red, &image[i][j].green, &image[i][j].blue);
/* Tire os comentários para imprimir a matriz
    for(i = 0; i < height; i++)
        for(j = 0; j < height; j++)
            printf("%i %i %i\n", image[i][j].red, image[i][j].green, image[i][j].blue);
*/
	fclose(imagepath);
	return 0;
}
