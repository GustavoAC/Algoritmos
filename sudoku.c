#include <stdio.h>

//Autores: Gustavo Araujo Carvalho e Yuri Alessandro

/*
* Esta função serve para checar se existem dois valores iguais na mesma linha,
* o que invalidaria a proposição da matriz ser um quadrado latino.
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
    for(i = 0; i < 9 && lat; i++)
        for(j = 0; j < 9 && lat; j++)
            for(k = 0; k < 9 && lat; k++)
                if((j != k) && (matriz[i][j] == matriz[i][k]))
                    lat = 0;

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

    for(j = 0; j < 9 && lat; j++)
        for(i = 0; i < 9 && lat; i++)
            for(k = 0; k < 9 && lat; k++)
                if((i != k) && (matriz[i][j] == matriz[k][j]))
                    lat = 0;

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
    * Há também um loop que impede o usuário de colocar valores acima de 9,
    * pois o jogo de Sudoku só aceita números de 1 a 9;
    */
    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++){
            scanf("%i", &matriz[i][j]);
            while(matriz[i][j] < 1 || matriz[i][j] > 9){
                printf("Somente valores maiores que 0 e menores ou iguais a 9\n");
                printf("sao permitidos no jogo de sudoku, digite outro valor.\n");
                scanf("%i", &matriz[i][j]);
            }
        }
}

/*
* Esta função serve para checar os setores menores do jogo de Sudoku, para
* fazer isso, recebe uma matriz 3x3, que tem o tamanho de um setor do jogo
* de Sudoku e verifica se esse mesmo é válido.
* A função passa por todos os valores da matriz e conta a frequência dos
* números de 1 a 9. Já que todos os quadrados são preenchidos e só existem
* 9 quadrados em cada setor, ele deve ter valores únicos de 1 a 9 , Se houver
* um dígito repetido, significa que todos os 9 que deveriam estar presentes
* não estão, e logo, o Sudoku é inválido.
*/
int checarMenor(int mini[3][3]){
    /*
    * As variáveis i e j servem para iterar através de todas as posições da
    * matriz, enquanto que num serve para iterar de 1 a 9, os números que
    * serão procurados. "existe" é a variável que informa quantas vezes o número
    * "num" foi encontrado na matriz.
    */
    int i, j, num, existe = 0;

    /*
    * Os loops passam por todos os valores da matriz e sempre que encontram o
    * número "num" em um dos espaços incrementam a variável "existe" em mais 1.
    * Se "existe" for maior que 1, isto é, se ouver mais de um número "num" no mesmo
    * setor, o setor é automaticamente inválido e retorna falso. Caso passe por
    * todos os loops corretamente, não há problemas no setor e função retorna
    * verdadeiro.
    */
    for(num = 1; num <= 9; num++){
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                if(mini[i][j] == num) existe++;
        if(existe > 1) return 0;
        existe = 0;
    }

    return 1;
}
/*
* Esta função serve para separar a matriz completa 9x9 em matrizes
* pequenas 3x3 e enviá-las para a função checarMenor(), para assim serem
* retornadas como válidas ou não.
*/
int checarMenores(int matriz[9][9]){
    /*
    * As variáveis i e j servem para iterar sobre a matriz 9x9 e identificar
    * os setores do Sudoku. Elas crescem de 3 em 3 para ter início exatamente
    * sobre o primeiro quadrado de cada setor, isso serve de referência para
    * o começo de onde o programa vai começar a pegar os valores para por na
    * matriz mini.
    * As variáveis k e l servem para iterar sobre os elementos da matriz pequena
    * 3x3; e da matriz 9x9 tomando como início os pontos i e j, para todos os
    * elementos da matriz grande serem alcançados.
    * A matriz mini 3x3, na sua vez, armazenará os valores de cada um desses
    * setores para serem depois enviados para a função checarMenor()
    */
    int i, j, k, l, mini[3][3];

    /*
    * Como já dito, os loops de i e j vão iterar sobre o começo de cada setor e
    * os loops de k e l sobre esses mesmos setores. Quando uma matriz 3x3 for completa,
    * ela será enviada para a função checarMenor() para verificar se é ou não válida.
    * Caso ela não seja válida, a função checarMenor() retornará falso, o que causará
    * a função atual retornar falso também, pois o Sudoku é inválido.
    * Caso todos os loops sejam completados sem problema, quer dizer que o programa
    * não achou nenhuma inconsistência, e então a função retornará verdadeiro.
    */
    for(i = 0; i < 9; i += 3)
        for(j = 0; j < 9; j += 3){
            for(k = 0; k < 3; k++)
                for(l = 0; l < 3; l++)
                    mini[k][l] = matriz[k+i][l+j];
            if(!checarMenor(mini))
                return 0;
        }

    return 1;
}
/*
* Este é o início do programa.
* Primeiramente ele criará uma matriz 9x9 e a enviará para a função popularMatriz().
* Lá o usuário inserirá valores na matriz.
*/
int main(){
    int matriz[9][9];
    popularMatriz(matriz);

    /*
    * Agora uma estrutura condicional vai verificar se o matriz inserida pelo
    * usuário é ou não um Sudoku válido.
    * As funções checkHorizontal() e checkVertixal() vão verificar se a matriz
    * é um quadrado latino 9x9, uma das condições para ser Sudoku, enquanto
    * checarMenores vai verificar, com a ajuda de checarMenor(), cada um dos
    * setores da Matriz, que devem ter valores únicos de 1 a 9 dentro deles;
    * essa também é uma condição para Sudoku.
    *
    * Se as três funções retornarem verdadeiro, significa que a matriz realmente
    * forma um Sudoku, e uma mensagem que expressa isso será impressa na tela.
    * Mas se ao menos um desses retornar falso, significa que a matriz não é Sudoku,
    * e assim uma mensagem será impressa na tela informando isso.
    */
    if(checkHorizontal(matriz) && checkVertical(matriz) && checarMenores(matriz))
        printf("A matriz inserida forma um Sudoku. Parabéns!");
    else
        printf("A matriz inserida nao forma um Sudoku. Que pena!");

    /*
    * Fim do Programa.
    */
    return 0;
}
