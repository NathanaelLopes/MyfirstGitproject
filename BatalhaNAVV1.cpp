#include <iostream> 
#include <ctime>     
using namespace std;


const int tamanho_tabuleiro = 10;  // define o tamanho do tabuleiro (10x10)
const int total_barcos = 10;       // número total de barcos


int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];  // matriz que representa o tabuleiro
int tentativas_restantes = 25;   // número máximo de tiros que o jogador pode dar
int barcos_afundados = 0;        // contador de quantos barcos já foram afundados


struct Barco {
    int tamanho;            // número de partes do barco
    bool horizontal;        // orientação: true = horizontal, false = vertical
    int x, y;               // posição inicial do barco (linha e coluna)
    int partes_atingidas;   // contador de quantas partes do barco foram atingidas
};

Barco frota[total_barcos];  // guarda todos os barcos da frota

// Função para inicializar o tabuleiro
void inicializar_tabuleiro() {
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for(int j = 0; j < tamanho_tabuleiro; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para mostrar o tabuleiro no ecrã
void mostrar_tabuleiro(bool mostrar_barcos = false) {
    // Cabeçalho com números das colunas
    cout << "    ";
    for (int j = 0; j < tamanho_tabuleiro; j++) {
        cout << j << "  ";
    }
    cout << endl;


    // Mostra cada linha do tabuleiro
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        cout << i << "| ";  // mostra o número da linha vertical
        for(int j = 0; j < tamanho_tabuleiro; j++) {
            // símbolos visuais:
            if (tabuleiro[i][j] == 0) cout << "🌊 ";            // água
            else if (tabuleiro[i][j] == 1 && mostrar_barcos) cout << "⛵ ";  // barco visível
            else if (tabuleiro[i][j] == 1) cout << "🌊 ";       // barco escondido (ainda não atingido)
            else if (tabuleiro[i][j] == 2) cout << "💥 ";       // acerto
            else if (tabuleiro[i][j] == 3) cout << "❌ ";       // tiro na água
        }
        cout << endl;
    }
    cout << endl;
}

/* Função que verifica se é possível colocar um barco numa determinada posição.
   Ela garante que o barco não ultrapassa os limites do tabuleiro */
bool posicao_valida(int x, int y, int tamanho, bool horizontal) {
    if (horizontal) {
        // verifica se o barco cabe horizontalmente
        if (y + tamanho > tamanho_tabuleiro) return false;
        for (int i = 0; i < tamanho; i++) {  // nao pode ultrapassar as bordas
            if (tabuleiro[x][y + i] != 0) return false;  // já tem algo ali
        }
    } else {
        // verifica se o barco cabe verticalmente
        if (x + tamanho > tamanho_tabuleiro) return false;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y] != 0) return false;
        }
    }
    return true;
}

// Função que posiciona um barco no tabuleiro e registra suas informações
void colocar_barco(int x, int y, int tamanho, bool horizontal, int indice_barco) {
    frota[indice_barco].tamanho = tamanho;
    frota[indice_barco].horizontal = horizontal;
    frota[indice_barco].x = x;
    frota[indice_barco].y = y;
    frota[indice_barco].partes_atingidas = 0;

    // Marca as posições ocupadas pelo barco no tabuleiro
    if (horizontal) {
        for (int i = 0; i < tamanho; i++) { // Percorre cada célula do barco na horizontal.
            tabuleiro[x][y + i] = 1;  // 1 = barco
        }
    } else {
        for (int i = 0; i < tamanho; i++) { // // Percorre cada célula do barco na vertical.
            tabuleiro[x + i][y] = 1;
        }
    }
}

/* Função que cria automaticamente a frota inteira, posicionando todos os barcos de tamanhos diferentes. */
void criar_frota_automatica() {
    int barcos_por_tamanho[] = {1, 1, 2, 1, 5};  // quantidade de barcos por tamanho
    int tamanhos[] = {5, 4, 3, 2, 1};            // tamanhos correspondentes
    int indice_barco = 0;  // índice da frota

    // percorre cada tipo de barco
    for (int t = 0; t < 5; t++) {
        for (int b = 0; b < barcos_por_tamanho[t]; b++) {
            bool colocado = false;
            while (!colocado) {
                // escolhe uma posição e orientação aleatória no x e y.
                int x = rand() % tamanho_tabuleiro;
                int y = rand() % tamanho_tabuleiro;
                bool horizontal = rand() % 2 == 0; // 50% de chance de ser horizontal ou vertical.

                // se for possível colocar, faz isso
                if (posicao_valida(x, y, tamanhos[t], horizontal)) { // Chama a função para registrar o barco na frota.
                    colocar_barco(x, y, tamanhos[t], horizontal, indice_barco);
                    indice_barco++;
                    colocado = true;
                }
            }
        }
    }
}

