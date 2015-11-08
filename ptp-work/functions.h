/* TODO:
* Função pra pular os comentários na leitura do arquivo
* Restante das funções necessárias
* Funções de espelhamento para extras
* (Talvez) Superblur
* Comentar código
* jpg para ppm e vice-versa
* RLE
*/



void header(){
	system("clear");
	printf("Bem vindo ao programa!\n");
	printf("Dígite o nome do seu arquivo (sem extensão)");
	printf("\t(Exemplo: lena)\n");
}

void read_image(Pixel image[height][width], FILE *imagepath){
	int i, j;

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

void ef_black_white(Pixel image[height][width]){
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

void ef_thresholding(Pixel image[height][width]){
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
void ef_blur(Pixel image[height][width]){
	int i, j, l;
	strcat(nome, "_blu2.ppm");
	for(i = 1; i < height-1; i++)
		for(j = 1; j < width; j++){
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

void create_new_file(Pixel image[height][width]){
	int i, j;
	FILE *newfile;
	newfile = fopen(nome, "w");
	fprintf(newfile, "%s\n%i %i\n%i\n", filetype, height, width, clrRange);
	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++)
        		fprintf(newfile, "%i %i %i ", image[i][j].red, image[i][j].green, image[i][j].blue);

    system("clear");
    printf("O arquivo %s foi criado com sucesso na pasta raíz do programa.\n", nome);
}


void choose_options(Pixel image[height][width]){
	int escolha;

	printf("== Pressione a opção desejada ==\n");
	printf("1- thr // Thresholding\n");
	printf("2- bw  // Black & White\n");
	printf("3- blu // Blurring\n");
	printf("================================\n");

	scanf("%i", &escolha);
	controller(escolha, image);
}

void controller(int opcao, Pixel image[height][width]){
	if(opcao == STR)
		ef_thresholding(image);
	else if(opcao == BW)
		ef_black_white(image);
	else if(opcao == BLU)
		ef_blur(image);
	else{
		system("clear");
		printf("Opção inválida, tente novamente.\n\n");

		print_options(image);

	}
}


