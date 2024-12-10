#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 

int tamanhodocartao = 5; 
 int cartoes;
 bool umcartoes = true;
 
 int main() {

cout << "Bem vindo ao jogo do bingo!!" <<endl;
cout << "Pode escolher entre 1 ou 2 cartões"<<endl;
 cout<< "Quantos cartoes deseja?:";
    cin >> cartoes;
    
   if (cartoes < 1 || cartoes > 2) {
        cout << "Só pode ser 1 ou 2 cartões." << endl;
        return 0;
    }

 struct NumerosDoCartao {
        int numero;
        bool jogado;
    };

    NumerosDoCartao num[75];
    for (int i = 0; i < 75; i++) {
        num[i].numero = i;
        num[i].jogado = false;
    }
  
    int cartao1[tamanhodocartao][tamanhodocartao];
     int cartao2[tamanhodocartao][tamanhodocartao];
    bool usados[76] = {false}; // Para verificar se o número já foi sorteado

    for (int y = 0; y < tamanhodocartao; y++) {
        for (int x = 0; x < tamanhodocartao; x++) {
            int numero;
            do {
                numero = rand() % 75 + 1; // Gera número entre 1 e 75
            } while (usados[numero]); // Garante que o número não foi usado

            usados[numero] = true; // Marca o número como usado
            cartao1[x][y] = numero; // Preenche o cartão
        }
    }
  if (cartoes == 2) {
        for (int y = 0; y < tamanhodocartao; y++) {
            for (int x = 0; x < tamanhodocartao; x++) {
                int numero;
                do {
                    numero = rand() % 75 + 1; // Gera número entre 1 e 75
                } while (usados[numero]); // Garante que o número não foi usado

                usados[numero] = true; // Marca o número como usado
                cartao2[x][y] = numero; // Preenche o cartão
            }
        }
    }

    cout << "Seu cartão 1: " << endl;
    for (int y = 0; y < tamanhodocartao; y++) {
        for (int x = 0; x < tamanhodocartao; x++) {
            cout << cartao1[x][y] << "\t";
        }
        cout << endl;
    }

    // Exibe o segundo cartão, se necessário
    if (cartoes == 2) {
        cout << "\nSeu cartão 2: " << endl;
        for (int y = 0; y < tamanhodocartao; y++) {
            for (int x = 0; x < tamanhodocartao; x++) {
                cout << cartao2[x][y] << "\t";
            }
            cout << endl;
            
        }
    }
    
    int tentativas = 75;
     while (tentativas > 0) {
     int numeros;
   numeros = rand() % 75 + 1; 
   int enter;
   cin >> enter; 
   if(enter = 5){
       cout << "O numero aleatorio é:" << numeros <<endl;
   }
    
    tentativas --;
     }
    

    return 0;
}