// Função que processa um tiro do jogador
bool atirar(int x, int y) {
    if (tabuleiro[x][y] == 1) { // acertou um navio
        tabuleiro[x][y] = 2; // marca como acerto 💥
        
        // percorre todos os barcos para identificar qual foi atingido
        for (int i = 0; i < total_barcos; i++) {
            Barco& barco = frota[i];
            bool atingiu = false;
            
            if (barco.horizontal) {
    // Verifica se o tiro atingiu alguma parte do barco horizontal
    for (int j = 0; j < barco.tamanho; j++) {
        if (barco.x == x && barco.y + j == y) { // mesma linha, coluna dentro do barco
            barco.partes_atingidas++; // marca acerto
            atingiu = true;
            break;
        }
    }
} else {
    // Verifica se o tiro atingiu alguma parte do barco vertical
    for (int j = 0; j < barco.tamanho; j++) {
        if (barco.x + j == x && barco.y == y) { // mesma coluna, linha dentro do barco
            barco.partes_atingidas++; // marca acerto
            atingiu = true;
            break;
        }
    }
}
            
            // se o barco foi atingido, verifica se foi afundado
            if (atingiu) {
                if (barco.partes_atingidas == barco.tamanho) {
                    barcos_afundados++;
                    cout << "Voce afundou um navio de tamanho " << barco.tamanho << "!" << endl;
                } else {
                    cout << "Voce acertou um navio!" << endl;
                }
                break;
            }
        }
        return true;
    } else if (tabuleiro[x][y] == 0) { // tiro na água
        tabuleiro[x][y] = 3; // marca como ❌
        return false;
    }
    return false;
}

// Conta quantos barcos ainda não foram completamente afundados
int contar_barcos_restantes() {
    int restantes = 0;
    for (int i = 0; i < total_barcos; i++) {
        if (frota[i].partes_atingidas < frota[i].tamanho) {
            restantes++;
        }
    }
    return restantes;
}

// Mostra as estatísticas atuais do jogo
void mostrar_estatisticas() {
    cout << "=== ESTATISTICAS ===" << endl;
    cout << "Tentativas restantes: " << tentativas_restantes << endl;
    cout << "Barcos restantes: " << contar_barcos_restantes() << endl;
    cout << "Barcos afundados: " << barcos_afundados << "/" << total_barcos << endl;
    cout << "------------------------------" << endl << endl;
}

// Função principal do jogo
int main() {
    srand(time(NULL)); // inicializa o gerador de números aleatórios com base no tempo atual
    
    inicializar_tabuleiro(); // começa com tudo como água
    criar_frota_automatica(); // posiciona os barcos aleatoriamente

    // Mensagem inicial
    cout << "=== BATALHA NAVAL 67 ===" << endl;
    cout << "Tabuleiro: " << tamanho_tabuleiro << "x" << tamanho_tabuleiro << endl;
    cout << "Frota: 1 Porta-avioes (5), 1 Couracado (4), 2 Cruzadores (3), 1 Submarino (2), 5 Barcos pequenos (1)" << endl;
    cout << "Tentativas: " << tentativas_restantes << endl;
    cout << "Coordenadas: 0 a " << tamanho_tabuleiro-1 << endl;
    cout << "Simbolos: 🌊 = Agua, ❌ = Tiro na agua, 💥 = Acerto no navio" << endl;
    cout << "------------------------------" << endl << endl;

    int linha, coluna;

    // Loop principal do jogo
    while(tentativas_restantes > 0) {
        mostrar_estatisticas();  // mostra status atual
        mostrar_tabuleiro();     // mostra o tabuleiro (sem revelar barcos)

        // Lê coordenadas do jogador
        cout << "Digite as coordenadas (linha coluna): ";
        cin >> linha >> coluna;

        // Verifica se o jogador digitou coordenadas válidas
        if(linha < 0 || linha >= tamanho_tabuleiro || coluna < 0 || coluna >= tamanho_tabuleiro) {
            cout << "Coordenadas invalidas! Use valores entre 0 e " << tamanho_tabuleiro-1 << endl;
            continue;
        }

        // Evita tiros repetidos
        if(tabuleiro[linha][coluna] == 2 || tabuleiro[linha][coluna] == 3) {
            cout << "Voce ja atirou nesta posicao!" << endl;
            continue;
        }

        // Gasta uma tentativa
        tentativas_restantes--;

        // Processa o tiro
        if(atirar(linha, coluna)) {
            cout << "--- ACERTOU! ---" << endl;
        } else {
            cout << "--- AGUA! ---" << endl;
        }

        // Verifica se o jogador venceu
        if(contar_barcos_restantes() == 0) {
            cout << endl << "PARABENS! Venceste, afundaste toda a frota!" << endl;
            break;
        }

        // Verifica se acabou as tentativas
        if(tentativas_restantes == 0) {
            cout << endl << "FIM DE JOGO! Suas tentativas acabaram!" << endl;
            cout << "Barcos restantes: " << contar_barcos_restantes() << endl;
        }
    }

    // Mostra o tabuleiro final (com todos os barcos visíveis)
    cout << endl << "=== TABULEIRO FINAL ===" << endl;
    mostrar_tabuleiro(true);
    
    cout << "Obrigado por jogar Batalha Naval! GOOD BOY/GIRL!" << endl;

    return 0;
}