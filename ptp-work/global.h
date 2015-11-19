typedef struct{
	int red;
	int green;
	int blue;
} Pixel;

int lat, height, width, clrRange;
char filetype[3], nome[50], nomeArq[55];

enum {THR = 1, BLU = 2, SHAR = 3, ROTL = 4, AMP = 5, RED = 6} options;
enum {BW = 10, MIR, BORDA, INV, SEP} extra;

/* TO DO:
* Função pra pular os comentários na leitura do arquivo
* Comentar código
* RLE
*/

void header();
void read_image(Pixel image[lat][lat], FILE *imagepath);
void create_new_file(Pixel image[lat][lat]);
void null_matrix(Pixel image[lat][lat]);
void controle_rotacao(Pixel image[lat][lat]);
void choose_options(Pixel image[lat][lat]);
void controller(int opcao, Pixel image[lat][lat]);

void ef_black_white(Pixel image[lat][lat]);
void ef_thresholding(Pixel image[lat][lat], int grau);
void ef_blur(Pixel image[lat][lat]);
void ef_sharpening(Pixel image[lat][lat]);
void ef_rotate_left(Pixel image[lat][lat]);
void ef_mirror_horizontal(Pixel image[lat][lat]);
void ef_ampliar(Pixel image[lat][lat], int grau);
void ef_reduzir(Pixel image[lat][lat], int grau);
void ef_detecta_borda(Pixel image[lat][lat]);
void ef_inverte_cores(Pixel image[lat][lat], int clrRange);
void ef_sepia(Pixel image[lat][lat]);
