#include <stdio.h>

//Autor: Gustavo Araujo Carvalho


/*
* Esta função serve para checar se existem dois valores iguais na mesma linha,
* o que invalidaria a proposição de ser quadrado latino.
*/
int checkHorizontal(int matriz[9][9]){

    /*
    * As variáveis i, j e k servem para iteração.
    * A variável lat serve como retorno e tem o valor padrão de 1,
    * que considera que o quadrado já é inicialmente latino.
    */
    int i, j, k, lat = 1;

    /*
    * O primeiro loop serve para percorrer as linhas da matriz, enquanto que
    * o segundo e o terceiro loop servem para comparar valores que ocupam a
    * mesma linha, se esses valores forem iguais, o quadrado não é latino e o
    * valor de lat vai a zero. Há também a condição de parada nos loops para
    * quando lat for falso (igual a 0), isso serve para quebrar os loops e evitar
    * processamento desnecessário.
    * Há o cuidado de se colocar j diferente de k como condição no if para
    * não comparar valores que são iguais.
    */
    for(i = 0; i < 9 && lat; i++){
        for(j = 0; j < 9 && lat; j++){
            for(k = 0; k < 9 && lat; k++){
                if((j != k) && (matriz[i][j] == matriz[i][k]))
                    lat = 0;
            }
        }
    }

    /*
    O valor retornado é lat, que serve como uma variável booleana
    quando se trata de dizer se o quadrado é ou não latino.
    */
    return lat;
}

/*
* Esta função serve para checar se existem dois valores iguais na mesma coluna,
* o que invalidaria a proposição de ser quadrado latino.
*/
int checkVertical(int matriz[9][9]){

    /*
    * Essa função tem o funcionamento exatamente igual ao da função checkHorizontal,
    * com a diferença que procura valores iguais na mesma coluna ao invés de na
    * mesma linha. As variáveis i, j, e k ainda servem para iteração e lat como a
    * variável booleana de resposta.
    */
    int i, j, k, lat = 1;

    for(j = 0; j < 9 && lat; j++){
        for(i = 0; i < 9 && lat; i++){
            for(k = 0; k < 9 && lat; k++){
                if((i != k) && (matriz[i][j] == matriz[k][j]))
                    lat = 0;
            }
        }
    }

    /*
    * O return é o booleano lat, que diz se o quadrado é ou não latino
    * considerando somente as colunas.
    */
    return lat;
}

/*
* Esta função serve para preencher a matriz com os valores inseridos pelo
* usuário. Como arranjos já são por si só um tipo de ponteiro, as mudanças
* que acontecem nessa função afetam a matriz declarada na função main.
*/
void popularMatriz(int matriz[9][9]){

    /*
    * As variáveis i e j servem para iteração, os loops percorrerão todos os
    * espaços da matriz e pedirão um valor para o usuário pôr em cada um deles.
    */
    int i, j;

    printf("Digite os valores do quadrado a ser testado:\n");

    /*
    * Há também um loop que impede o usuário de colocar valores acima de n,
    * o que impossibilitaria a medição própria de saber se é ou não um
    * quadrado latino.
    */
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            scanf("%i", &matriz[i][j]);
            while(matriz[i][j] > 9){
                printf("Somente valores menores ou iguais a 9 sao permitidos no \n");
                printf("jogo de sudoku, digite outro valor.\n");
                scanf("%i", &matriz[i][j]);
            }
        }
    }
}

int checarMenor(int mini[3][3]){
    int i, j, num, existe = 0;

    for(num = 1; num <= 9; num++){
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                    if(mini[i][j] == num) existe++;
            }
        }
        if(existe > 1) return 0;
        existe = 0;
    }

    return 1;
}

int checarMenores(int matriz[9][9]){
    int i, j, k, l, mini[3][3];

    for(i = 0; i < 9; i += 3){
        for(j = 0; j < 9; j += 3){
            for(k = 0; k < 3; k++){
                for(l = 0; l < 3; l++){
                    mini[k][l] = matriz[k+i][l+j];
                }
            }
            if(!checarMenor(mini)){
                return 0;
            }
        }
    }

    return 1;
}

int main(){
    int matriz[9][9];
    popularMatriz(matriz);

    if(checkHorizontal(matriz) && checkVertical(matriz)){
        if(checarMenores(matriz)){
            printf("A matriz inserida forma um Sudoku. Parabéns!");
            return 0;
        }
    }
    printf("A matriz inserida nao forma um Sudoku. Que pena!");
    return 0;
}

