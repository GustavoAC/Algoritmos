/**
 * \file functions.h
 * \brief Funções gerais para manipulação da imagem.
 */

/**
 * A função "intro".\n
 * Imprime as boas-vindas do programa ao usuário.
 */
void intro(){
	system("clear");
	printf("Bem vindo ao programa!\n");
	printf("Dígite o nome do seu arquivo (sem extensão)");
	printf("\t(Exemplo: lena)\n");
}

/**
 * A função "read_image".\n
 * Lê os valores de um arquivo e os transporta para uma matriz de pixels.\n
 * A função recebe a matriz de pixels "image" de tamanho "lat" e um tipo FILE "imagepath".
 */
void read_image(Pixel image[lat][lat], FILE *imagepath){
	int i, j;

	/* Zera os valores da matriz.*/
	null_matrix(image);

	/* Os laços percorrem a matriz de pixels atribuindo a cada espaço os valores lidos do arquivo.
	 * A execução é pausada caso o arquivo não seja do tipo P3.*/
	if(filetype[0] == 'P' && filetype[1] == '3')
        for(i = 0; i < height; i++)
        	for(j = 0; j < width; j++)
        		fscanf(imagepath, "%i %i %i", &image[i][j].red, &image[i][j].green, &image[i][j].blue);
    else {
    	system("clear");
    	printf("O tipo de arquivo PPM não é P3!\n");
    	exit(1);
    }

    /* A conexão com o arquivo é encerrada.*/
    fclose(imagepath);

}

/**
 * A função "create_new_file".\n
 * Escreve os valores da matriz de pixels num novo arquivo.\n
 * A função recebe a matriz de pixels "image" de tamanho "lat".
 */
void create_new_file(Pixel image[lat][lat]){
	int i, j;

	/* Cria um novo arquivo e escreve as informações básicas da imagem nele.*/
	FILE *newfile;
	newfile = fopen(name, "w");
	fprintf(newfile, "%s\n%i %i\n%i\n", filetype, width, height, clrRange);

	/* Percorre a matriz de pixels escrevendo os valores da mesma no arquivo.*/
	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++)
        		fprintf(newfile, "%i %i %i ", image[i][j].red, image[i][j].green, image[i][j].blue);

    system("clear");
    printf("O arquivo %s foi criado com sucesso na pasta raíz do programa.\n", name);
}

/**
 * A função "null_matrix".\n
 * Zera o valor de todos os pixels da matriz inserida.\n
 * A função recebe a matriz de pixels "image" de tamanho "lat".
 */
void null_matrix(Pixel image[lat][lat]){
	int i, j;
	for(i = 0; i < lat; i++)
		for(j = 0; j < lat; j++){
			image[i][j].blue = 0;
			image[i][j].red = 0;
			image[i][j].green = 0;
		}
}

/**
 * A função "rotation_controller".\n
 * Recebe do usuário o ângulo de rotação e executa as funções necessárias para girar a imagem da maneira desejada.\n
 * A função recebe a matriz de pixels "image" de tamanho "lat".
 */
void rotation_controller(Pixel image[lat][lat]){
	int ang;
	printf("Digite o angulo de rotação (em sentido horario):\n");
	scanf("%i", &ang);
	switch (ang){
		case 90:
			strcat(name, "_rot_90.ppm");
			ef_rotate_left(image);
			ef_rotate_left(image);
			ef_rotate_left(image);
			break;
		case 180:
			strcat(name, "_rot_180.ppm");
			ef_rotate_left(image);
			ef_rotate_left(image);
			break;
		case 270:
			strcat(name, "_rot_270.ppm");
			ef_rotate_left(image);
			break;
		default:
			system("clear");
			printf("Escolha um angulo reto: 90 - 180 - 270 \n");
			rotation_controller(image);			
	}
}

/**
 * A função "choose_options".\n
 * Mostra ao usuário as funções do programa.\n
 * A função recebe a matriz de pixels "image" de tamanho "lat".
 */
void choose_options(Pixel image[lat][lat]){
	int choice;
	
	printf("\n======== Escolha uma opção =======\n");
	printf("1 - thr     //    Thresholding   *\n");
	printf("2 - blur    //    Blurring       *\n");
	printf("3 - sha     //    Sharpening     *\n");
	printf("4 - rot     //    Rotacionar     *\n");
	printf("5 - amp     //    Ampliar        *\n");
	printf("6 - red     //    Reduzir        *\n");
	printf("==================================\n");

	printf("============= Extras =============\n");
	printf("10 - bw     //    Preto e Branco *\n");
	printf("11 - Mir    //    Espelhar       *\n");
	printf("12 - borda  //    Detecta Bordas *\n");
	printf("13 - inv    //    Negativo       *\n");
	printf("14 - sep    //    Tom de sepia   *\n");
	printf("15 - comp   //    Compressão RLE *\n");
	printf("==================================\n\n");

	printf("[0 - Exit]\n");


	scanf("%i", &choice);
	controller(choice, image);
}

/**
 * A função "controller".\n
 * Realiza os procedimentos necessários para executar o comando do usuário.\n
 * A função recebe a matriz de pixels "image" de tamanho "lat", e a variável "choice" com a escolha do usuário.
 */
