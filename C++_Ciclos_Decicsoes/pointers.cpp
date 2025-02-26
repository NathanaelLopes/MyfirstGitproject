#include <iostream>
using namespace std;

int x=10;
int y=20;
int g=30;

int soma(int &z, int &w){
    return x+y;
}   

//funçao que soma o g, passado por referencia
//com o valor retornado da funçao soma x e y

int soma2(int &g){
    return g + soma(x,y);
}    


int main(){


return 0;
}