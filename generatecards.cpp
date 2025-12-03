#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

class BingoCard {
private:
    int card[5][5];
    
    vector<int> generateUniqueNumbers(int min, int max, int count) {
        vector<int> numbers;
        for (int i = min; i <= max; i++) {
            numbers.push_back(i);
        }
        
        random_device rd;
        mt19937 g(rd());
        shuffle(numbers.begin(), numbers.end(), g);
        
        return vector<int>(numbers.begin(), numbers.begin() + count);
    }
    
public:
    BingoCard() {
        vector<int> colB = generateUniqueNumbers(1, 20, 5);
        vector<int> colI = generateUniqueNumbers(21, 40, 5);
        vector<int> colN = generateUniqueNumbers(41, 60, 5);
        vector<int> colG = generateUniqueNumbers(61, 80, 5);
        vector<int> colO = generateUniqueNumbers(81, 100, 5);
        
        for (int row = 0; row < 5; row++) {
            card[row][0] = colB[row];
            card[row][1] = colI[row];
            card[row][2] = colN[row];
            card[row][3] = colG[row];
            card[row][4] = colO[row];
        }
        
        card[2][2] = 0;
    }
    
    void display(int cardNumber) {
        cout << "\nCarta " << cardNumber << ":" << endl;
        cout << " B      I      N      G      O" << endl;
        
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (row == 2 && col == 2) {
                    cout << setw(3) << "**" << "    ";
                } else {
                    cout << setw(3) << card[row][col] << "    ";
                }
            }
            cout << endl;
        }
    }
    
    // Salvar cartela em arquivo individual
    void saveToFile(int cardNumber) {
        // Criar nome do arquivo: carta_1.txt, carta_2.txt, etc.
        ostringstream filename;
        filename << "carta_" << cardNumber << ".txt";
        
        ofstream file(filename.str());
        
        if (!file.is_open()) {
            cerr << "Erro ao criar arquivo: " << filename.str() << endl;
            return;
        }
        
        // Escrever cabeçalho
        file << "==================================================" << endl;
        file << "              CARTÃO DE BINGO #" << cardNumber << endl;
        file << "==================================================" << endl;
        file << endl;
        
        // Escrever as colunas
        file << " B      I      N      G      O" << endl;
        file << "---   ---   ---   ---   ---" << endl;
        
        // Escrever os números
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (row == 2 && col == 2) {
                    file << setw(3) << "**" << "    ";
                } else {
                    file << setw(3) << card[row][col] << "    ";
                }
            }
            file << endl;
        }
        
        // Rodapé
        file << endl;
        file << "==================================================" << endl;
        file << "    Boa sorte! Marque os números sorteados!" << endl;
        file << "==================================================" << endl;
        
        file.close();
        
        cout << "  -> Arquivo criado: " << filename.str() << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " [numero_de_cartas]" << endl;
        cout << "Exemplo: " << argv[0] << " 20" << endl;
        return 1;
    }
    
    int numCards = atoi(argv[1]);
    
    if (numCards < 1 || numCards > 500) {
        cout << "Erro: O número de cartas deve estar entre 1 e 500." << endl;
        return 1;
    }
    
    cout << "==================================================" << endl;
    cout << "       GERADOR DE CARTÕES DE BINGO" << endl;
    cout << "==================================================" << endl;
    cout << "Gerando " << numCards << " carta(s)..." << endl;
    cout << endl;
    
    // Gerar e salvar os cartões
    for (int i = 0; i < numCards; i++) {
        BingoCard card;
        card.display(i + 1);
        card.saveToFile(i + 1);
    }
    
    cout << "\n==================================================" << endl;
    cout << "Total de cartas geradas: " << numCards << endl;
    cout << "Arquivos salvos: carta_1.txt até carta_" << numCards << ".txt" << endl;
    cout << "==================================================" << endl;
    
    return 0;
}