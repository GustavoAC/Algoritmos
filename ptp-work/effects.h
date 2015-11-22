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

void ef_blur(Pixel image[lat][lat]){
	int i, j;
	Pixel temp[lat][lat];
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++){
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
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++)
			image[i][j] = temp[i][j];
	
	create_new_file(image);
}

void ef_sharpening(Pixel image[lat][lat]){
	int i, j;
	Pixel temp[lat][lat];
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++){
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
				
	}
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++)
			image[i][j] = temp[i][j];
	create_new_file(image);

}

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

	system("clear");
    printf("O arquivo %s foi criado com sucesso na pasta raíz do programa.\n", name);
}

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

void ef_black_white(Pixel image[lat][lat]){
	int i, j, gray;

	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++){
			gray = (image[i][j].red + image[i][j].green + image[i][j].blue)/3;
			image[i][j].red = gray;
			image[i][j].green = gray;
			image[i][j].blue = gray;
		}
	create_new_file(image);
}

void ef_horizontal_mirror(Pixel image[lat][lat]){
	int i, j;	
	Pixel temp[lat][lat];
	
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			temp[i][width-j-1].red = image[i][j].red;
			temp[i][width-j-1].green = image[i][j].green;
			temp[i][width-j-1].blue = image[i][j].blue;
		}
	}
	
	create_new_file(temp);
}

void ef_border_detection(Pixel image[lat][lat]){
	int i, j;
	Pixel temp[lat][lat];
	
	null_matrix(temp);

	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++){
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

		}
	
	ef_thresholding(temp, 127);
}

void ef_negative(Pixel image[lat][lat], int clrRange){
	int i, j;
	
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			image[i][j].red = clrRange - image[i][j].red;
			image[i][j].green = clrRange - image[i][j].green;
			image[i][j].blue = clrRange - image[i][j].blue; 
		}
	}
	create_new_file(image);
}

void ef_sepia(Pixel image[lat][lat]){
	int i, j;
	
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			image[i][j].red = (image[i][j].red * 0.493) + (image[i][j].green * 0.469) + (image[i][j].blue * 0.089);
			

			image[i][j].green = (image[i][j].red * 0.349) + (image[i][j].green * 0.486) + (image[i][j].blue * 0.168);
			

			image[i][j].blue = (image[i][j].red * 0.272) + (image[i][j].green * 0.334) + (image[i][j].blue * 0.131);
			


		}
	}
	create_new_file(image);
}
