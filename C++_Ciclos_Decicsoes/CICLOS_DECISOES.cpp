#include <iostream>
using namespace std; 

 /*int comprimentoDaString(string str){
        int y = size(str);
        return y;
    }
*/
    int soma(int& x, int& y){
        x = 10;
        y = 20;
        return x+y;
    }


int main(){
    //cout << comprimentoDaString("ola") << endl;

    int a = 5;
    int b = 10;
    cout << a << "\n\n";
    cout << soma(a,b) << "\n\n";
    cout << a << "\n\n";
       

    return 0;
}