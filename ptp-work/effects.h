/**
 * @brief effects.h possui todos os filtros que processam a imagem.
 */

/**
 * A função "ef_thresholding"
 * A imagem é binarizada, ficando apenas com duas cores: o branco e o preto*/
void ef_thresholding(Pixel image[lat][lat], int value){
	int i, j, gray;
	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++){
			gray = (image[i][j].red + image[i][j].green + image[i][j].blue)/3;
			if(gray > value){
				image[i][j].red = 1;
				image[i][j].green = 1;
				image[i][j].blue = 1;
			}else{
				image[i][j].red = 0;
				image[i][j].green = 0;
				image[i][j].blue = 0;
			}
		}

    clrRange = 1;
    create_new_file(image);
}

/**
 * A função "ef_blur"
 * Borra a imagem e diminui a percepção dos detalhes */
void ef_blur(Pixel image[lat][lat]){
	int i, j;
	
	Pixel temp[lat][lat]; /* < "Pixel temp" é uma matriz temporária que irão receber a nova imagem, borrada */
	
	/* O laço passeia pela matriz de pixels*/
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++){
				/* A matriz temporária soma os pixel ao imediatamente redor do atual pixel do laço e tira a média deles.*/
				temp[i][j].red = (
					image[i-1][j-1].red + image[i-1][j].red + image[i-1][j+1].red +
					image[i][j-1].red + image[i][j].red + image[i][j+1].red +
					image[i+1][j-1].red + image[i+1][j].red + image[i+1][j+1].red)/9;

				temp[i][j].green = (
					image[i-1][j-1].green + image[i-1][j].green + image[i-1][j+1].green +
					image[i][j-1].green + image[i][j].green + image[i][j+1].green +
					image[i+1][j-1].green + image[i+1][j].green + image[i+1][j+1].green)/9;

				temp[i][j].blue = (
					image[i-1][j-1].blue + image[i-1][j].blue + image[i-1][j+1].blue +
					image[i][j-1].blue + image[i][j].blue + image[i][j+1].blue +
					image[i+1][j-1].blue + image[i+1][j].blue + image[i+1][j+1].blue)/9;

		}
	/* O segundo laço transporta todos os novos valores da matriz temporária novamente para a matriz "image".*/
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++)
			image[i][j] = temp[i][j];
	
	create_new_file(image);
}

/**
 * A função "ef_sharpening"
 * Aumenta a clareza de detalhes e das bordas*/
void ef_sharpening(Pixel image[lat][lat]){
	int i, j;
	
	Pixel temp[lat][lat];/* < Pixel temp é uma matriz temporária, que será usada para receber a imagem com as alterações*/
	
	/* O laço passei pela matriz de pixels.*/
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++){
				/* O pixel "central" é multiplicado por 5, enquanto os pixel imediatamente ao lado e em cima são
				 * multiplicados por -1 e somado ao pixel central.*/
				temp[i][j].red = (image[i][j].red*5 - image[i-1][j].red - image[i][j-1].red - image[i][j+1].red - 
					image[i+1][j].red);
				temp[i][j].red = (temp[i][j].red < 255) ? temp[i][j].red : 255; 
				temp[i][j].red = (temp[i][j].red > 0) ? temp[i][j].red : 0;
				
				temp[i][j].green = (image[i][j].green*5 - image[i-1][j].green - image[i][j-1].green - image[i][j+1].green - 
					image[i+1][j].green);
				temp[i][j].green = (temp[i][j].green < 255) ? temp[i][j].green : 255; 
				temp[i][j].green = (temp[i][j].green > 0) ? temp[i][j].green : 0;
				
				temp[i][j].blue = (image[i][j].blue*5 - image[i-1][j].blue - image[i][j-1].blue - image[i][j+1].blue - 
					image[i+1][j].blue);
				temp[i][j].blue = (temp[i][j].blue < 255) ? temp[i][j].blue : 255; 
				temp[i][j].blue = (temp[i][j].blue > 0) ? temp[i][j].blue : 0;
				
				/* Os operadores ternários verificam se os novos valores são maiores que 255 ou menores que 0.
				 * Caso seja maior que 255, o valor novo será o próprio 255.
				 * Caso seja menor que 0, o valor será o pŕoprio 0.
				 * Isso evita que os valores dos pixels saiam do color ranger e quebrem a imagem */
	}
	/* O segundo laço transporta todos os novos valores da matriz temporária novamente para a matriz "image".*/
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++)
			image[i][j] = temp[i][j];
	create_new_file(image);

}

