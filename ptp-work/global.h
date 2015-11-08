typedef struct{
	int red;
	int green;
	int blue;
} Pixel;

int lat, height, width, clrRange;
char filetype[3], nome[50], nomeArq[55];

enum {STR = 1, BW, BLU, ROTR, ROTL, MIR} options;

void header();
FILE *open_image(char name[]);
void read_image(Pixel image[height][width], FILE *imagepath);
void ef_black_white(Pixel image[height][width]);
void ef_thresholding(Pixel image[height][width]);
void create_new_file(Pixel image[height][width]);
void print_options(Pixel image[height][width]);
void controller(int opcao, Pixel image[height][width]);
void null_matrix(Pixel image[lat][lat]);
