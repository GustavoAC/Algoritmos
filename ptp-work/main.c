#include <stdio.h>



int main(){

	FILE *image;
	int n;
	char ta1, ta2, nome[50];
	fgets(nome, 50, stdin);
	printf("%s", nome);
	image = fopen(".ppm", "r");
	
	if(image == NULL) printf("Nem abriu");
	else{
		fscanf(image, "%c%c", &ta1, &ta2);
		if(ta1 == 'P' && ta2 == '3')		
			while(fscanf(image, "%i", &n) != EOF)
				fprintf(stdout, "%i ", n);
	}
	
	fclose(FILE *image);
	return 0;
}
