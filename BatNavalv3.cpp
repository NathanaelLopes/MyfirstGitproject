
#include <iostream>
#include <ctime>
using namespace std;

const int tamanho_tabuleiro = 10;
const int total_barcos = 10;

int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];
int tentativas_restantes = 25;
int barcos_afundados = 0;

struct Barco {
    int tamanho;
    bool horizontal;
    int x, y;
    int partes_atingidas;
};

Barco frota[total_barcos];

void inicializar_tabuleiro() {   // percorre todo o tabuleiro e coloca 0 que define a agua
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for(int j = 0; j < tamanho_tabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void mostrar_tabuleiro(bool mostrar_barcos = false) {
    cout << "    ";
    for (int j = 0; j < tamanho_tabuleiro; j++) {
        cout << j << "  ";
    }
    cout << endl;

    for (int i = 0; i < tamanho_tabuleiro; i++) {
        cout << i << "| ";
        for(int j = 0; j < tamanho_tabuleiro; j++) {
            if (tabuleiro[i][j] == 0) cout << "🌊 ";
            else if (tabuleiro[i][j] == 1 && mostrar_barcos) cout << "⛵ ";
            else if (tabuleiro[i][j] == 1) cout << "🌊 "; 
            else if (tabuleiro[i][j] == 2) cout << "💥 ";
            else if (tabuleiro[i][j] == 3) cout << "❌ ";
        }
        cout << endl;
    }
    cout << endl;
}

/* Esta função verifica se é possível colocar um barco numa posição 
sem ultrapassar os limites do tabuleiro nem colidir com outro barco.*/

bool posicao_valida(int x, int y, int tamanho, bool horizontal) {  
    if (horizontal) {
        if (y + tamanho > tamanho_tabuleiro) return false; // verifica se cabe y 
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x][y + i] != 0) return false;
        }
    } else {
        if (x + tamanho > tamanho_tabuleiro) return false; // verifica se cabe x
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y] != 0) return false;
        }
    }
    return true;
}

void colocar_barco(int x, int y, int tamanho, bool horizontal, int indice_barco) {
    frota[indice_barco].tamanho = tamanho;
    frota[indice_barco].horizontal = horizontal;
    frota[indice_barco].x = x;
    frota[indice_barco].y = y;
    frota[indice_barco].partes_atingidas = 0;

    if (horizontal) {
        for (int i = 0; i < tamanho; i++) { //verifica se e horizontal x ou vertical Y
            tabuleiro[x][y + i] = 1;
        }
    } else {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[x + i][y] = 1;
        }
    }
}

/*1 barco de tamanho 5 (porta-aviões)
1 de tamanho 4 (couraçado)
2 de tamanho 3 (cruzadores)
1 de tamanho 2 (submarino)
5 de tamanho 1 (barcos pequenos)*/

void criar_frota_automatica() { // quantos barcos de cada tamanho devem ser colocados.
    int barcos_por_tamanho[] = {1, 1, 2, 1, 5}; 
    int tamanhos[] = {5, 4, 3, 2, 1};
    int indice_barco = 0;

    for (int t = 0; t < 5; t++) {
        for (int b = 0; b < barcos_por_tamanho[t]; b++) {
            bool colocado = false;
            while (!colocado) {
                int x = rand() % tamanho_tabuleiro; //colocar em uma posiçao aleatoria x e y
                int y = rand() % tamanho_tabuleiro;
                bool horizontal = rand() % 2 == 0;

                if (posicao_valida(x, y, tamanhos[t], horizontal)) {  //verifica se a posiçao e valida para colocar os barcos
                    colocar_barco(x, y, tamanhos[t], horizontal, indice_barco);
                    indice_barco++;
                    colocado = true;
                }
            }
        }
    }
}