/**
 * A função "ef_rotate_left"
 * A função rotaciona a imagem para a esquerda em 90 graus*/
void ef_rotate_left(Pixel image[lat][lat]){
	int i, j;
	Pixel temp[lat][lat];

	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			temp[i][j] = image[i][j];
		}
	}
	
	for (i = 0; i < height; i++)
        	for (j = 0; j < width; j++)
           		image[width-j-1][i] = temp[i][j];

	i = height;
	height = width;
	width = i;
	create_new_file(image);
}

/**
 * A função "ef_enlarge"
 * Dado um coeficiente de ampliação, a função amplia a imagem*/
void ef_enlarge(Pixel image[lat][lat], int value){
	int i, j, k, l;
	
	FILE *newfile;
	newfile = fopen(name, "w");
	fprintf(newfile, "%s\n%i %i\n%i\n", filetype, width*value, height*value, clrRange);
	
	for(i = 0; i < height; i++)
		for (k = 0; k < value; k++)
			for(j = 0; j < width; j++)
				for(l = 0; l < value; l++)
					fprintf(newfile, "%i %i %i ", image[i][j].red, image[i][j].green, image[i][j].blue);

	fclose(newfile);
	
	system("clear");
    printf("O arquivo %s foi criado com sucesso na pasta raíz do programa.\n", name);
}

/**
 * A função "ef_reduce"
 * Dado um coeficiente de redução, a função diminui a imagem*/
void ef_reduce(Pixel image[lat][lat], int value){
	int i, j, k, l, lat2 = lat/value;
	Pixel temp[lat2][lat2];
	
	for(i = 0; i < lat2; i++)
		for(j = 0; j < lat2; j++){
			temp[i][j].red = 0;
			temp[i][j].green = 0;
			temp[i][j].blue = 0;
		}

	for(i = 0; i < height; i += value){
		for(j = 0; j < width; j += value){
			for (k = 0; k < value; k++){
				for(l = 0; l < value; l++){
					temp[i/value][j/value].red += image[i+k][j+l].red;
					temp[i/value][j/value].green += image[i+k][j+l].green;
					temp[i/value][j/value].blue += image[i+k][j+l].blue;
				}
			}
			temp[i/value][j/value].red /= value*value;
			temp[i/value][j/value].green /= value*value;
			temp[i/value][j/value].blue /= value*value;
		}
	}
	width /= value;
	height /= value;
	lat /= value;
	
	create_new_file(temp);
}

/**
 * A função "ef_black_white"
 * Deixa a imagem em escala de cinza (preto e branco).*/

void ef_black_white(Pixel image[lat][lat]){
	int i, j, gray;
	
	/* O laço passeia pela matriz de pixels*/
	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++){
			gray = (image[i][j].red + image[i][j].green + image[i][j].blue)/3;	/* < "gray" soma os valores RGB e tira a média deles*/
			/* Os três valores RGB recebem "gray", tornando a imagem cinza*/
			image[i][j].red = gray;
			image[i][j].green = gray;
			image[i][j].blue = gray;
		}
	create_new_file(image);
}

/**
 * A função "ef_horizontal_mirror"
 * Espelha a imagem. */
void ef_horizontal_mirror(Pixel image[lat][lat]){
	int i, j;	
	Pixel temp[lat][lat]; /* < Pixel temp é uma matriz temporária, que será usada para receber a imagem espelhada*/
	/* O laço percorre a matriz de pixels*/
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			/* A matriz "temp" recebe a imagem do atual [i][j] no seu oposto a matriz "image", ou seja, [tamanho - i] e
			 * [tamanho - j]. Como a matriz começa em [0][0], o final da matriz temporária é o [tamanho - 1].*/
			temp[i][width-j-1].red = image[i][j].red;
			temp[i][width-j-1].green = image[i][j].green;
			temp[i][width-j-1].blue = image[i][j].blue;
		}
	}
	
	create_new_file(temp);
}

