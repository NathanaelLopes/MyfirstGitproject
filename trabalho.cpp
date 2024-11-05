#include <iostream>
using namespace std;


int main() {

    int numerospares[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
    20};
    
    for(int x=0; x < 20; x++){
        if (numerospares[x] % 2 == 0)

        cout << numerospares[x] << endl;
    }




    return 0;
}


//correção

#iclude <iostrem>
using namespace std;

int numerospares[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int main(){

cout << "Esses são os numeros pares" << endl;

    for(int x = 0; x < 20; x++){
       if (numerospares[x] % 2 == 0){

           cout << numerospares[20] << endl;
           
    }
           



return 0;
}
