#include <iostream>
using namespace std;

float soma(int x, float y){
    return x+y;
}

/**
 * @brief Funçao que aceita duas referencias de inteiros multiplica a soma destes valores e soma 10
 * @param x primeiro ref. numero inteiro
 * @param y segunda ref. numero inteiro
 * @return soma dos dois numeros
 */

int multiplica(int x, int y){
    return (x * y) + 10;

}

/**
 * @brief Funçao que aceita dois inteiros e retorna o resto da divisao entre dois numeros
 * @param x primeiro numero inteiro
 * @param y segundo mumeoro interio
 * @return Resto da divisao entre os dois numeros
 */

int resto(int x, int y){
    return x%y;
}

/**
 * @brief Funçao que aceita um array de inteiros e retorna o valor do indice 0
 * @param x Array de inteiros
 *@return vlor indice 0
 */

int primeiro(int x[]){
    return x[0];
}

/**
 * @brief Funça que aceita uma array de inteiros, um interio e devolve o indice referente ao inteiro passado
 * @param x Array de inteiros 
 * @param y inteiro
 * @return Indice referente ao ponteiro passado como valor Y
 */

int array(int x[], int y){
    return x[y];
}

/**
 * @brief Funçao que aceita um array de inteiros, um inteiro e imprime todos os valores do array até ao indice passado como valor y
 * @param x Array de inteiros
 * @param y inteiro
 */

void MyArray(int x[], int y){
    for(int i =0; i < y; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

struct ponto{
    int x;
    int y;
};
ponto pontos[] = {{1,2},{3,4},{5,6}};
/**
 * @brief funçao que aceita um array de pontos e imprime o valor de x de cada ponto
 * @param x array de pontos 
 */

void pontos(ponto x[]){
    for(int i = 0; i < 3; i++){
        cout << x[i].x << " ";
    }
    cout << endl;
}

int dobro(int x){
    return x*2;

}

/**
 * @brief que aceita um inteiro e devolve o seu dobro recorrendo à funçao dobro(int) definida acima
 * @param x inteiro
 * @return dobro do inteiro
 */

int dobroRec(int x){
    return dobro(x);
}
 
/**
 * @brief Funçao que aceita um array de interios com 10 elementos e devolve a soma de todos os elementos
 * @param x Array de inteiros
 * @return soma de todos os elementos do array
 */

int Array01(int x[]){
    int soma = 0;
    for(int i = 0; i<10; i++){
        soma+=x[i];
    }
    return soma;
}

int main(){

    return 0;
}