#include <iostream> // usar smepre

using namespace std;// usar sempre

int main(){

 // Funçao principal
    cout << "Hello World" << endl;
    

 // funçao sempre dentro das chaves {}


    // Adição de números
     cout << 3 + 3 << endl;

    //subtração de números 
    cout << 3 * 3 << endl;

    // Divisão de números
    cout << 3 / 3 << endl;

    // Resto da divisão
    cout << 5 % 3 << endl;

    //Variaveis sempre minúsculas ou camel case, nunca deve começar com número
    int qntLivros = 5; // int=inteiro
    int x , y ,z;
    x = 25;
    cout << qntLivros * 2 << endl;
    cout << qntLivros + 5 << endl;
    cout << qntLivros - 2 << endl;


    bool isTrue = true;
    bool isHIgh;
    isHIgh = true;

    float altura = 1.75;
    float peso;
    peso = 34.6;

    double altura2 = 1.75;
    double peso2;
    peso2 = 34.6;

    char letra = 'a';
    char letra2;
    letra2 = 'b';


    string nome = "Luscas"; //string e um conjunton de chars
    string sobrenome;
    sobrenome = "santos";
    

    cout << " Nome " << nome << " " << sobrenome << endl;


    // 2 * pi * r;
    const float PI = 3.1416; // const=constante e um, valor que nao pode variar e nem ser alterado no codigo e tem que ser MAIUSCULAS
    const int X = 2;
    
    float valor;

    cout << "indique o valor do raio";
    cin >> valor;
    cout << y * PI * 5 << endl;

    //operadores lógicos:
    // ==        Igual
    // !=        Diferente
    // >         Maior
    // <         Menor
    // >=        Maior ou igual
    // <=        Menor ou igual

    // &&        e o
    // ||        OU

 
    int abc;
    if( abc == 'a' ){
        cout << "abc é igual a a" << endl;
    }else{
        cout << "abc é diferente de a" << endl;
    }

    int x = 2;
    int y = 3;
    int z = 3;


    if( x == 2){
        cout << "x é igual a dois" << endl;
    }else if( z == 3){
        cout << "y é igual a três" << endl;
    }else if( z == 4){
        cout << "z é igual a quatro" << endl;
    }else{
        cout << "nenhum dos valores é igual a 2, 3 ou 4" << endl;
    }


    // string result = (time < 18) ? "bom dia." : "Boa noite"; forma resumida

    // cout << result;
    // comparar valores
    // else if vai ser chamada se a anterior for chamada
    // switch é para selecionar um dos blocos de comamndo


    return 0;

}