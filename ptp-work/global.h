/**
* \file global.h
* \brief Contém as assinaturas das principais funções e as variáveis globais.
*/

/**
 * Struct que contém os valores RGB de um determinado pixel. */
typedef struct{
	int red;	 /**<Amarzena o valor correspondente ao tom de vermelho.*/
	int green;   /**<Armazena o valor correspondente ao tom de verde.*/
	int blue;    /**<Armazena o valor correspondente ao tom de azul.*/
} Pixel;

int lat;		/**<Recebe o maior valor entre altura e largura.*/
int height; 	/**<Recebe o valor da altura.*/
int width; 		/**<Recebe o valor da largura.*/
int clrRange;	/**<Recebe o valor da escala máxima de cores.*/

char filetype[3]; 	/**<Recebe o tipo de PPM, verificando se o arquivo é P3 (tratado nesse programa).*/
char name[50]; 		/**<Recebe o nome do arquivo da imagem que será tratada.*/
char nameFile[55];	/**<Recebe o nome concatenado do arquivo da imagem com a extensão (.PPM).*/ 

/** 
 * Enumerações que determina a escolha que o usuário fez no menu de opções de efeitos. */
enum {EXIT = 0, THR, BLU, SHAR, ROT, AMP, RED} options;
/** 
 * Enumerações que determina a escolha que o usuário fez no menu de opções de efeitos extras. */
enum {BW = 10, MIR, BORD, INV, SEP, COMP} extra;

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
