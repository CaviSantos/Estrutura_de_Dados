#include <iostream>
#include <string>
using namespace std;

//Escreva uma primeira implementação,
//ainda incompleta, de dicionário para
//chave "int" e valor "string" via tabela
//de dispersão. Essa primeira versão não 
//deve redimensionar a tabela, que deverá
//ter sempre o mesmo tamanho (>= 1), recebido
//como argumento no construtor.
//Utilize "h(c) = c % m" como função de dispersão,
//sendo "m" o tamanho da tabela (vetor), e resolva
//colisões através de encadeamento externo, usando lista encadeada.

class Dic{
  struct noh{
    int chave;
    string valor;
    noh *prox;
  };
  
  noh** tabela;
  int tamanho;
  
  //construtor
  Dic(){
    tamanho = 5;
    tabela = new noh* [tamanho];
      
    for(int i = 0; i < tamanho; i++){
        tabela[i]=nullptr;
    }
  }
  
  struct resultado{
    bool achado;
    string valor;
  };
  
  
  int hash_calc(int chave){
    return chave % tamanho;
  }
  
  resultado consultar(int chave){
      noh* cursor = tabela[hash_calc(chave)];
      resultado R;
      
      while(cursor->prox != nullptr){
          if(cursor->chave == chave){
            R.achado = true;
            R.valor = cursor->valor;
            return R;
          }
          
          cursor = cursor->prox;
      }
      R.achado = false;
      R.valor = " ";
      return R;
  }
  
  void inserir(int chave, string valor){
      //primeiro noh do indice da tabela.
      if(tabela[hash_calc(chave)]->prox == nullptr]){
        noh* novo = new noh {chave,valor,nullptr};
      
        tabela[hash_calc(chave)] = novo;
        noh *inicio;
        inicio = novo;
      }
      
      // caso já exista mais de um noh no indice da tabela.
      noh* novo = new noh {chave,valor,tabela[hash_calc(chave)]};
      tabela[hash_calc(chave)] = novo;
  }
  
  void inserir_se_novo(int chave, string valor){
      if(consultar(chave).achado == false){
          inserir(chave,valor);
      }
  }
  
  void remover(int chave){
      if(consultar(chave).achado){
        noh* cursor = tabela[hash_calc(chave)];
        
        if(cursor->chave == chave){
            tabela[hash_calc(chave)] = cursor->prox;
            
            delete cursor;
        }
      
        while(cursor->prox != nullptr){
            if(cursor->prox->chave == chave){
            noh* aux = cursor->prox;
            cursor = aux->prox;
            delete aux;  
            }
        }
    }
    return;
  }
  
  ~Dic(){
    for(int i = 0; i<tamanho;i++){
        noh* cursor = tabela[i];
        while(cursor != nullptr){
            noh* aux = cursor;
            
            cursor = cursor->prox;
            delete aux;
        }
    }
    delete[] tabela;
  }
};

int main() {
    
 // não precisa implementar.
 
    return 0;
}
