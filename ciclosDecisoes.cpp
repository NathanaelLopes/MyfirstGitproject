#include <iostream>
using namespace std;

char vogais[5] = {'a','e','i','o','u'};

int main(){

    for(char nome : vogais){
   string ID;
   cout << "indique o ID para a vogal" << nome << endl;
   cin >> ID;
   cout << "ID da vogal" << nome << "é:" << ID << endl;
    }
    
    return 0;
}