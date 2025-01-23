#include <iostream>
using namespace std;

int main(){

struct Vogal{
    char vogal;
    string valor;
};

Vogal Vogais[]={
    {'a', "8258"},
    {'e', "8257"},
    {'i', "8258"},
    {'o', "8338"},
    {'u', "8263"},

};

for(Vogal vogal : Vogais){
    cout << vogal.vogal << endl;
}


  return 0;
}