/**
 * A função "ef_border_detection"
 * Essa função analiza as trocas de luminosidade da imagem e detecta as bordas*/
void ef_border_detection(Pixel image[lat][lat]){
	int i, j;
	Pixel temp[lat][lat]; /* < Pixel temp é uma matriz temporária*/
	
	null_matrix(temp); /* Chama a matriz que zera todos os valores da matriz temporária*/
	
	/* O laço percorre a matriz de pixels*/
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++){
				/* O pixel central é multiplicado por 8 e os imediatamente ao seu lado por -1. 
				 * Ao final, o atual pixel da matriz temporária será a soma do pixel central e 
				 * dos imadiatamente ao seu lado (incluindo diagonais)*/
				temp[i][j].red =
					(image[i][j].red*8) - image[i-1][j-1].red - image[i-1][j].red -
					image[i-1][j+1].red - image[i][j-1].red - image[i][j+1].red -
					image[i+1][j-1].red - image[i+1][j].red - image[i+1][j+1].red;
				temp[i][j].red = (temp[i][j].red < 0) ? 0 : temp[i][j].red;
				temp[i][j].red = (temp[i][j].red > 255) ? 255 : temp[i][j].red;

				temp[i][j].green =
					(image[i][j].green*8) - image[i-1][j-1].green - image[i-1][j].green -
					image[i-1][j+1].green - image[i][j-1].green - image[i][j+1].green -
					image[i+1][j-1].green - image[i+1][j].green - image[i+1][j+1].green;
				temp[i][j].green = (temp[i][j].green < 0) ? 0 : temp[i][j].green;
				temp[i][j].green = (temp[i][j].green > 255) ? 255 : temp[i][j].green;

				temp[i][j].blue =
					(image[i][j].blue*8) - image[i-1][j-1].blue - image[i-1][j].blue -
					image[i-1][j+1].blue - image[i][j-1].blue - image[i][j+1].blue -
					image[i+1][j-1].blue - image[i+1][j].blue - image[i+1][j+1].blue;
				temp[i][j].blue = (temp[i][j].blue < 0) ? 0 : temp[i][j].blue;
				temp[i][j].blue = (temp[i][j].blue > 255) ? 255 : temp[i][j].blue;
				
				/* Os operadores ternários verificam se os novos valores são maiores que 255 ou menores que 0.
				 * Caso seja maior que 255, o valor novo será o próprio 255.
				 * Caso seja menor que 0, o valor será o pŕoprio 0.
				 * Isso evita que os valores dos pixels saiam do color ranger e quebrem a imagem */
		}
	
	ef_thresholding(temp, 127);
}

/**
 * A função "ef_negative"
 * Negativa a imagem, recebendo o color range e subtraindo-o do atual valor do pixel*/
void ef_negative(Pixel image[lat][lat], int clrRange){
	int i, j;
	
	/* O laço percorre a matriz de pixels*/
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			/* Retira o atual valor do pixel do color range*/
			image[i][j].red = clrRange - image[i][j].red;
			image[i][j].green = clrRange - image[i][j].green;
			image[i][j].blue = clrRange - image[i][j].blue; 
		}
	}
	create_new_file(image);
}

/**
 * A função "ef_sepia"
 * Multiplica a matriz de pixel por valores pŕe-determinados para dar um tom marrom, envelhencendo a imagem*/
void ef_sepia(Pixel image[lat][lat]){
	int i, j;
	
	/* O laço passeia pela matriz de pixels*/
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			image[i][j].red = (image[i][j].red * 0.493) + (image[i][j].green * 0.469) + (image[i][j].blue * 0.089);
			

			image[i][j].green = (image[i][j].red * 0.349) + (image[i][j].green * 0.486) + (image[i][j].blue * 0.168);
			

			image[i][j].blue = (image[i][j].red * 0.272) + (image[i][j].green * 0.334) + (image[i][j].blue * 0.131);
			
			/** Os valores são pré determinados, por meio de testes, para deixar a imagem com tons de marrom/amarelo*/

		}
	}
	create_new_file(image);
}
