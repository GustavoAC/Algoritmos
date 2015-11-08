/* TODO:
* Colocar o controle de todos os giros numa opção só
* Função pra pular os comentários na leitura do arquivo
* Restante das funções necessárias
* Funções de espelhamento para extras
* (Talvez) Superblur
* Comentar código
* jpg para ppm e vice-versa
* RLE
* Color wheels
* Consertar ROTR
*/



void header(){
	system("clear");
	printf("Bem vindo ao programa!\n");
	printf("Dígite o nome do seu arquivo (sem extensão)");
	printf("\t(Exemplo: lena)\n");
}

void read_image(Pixel image[lat][lat], FILE *imagepath){
	int i, j;
	
	null_matrix(image);
	if(filetype[0] == 'P' && filetype[1] == '3')
        for(i = 0; i < height; i++)
        	for(j = 0; j < width; j++)
        		fscanf(imagepath, "%i %i %i", &image[i][j].red, &image[i][j].green, &image[i][j].blue);
    else {
    	system("clear");
    	printf("O tipo de arquivo PPM não é P3!\n");
    	exit(1);
    }

    fclose(imagepath);

}

void ef_black_white(Pixel image[lat][lat]){
	int i, j, gray;
	strcat(nome, "_bw.ppm");

	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++){
			gray = (image[i][j].blue + image[i][j].green + image[i][j].red)/3;
			image[i][j].blue = gray;
			image[i][j].red = gray;
			image[i][j].green = gray;
		}
}

void ef_thresholding(Pixel image[lat][lat]){
	int i, j, gray;
	strcat(nome, "_thr.ppm");
	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++){
			gray = (image[i][j].blue + image[i][j].green + image[i][j].red)/3;
			if(gray > clrRange/2){
				image[i][j].blue = 1;
				image[i][j].green = 1;
				image[i][j].red = 1;
			}else{
				image[i][j].blue = 0;
				image[i][j].green = 0;
				image[i][j].red = 0;
			}
		}

    clrRange = 1;
}


//Testar com matriz separada da original.
//Não funciona com imagens retangulares
void ef_blur(Pixel image[lat][lat]){
	int i, j;
	strcat(nome, "_blu.ppm");
	for(i = 1; i < lat-1; i++)
		for(j = 1; j < lat-1; j++){
				image[i][j].blue += image[i-1][j-1].blue + image[i-1][j].blue +
					image[i-1][j+1].blue + image[i][j-1].blue + image[i][j+1].blue +
					image[i+1][j-1].blue + image[i+1][j].blue + image[i+1][j+1].blue;
				image[i][j].blue /= 9;

				image[i][j].green += image[i-1][j-1].green + image[i-1][j].green +
					image[i-1][j+1].green + image[i][j-1].green + image[i][j+1].green +
					image[i+1][j-1].green + image[i+1][j].green + image[i+1][j+1].green;
				image[i][j].green /= 9;

				image[i][j].red += image[i-1][j-1].red + image[i-1][j].red +
					image[i-1][j+1].red + image[i][j-1].red + image[i][j+1].red +
					image[i+1][j-1].red + image[i+1][j].red + image[i+1][j+1].red;
				image[i][j].red /= 9;
		}

}
//Bugado
void ef_rotate_right(Pixel image[lat][lat]){
	int i, j, k;	
	Pixel temp[lat][lat];
	strcat(nome, "_rotl.ppm");

	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++)
			temp[i][j] = image[i][j];
	
	for (i = 0; i < height; i++)
        	for (j = 0; j < width; j++)
           		 image[j][width-i-1] = temp[i][j];

	k = height;
	height = width;
	width = k;
}

//FUNCIONA!!!
void ef_rotate_left(Pixel image[lat][lat]){
	int i, j, k;	
	Pixel temp[lat][lat];
	strcat(nome, "_rotl.ppm");

	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			temp[i][j] = image[i][j];
		}
	}
	
	for (i = 0; i < height; i++)
        	for (j = 0; j < width; j++)
           		 image[width-j-1][i] = temp[i][j];

	k = height;
	height = width;
	width = k;
}

// Função espelhar?
// Descoberto acidentalmente, tem que checar se usa height ou width
// Quebra em imagens retangulares
void ef_mirror_horizontal(Pixel image[lat][lat]){
	int i, j;	
	Pixel temp[lat][lat];
	strcat(nome, "_mir.ppm");
	
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			temp[i][width-j].red = image[i][j].red;
			temp[i][width-j].green = image[i][j].green;
			temp[i][width-j].blue = image[i][j].blue;
		}
	}
	
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			image[i][j] = temp[i][j];
		}
	}
}


void create_new_file(Pixel image[lat][lat]){
	int i, j;
	FILE *newfile;
	newfile = fopen(nome, "w");
	fprintf(newfile, "%s\n%i %i\n%i\n", filetype, width, height, clrRange);
	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++)
        		fprintf(newfile, "%i %i %i ", image[i][j].red, image[i][j].green, image[i][j].blue);

    system("clear");
    printf("O arquivo %s foi criado com sucesso na pasta raíz do programa.\n", nome);
}

void null_matrix(Pixel image[lat][lat]){
	int i, j;
	for(i = 0; i < lat; i++)
		for(j = 0; j < lat; j++){
			image[i][j].blue = 0;
			image[i][j].red = 0;
			image[i][j].green = 0;
		}
}

void choose_options(Pixel image[lat][lat]){
	int escolha;

	printf("== Pressione a opção desejada ==\n");
	printf("1 - thr // Thresholding\n");
	printf("2 - bw  // Black & White\n");
	printf("3 - blu // Blurring\n");
	printf("4 - RotR// Rotate Right (Broken)\n");
	printf("5 - RotL// Rotate Left\n");
	printf("6 - Mir // Mirror\n");
	printf("================================\n");

	scanf("%i", &escolha);
	controller(escolha, image);
}

void controller(int opcao, Pixel image[lat][lat]){
	if(opcao == STR)
		ef_thresholding(image);
	else if(opcao == BW)
		ef_black_white(image);
	else if(opcao == BLU)
		ef_blur(image);
	else if(opcao == ROTR)
		ef_rotate_right(image);
	else if(opcao == ROTL)
		ef_rotate_left(image);
	else if(opcao == MIR)
		ef_mirror_horizontal(image);
	else{
		system("clear");
		printf("Opção inválida, tente novamente.\n\n");

		choose_options(image);

	}
}


