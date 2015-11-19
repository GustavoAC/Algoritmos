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

void controle_rotacao(Pixel image[lat][lat]){
	int ang;
	printf("Digite o angulo de rotação (em sentido horario):\n");
	scanf("%i", &ang);
	switch (ang){
		case 90:
			strcat(nome, "_rot_90.ppm");
			ef_rotate_left(image);
			ef_rotate_left(image);
			ef_rotate_left(image);
			break;
		case 180:
			strcat(nome, "_rot_180.ppm");
			ef_rotate_left(image);
			ef_rotate_left(image);
			break;
		case 270:
			strcat(nome, "_rot_270.ppm");
			ef_rotate_left(image);
			break;
		default:
			system("clear");
			printf("Escolha um angulo reto: 90 - 180 - 270 \n");
			controle_rotacao(image);			
	}
}

void choose_options(Pixel image[lat][lat]){
	int escolha;
	
	printf("\n======== Escolha uma opção =======\n");
	printf("1 - thr     //    Thresholding   *\n");
	printf("2 - blur    //    Blurring       *\n");
	printf("3 - sha     //    Sharpennig     *\n");
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
	printf("==================================\n");

	scanf("%i", &escolha);
	controller(escolha, image);
}

void controller(int opcao, Pixel image[lat][lat]){
	if(opcao == THR){
		int grau;
		printf("Insira o padrão de binarização entre 0 e 255 (Padrão = 127)\n");
		scanf("%i", &grau);
		sprintf(nomeArq, "_thr_%i.ppm", grau);
		strcat(nome, nomeArq);
		ef_thresholding(image, grau);
	}else if(opcao == BW){
		strcat(nome, "_bw.ppm");
		ef_black_white(image);
	}else if(opcao == RED){
		int grau;
		printf("Quantas vezes deseja reduzir a imagem?\n");
		scanf("%i", &grau);
		sprintf(nomeArq, "_red_%i.ppm", grau);
		strcat(nome, nomeArq);
		ef_reduzir(image, grau);
	}else if(opcao == BLU){
		strcat(nome, "_blur.ppm");
		ef_blur(image);
	}else if(opcao == ROTL){
		system("clear");
		controle_rotacao(image);
	}else if(opcao == MIR){
		strcat(nome, "_mir.ppm");
		ef_mirror_horizontal(image);
	}else if(opcao == SHAR){
		strcat(nome, "_shar.ppm");
		ef_sharpening(image);
	}else if(opcao == AMP){
		int grau;
		printf("Quantas vezes deseja ampliar a imagem?\n");
		scanf("%i", &grau);
		sprintf(nomeArq, "_amp_%i.ppm", grau);
		strcat(nome, nomeArq);
		ef_ampliar(image, grau);
	}else if(opcao == BORDA){
		strcat(nome, "_bordas.ppm");
		ef_detecta_borda(image);
	}else if(opcao == INV){
		strcat(nome, "_neg.ppm");
		ef_inverte_cores(image, clrRange);
	}else if(opcao == SEP){
		strcat(nome, "_sepia.ppm");
		ef_sepia(image);
	}else{
		system("clear");
		printf("Essa opcao nao existe, tente novamente.\n\n");

		choose_options(image);

	}
}
