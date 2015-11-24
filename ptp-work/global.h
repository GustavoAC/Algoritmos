typedef struct{
	int red;
	int green;
	int blue;
} Pixel;

int lat, height, width, clrRange;
char filetype[3], name[50], nameFile[55];

enum {EXIT = 0, THR, BLU, SHAR, ROT, AMP, RED} options;
enum {BW = 10, MIR, BORD, INV, SEP, COMP} extra;

/* TO DO:
* Função pra pular os comentários na leitura do arquivo
* Comentar código
* RLE
*/

void intro();
void read_image(Pixel image[lat][lat], FILE *imagepath);
void create_new_file(Pixel image[lat][lat]);
void null_matrix(Pixel image[lat][lat]);
void rotation_controller(Pixel image[lat][lat]);
void choose_options(Pixel image[lat][lat]);
void controller(int choice, Pixel image[lat][lat]);
void compress_img(Pixel image[lat][lat]);
void decompress_img(FILE *imagepath);

void ef_thresholding(Pixel image[lat][lat], int value);
void ef_blur(Pixel image[lat][lat]);
void ef_sharpening(Pixel image[lat][lat]);
void ef_rotate_left(Pixel image[lat][lat]);
void ef_enlarge(Pixel image[lat][lat], int value);
void ef_reduce(Pixel image[lat][lat], int value);
void ef_black_white(Pixel image[lat][lat]);
void ef_horizontal_mirror(Pixel image[lat][lat]);
void ef_border_detection(Pixel image[lat][lat]);
void ef_negative(Pixel image[lat][lat], int clrRange);
void ef_sepia(Pixel image[lat][lat]);
