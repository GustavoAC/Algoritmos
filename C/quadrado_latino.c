#include <stdio.h>

//Autor: Gustavo Araujo Carvalho


/*
* Esta função serve para checar se existem dois valores iguais na mesma linha,
* o que invalidaria a proposição de ser quadrado latino.
*/
int checkHorizontal(int n, int matriz[n][n]){

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
    for(i = 0; i < n && lat; i++){
        for(j = 0; j < n && lat; j++){
            for(k = 0; k < n && lat; k++){
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
int checkVertical(int n, int matriz[n][n]){

    /*
    * Essa função tem o funcionamento exatamente igual ao da função checkHorizontal,
    * com a diferença que procura valores iguais na mesma coluna ao invés de na
    * mesma linha. As variáveis i, j, e k ainda servem para iteração e lat como a
    * variável booleana de resposta.
    */
    int i, j, k, lat = 1;

    for(j = 0; j < n && lat; j++){
        for(i = 0; i < n && lat; i++){
            for(k = 0; k < n && lat; k++){
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
void popularMatriz(int n, int matriz[n][n]){

    /*
    * As variáveis i e j servem para iteração, os loops percorrerão todos os
    * espaços da matriz e pedirão um valor para o usuário pôr em cada um deles.
    */
    int i, j;

    printf("Digite os valores do quadrado a ser testado:\n");

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%i", &matriz[i][j]);
            while(matriz[i][j] > n){
                printf("Somente valores menores ou iguais ao tamanho do quadrado\n");
                printf("sao permitidos nesse quadrado latino, digite outro valor.\n");
                scanf("%i", &matriz[i][j]);
            }
        }
    }
}

/*
* Esse é o início do programa.
*/
int main(){

    /*
    * A variável n é inicializada, ela armazenará o tamanho da matriz
    * e servirá como parâmetro para inicializá-la.
    */
    int n;

    /*
    * Uma mensagem de boas-vindas é exibida ao usuário, a medida do
    * quadrado é pedida a ele e é armazenada na variável n.
    */
    printf("Bem vindo ao programa do quadrado latino!\n");
    printf("Digite a medida do quadrado: ");
    scanf("%i", &n);

    /*
    * A matriz é inicializada com n linhas e n colunas e, logo após, a função
    * popularMatriz é chamada e valores são atribuídos.
    */
    int matriz[n][n];
    popularMatriz(n, matriz);

    /*
    * A seguir, uma estrutura condicional usa as funções checkHorizontal
    * e checkVertical para checar se a matriz é ou não um quadrado latino.
    * As funções retornam valores booleanos de 1 (True) ou 0 (False), e a
    * matriz só é considerada um quadrado latino se ambas as condições forem
    * verdadeiras.
    * Se ambas forem verdadeiras, o programa diz que a matriz é um quadrado
    * latino, mas se ao menos uma das condições for falsa, o programa dirá
    * que a matriz não é um quadrado latino.
    */
    if (checkHorizontal(n, matriz) && checkVertical(n, matriz))
        printf("A matriz digitada eh um quadrado latino.");
    else
        printf("A matriz digitada nao eh um quadrado latino.");

    /*
    * Fim do programa
    */
    return 0;
}
