//correção

#include <iostream>
using namespace std;

int numerospares[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int main(){

cout << "Esses são os numeros pares" << endl;

    for(int x = 0; x < 20; x++){
       if (numerospares[x] % 2 == 0){

           cout << " o numero " <<  numerospares[x] << " é par ";
           }else{
           cout << " o numero " << numerospares[x] << " é impar " ;
           }
    }



return 0;
}