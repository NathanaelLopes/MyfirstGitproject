#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_NUMBER 75
#define MAX_NUM_OF_CARDS 5

int tmpCards[25];

    struct numero{
    int num;
    bool sts;
    };

 numero painel[MAX_NUMBER];

int main(){

    for(int i = 1; i < MAX_NUMBER; i++){
        painel[1].num = i + 1;
        painel[i].sts = false;
    }


 //Inserir uma seed para o random
 srand(time(0));

 for(int i = 0; i < 25; i++){
        tmpCards[i] = rand() % MAX_NUMBER;
        

        for(int j=0; j < i; j++){
         

           //verificarse o numero ja foi gerado
            if(tmpCards[j] == tmpCards[i]){
            i--;
            break;
            }  

              
        }

    }

    for(int i = 0; i < 25; i++){
        cout << tmpCards[i] << " ";
        if((i + 1) % 5 == 0)cout << endl;
    }
    
    
   return 0; 
}