void controller(int choice, Pixel image[lat][lat]){
	int value;

	/* De acordo com a escolha do usuário, o programa muda o nome do arquivo e executa a função respectiva.*/
	switch(choice){
		case THR:
			printf("Insira o padrão de binarização entre 0 e 255 (Padrão = 127)\n");
			scanf("%i", &value);
			sprintf(nameFile, "_thr_%i.ppm", value);
			strcat(name, nameFile);
			ef_thresholding(image, value);
			break;

		case BLU:
			strcat(name, "_blur.ppm");
			ef_blur(image);
			break;

		case SHAR:
			strcat(name, "_shar.ppm");
			ef_sharpening(image);
			break;

		case ROT:
			system("clear");
			rotation_controller(image);
			break;

		case AMP:
			printf("Quantas vezes deseja ampliar a imagem?\n");
			scanf("%i", &value);
			sprintf(nameFile, "_amp_%i.ppm", value);
			strcat(name, nameFile);
			ef_enlarge(image, value);
			break;

		case RED:
			printf("Quantas vezes deseja reduzir a imagem?\n");
			scanf("%i", &value);
			sprintf(nameFile, "_red_%i.ppm", value);
			strcat(name, nameFile);
			ef_reduce(image, value);
			break;

		case BW:
			strcat(name, "_bw.ppm");
			ef_black_white(image);
			break;

		case MIR:
			strcat(name, "_mir.ppm");
			ef_horizontal_mirror(image);
			break;

		case BORD:
			strcat(name, "_bordas.ppm");
			ef_border_detection(image);
			break;

		case INV:
			strcat(name, "_neg.ppm");
			ef_negative(image, clrRange);
			break;

		case SEP:
			strcat(name, "_sepia.ppm");
			ef_sepia(image);
			break;
		
		case COMP:
			strcat(name, "_comp.ppmc");
			compress_img(image);
			break;
			
		case EXIT:
			exit(1);

		default:
			system("clear");
			printf("Essa opcao nao existe, tente novamente.\n\n");
			choose_options(image);
			break;
	}
}

/**
 * A função "compress_img".\n
 * Comprime a imagem com um algoritmo de RLE (Runtime Lenght Encoding).\n
 * A função recebe a matriz de pixels "image" de tamanho "lat".
 */
void compress_img(Pixel image[lat][lat]){
	int i, j, mult = 0;

	/* Cria um único Pixel temporário para servir de auxiliar na função.*/
	Pixel temp = image[0][0];

	/* Cria o novo arquivo e escreve as informações básicas da imagem nele.*/
	FILE *newfile;
	newfile = fopen(name, "w");
	fprintf(newfile, "%s\n%i %i\n%i\n", filetype, width, height, clrRange);

	/* Os laços percorrem a matriz procurando por pixels repetidos e escrevendo-os
	 * no arquivo de acordo com o número de vezes que apareceram consecutivamente.*/
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			if(temp.red == image[i][j].red && temp.green == image[i][j].green && temp.blue == image[i][j].blue){
				mult++;
			}else{
				fprintf(newfile, "%i(%i %i %i)\n", mult, temp.red, temp.green, temp.blue);
				mult = 1;
				temp = image[i][j];
			}
		}
	}

	fprintf(newfile, "%i(%i %i %i) ", mult, temp.red, temp.green, temp.blue);
	fclose(newfile);

	system("clear");
    printf("O arquivo %s foi criado com sucesso na pasta raíz do programa.\n", name);
}

/**
 * A função "decompress_img".\n
 * Descomprime uma arquivo ppm que foi comprimido com algoritmo RLE desse mesmo programa.\n
 * A função recebe um tipo FILE "imagepath" que aponta para o arquivo que será descomprimido.
 */
void decompress_img(FILE *imagepath){
	FILE *newfile;
	int i, mult = 0;

	/* Cria um único Pixel temporário para servir de auxiliar na função.*/
	Pixel temp;

	/* Cria o novo arquivo com um novo sufixo no nome.*/
	strcpy(nameFile, name);
	strcat(nameFile, "_decomp.ppm");
	newfile = fopen(nameFile, "w");

	printf("O arquivo indicado está comprimido, começando descompressão\n");

	/* Lê e escreve as informações básicas da imagem no novo arquivo.*/
	fgets(filetype, 3, imagepath);
	fscanf(imagepath, "%i %i %i", &width, &height, &clrRange);
	fprintf(newfile, "%s\n%i %i\n%i\n", filetype, width, height, clrRange);

	/* Lê as informações do arquivo antigo e as escreve já descomprimidas no arquivo novo.*/
	while(fscanf(imagepath, "%i(%i %i %i)", &mult, &temp.red, &temp.green, &temp.blue) != EOF)
		for (i = 0; i < mult; i++)
			fprintf(newfile, "%i %i %i ", temp.red, temp.green, temp.blue);

	
	fclose(newfile);
	imagepath = fopen(nameFile, "r");

	printf("O arquivo foi descomprimido com sucesso.\n");
}
