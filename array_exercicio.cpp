#include <iostream>
using namespace std;

float numero[10] = {12.3, 14.7, 34.8, 12.5, 17.5, 13.5, 17.8, 24.1, 28.2, 35.1};

int main() {

    float soma =0, media=0;

cout << "aqui esta a media" << endl;

for (int n=0; n<10; n++){
        soma += numero[n];
    }

    cout << soma/10 << endl;

return 0;
}