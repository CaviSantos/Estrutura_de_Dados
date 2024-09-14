#include <iostream>
using namespace std;

// Classe Matriz
class Matriz {
    int linhas;
    int colunas;
    double **M;
    
public:
    
    // Construtor
    Matriz(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
        M = new double* [linhas];
        for (int l = 0; l < linhas; l++) {
            M[l] = new double[colunas];
        }
    }
    
    // Destrutor
    ~Matriz() {
        for (int l = 0; l < linhas; l++) {
            delete[] M[l];
        }
        delete[] M;
    }
    
    // Sobrecarga do operador () para acessar elementos
    double& operator() (int i, int j) {
        return M[i][j];
    }
    
    int get_linhas() const {
        return linhas;
    }
    
    int get_colunas() const {
        return colunas;
    }
};

// Verifica se duas matrizes têm as mesmas dimensões
bool verifica_Dimensao(const Matriz &M1, const Matriz &M2) {
    return (M1.get_linhas() == M2.get_linhas() && M1.get_colunas() == M2.get_colunas());
}

// Função para somar duas matrizes
Matriz soma(const Matriz &M1, const Matriz &M2) {
    if (!verifica_Dimensao(M1, M2)) {
        cout << "Dimensões diferentes, retornando matriz nula." << endl;
        return Matriz(0, 0);  // Retorna uma matriz nula
    }

    int linhas = M1.get_linhas();
    int colunas = M1.get_colunas();
    Matriz somar(linhas, colunas);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            somar(i, j) = M1(i, j) + M2(i, j);
        }
    }
    return somar;
}

int main() {
    int l, c;
    
    // Entrada para a Matriz 1
    cout << "Matriz 1\n";
    cout << "Insira a quantidade de linhas da matriz 1: ";
    cin >> l;
    cout << "Insira a quantidade de colunas da matriz 1: ";
    cin >> c;
    
    Matriz M1(l, c);
    cout << "Insira os elementos da matriz 1:\n";
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> M1(i, j);
        }
    }
    
    int a, b;
    
    // Entrada para a Matriz 2
    cout << "\nMatriz 2\n";
    cout << "Insira a quantidade de linhas da matriz 2: ";
    cin >> a;
    cout << "Insira a quantidade de colunas da matriz 2: ";
    cin >> b;
    
    Matriz M2(a, b);
    cout << "Insira os elementos da matriz 2:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> M2(i, j);
        }
    }
    
    // Verifica se as dimensões são compatíveis para soma
    if (verifica_Dimensao(M1, M2)) {
        Matriz Resultado = soma(M1, M2);

        // Imprime a matriz resultante
        cout << "\nResultado da soma das matrizes:\n";
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                cout << Resultado(i, j) << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Não foi possível somar as matrizes, pois têm dimensões diferentes." << endl;
    }

    return 0;
}