bool atirar(int x, int y) {
    if (tabuleiro[x][y] == 1) { //se tiver um navio 1 vai marcar como tiro 2
        tabuleiro[x][y] = 2;
        
        for (int i = 0; i < total_barcos; i++) { //percorre todos os barcos 
            Barco& barco = frota[i];
            bool atingiu = false;
            
            if (barco.horizontal) {
                for (int j = 0; j < barco.tamanho; j++) {
                    if (barco.x == x && barco.y + j == y) { //percorre e verifica se foi realmente atingido x e y
                        barco.partes_atingidas++;
                        atingiu = true;
                        break;
                    }
                }
            } else {
                for (int j = 0; j < barco.tamanho; j++) {
                    if (barco.x + j == x && barco.y == y) {
                        barco.partes_atingidas++;
                        atingiu = true;
                        break;
                    }
                }
            }
            
            if (atingiu) {
                if (barco.partes_atingidas == barco.tamanho) {  //verifica se foi afundado o barco
                    barcos_afundados++;
                    cout << "Voce afundou um navio de tamanho " << barco.tamanho << "!" << endl;
                } else {
                    cout << "Voce acertou um navio!" << endl;
                }
                break;
            }
        }
        return true;
    } else if (tabuleiro[x][y] == 0) { // verifica se acertou na agua 0 e marca como erro 3
        tabuleiro[x][y] = 3;
        return false;
    }
    return false;
}

int contar_barcos_restantes() { // verifica se o barco ainda esta flutuando ou nao e mostra quantos tem
    int restantes = 0;
    for (int i = 0; i < total_barcos; i++) {
        if (frota[i].partes_atingidas < frota[i].tamanho) {
            restantes++;
        }
    }
    return restantes;
}

void mostrar_estatisticas() {
    cout << "=== ESTATISTICAS ===" << endl;
    cout << "Tentativas restantes: " << tentativas_restantes << endl;
    cout << "Barcos restantes: " << contar_barcos_restantes() << endl;
    cout << "Barcos afundados: " << barcos_afundados << "/" << total_barcos << endl;
    cout << "------------------------------" << endl << endl;
}

int main() {
    srand(time(NULL)); // inicializa o gerador de números aleatórios
    
    inicializar_tabuleiro(); // limpa o tabuleiro (só água).
    criar_frota_automatica(); // posiciona os 10 barcos aleatoriamente.

    cout << "=== BATALHA NAVAL 67 ===" << endl;
    cout << "Tabuleiro: " << tamanho_tabuleiro << "x" << tamanho_tabuleiro << endl;
    cout << "Frota: 1 Porta-avioes (5), 1 Couracado (4), 2 Cruzadores (3), 1 Submarino (2), 5 Barcos pequenos (1)" << endl;
    cout << "Tentativas: " << tentativas_restantes << endl;
    cout << "Coordenadas: 0 a " << tamanho_tabuleiro-1 << endl;
    cout << "Simbolos: 🌊  = Agua, ❌ = Tiro na agua, 💥 = Acerto no navio" << endl;
    cout << "------------------------------" << endl << endl;


    int linha, coluna;
    char comando;

    while(tentativas_restantes > 0) {
        mostrar_estatisticas();
        mostrar_tabuleiro();

        cout << "Digite as coordenadas (linha coluna): ";
        cin >> linha >> coluna;

        if(linha < 0 || linha >= tamanho_tabuleiro || coluna < 0 || coluna >= tamanho_tabuleiro) { // verifica se esta nos limites
            cout << "Coordenadas invalidas! Use valores entre 0 e " << tamanho_tabuleiro-1 << endl;
            continue;
        }

        if(tabuleiro[linha][coluna] == 2 || tabuleiro[linha][coluna] == 3) {
            cout << "Voce ja atirou nesta posicao!" << endl;
            continue;
        }

        tentativas_restantes--;

        if(atirar(linha, coluna)) {
            cout << "--- ACERTOU! ---" << endl;
        } else {
            cout << "--- AGUA! ---" << endl;
        }

        if(contar_barcos_restantes() == 0) {
            cout << endl << "PARABENS! Venceste afundas-te toda a frota!" << endl;
            break;
        }

        if(tentativas_restantes == 0) {
            cout << endl << "FIM DE JOGO! Suas tentativas acabaram!" << endl;
            cout << "Barcos restantes: " << contar_barcos_restantes() << endl;
        }
    }


    cout << endl << "=== TABULEIRO FINAL ===" << endl;
    mostrar_tabuleiro(true); // mostra o tabuleiro com tudo
    
    cout << "Obrigado por jogar Batalha Naval! GOOD BOY/GIRL!" << endl;

    return 0;
}
