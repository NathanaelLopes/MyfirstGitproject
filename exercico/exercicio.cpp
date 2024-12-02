#include <iostream>
#include <cstdlib> //permite aceder uma biblbioteca que permite gerar codigos aleatorios
#include <ctime>   //permite aceder ao tempo desde um determinada dta mais especificamente 1900 mais ou menos

using namespace std;

void tabuada(){


    int num;
    cout << "digite um numero";
    cin >> num;

    for(int i = 1 ;i<=10; i++) {

        cout << num << "x" << i << "=" << i << endl;

    }


}

void inverternome(){

   string userInput;
   cout << "Digite algo" << endl;
   cin >> userInput;

   int dimensao = userInput.length();

   for(int x = dimensao-1; x>=0; x--){
    cout << userInput[x];

   }
cout << " " <<endl;

} 

void tpcJogoAdivinhaLetra(){
 /**
  * Jogo Adivinha letra
  * 
  * terás um array com as letras minusculas do alfabeto e o compuatdor escolherá uma letra aleaória.
  * 
  * o jogdor terá que adivinhar a letra ecolhida pelo computador.
  *
  * O jogador terá que digitar uma letra e o computador dirá se a letra é o naior ou menor que a letra esolhida.
  * 
  * O jogo termia quando o jador acertar a letra esolhida.
  * 
  */
}



int main(){

srand(time(0));
int indice = rand() % 26;

    return 0;
}