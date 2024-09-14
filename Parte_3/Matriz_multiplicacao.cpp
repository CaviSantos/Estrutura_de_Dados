#include <iostream>
using namespace std;

//Escreva um programa para ler 2 matrizes, multiplicá-las e imprimir o resultado.
//É necessário que o número de colunas da matriz esquerda 
//seja igual ao número de linhas da matriz direita.

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

// Função para multiplicar as duas matrizes.
Matriz multiplicacao(const Matriz &M1, const Matriz &M2) {
    if (M1.get_colunas() != M2.get_linhas()) {
        cout << "Dimensões incompatíveis para multiplicação." << endl;
        return Matriz(0, 0);  // Retorna uma matriz nula
    }

    int linhas = M1.get_linhas();
    int colunas = M2.get_colunas();
    int inner = M1.get_colunas();  // Número de colunas de M1 ou número de linhas de M2
    
    Matriz resultado(linhas, colunas);
    
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            resultado(l, c) = 0;
            for (int k = 0; k < inner; k++) {
                resultado(l, c) += M1(l, k) * M2(k, c);
            }
        }
    }
    return resultado;
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
    
    multiplicacao(M1,M2);
    
    //falta printar o resultado.

    return 0;
}
