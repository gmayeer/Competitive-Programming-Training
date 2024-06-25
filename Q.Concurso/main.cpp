#include <iostream>
#define _MAX 100
using namespace std;

class Candidato{
  private:
    string nome;
    double nota;
  public:
    void getNome(){
      string nome;
      cin >> nome;
      setNome(nome);
    }
    void setNome(string nome){
      this->nome = nome;
    }
    string returnNome(){
      return this->nome;
    }
    
    void getNota(){
      double nota;
      cin >> nota;
      setNota(nota);
    }
    void setNota(double nota){
      this->nota = nota;
    }
    double returnNota(){
      return this->nota;
    }
};

int leTamanho(){
  int x;
  do{
    cin >> x;
  }while(x > _MAX);
  return x;
}

void leCandidatos(Candidato *candidate, int candidatesGroup){
  for(int i = 0; i < candidatesGroup; i++){
    candidate[i].getNome();
    candidate[i].getNota();
  }
}

double calculaMedia(Candidato *candidate, int candidatesGroup){
  double sum = 0;
  for(int i = 0; i < candidatesGroup; i++){
    sum += candidate[i].returnNota();
  }
  double average = sum / (double)candidatesGroup;
  return average;
}

void listAcima(Candidato *candidate, int candidatesGroup, double media){
  for(int i = 0; i < candidatesGroup; i++){
    if(candidate[i].returnNota() >= media){
      cout << candidate[i].returnNome() << " " << candidate[i].returnNota() << "\n";
      ;
    }
  }
}

int main(){
  //Recebendo tamanho do grupo de candidatos
  int candidatesGroup = leTamanho();
  //Criação do vetor de objetos  
  Candidato candidate[candidatesGroup];
  //Leitura do nome e nota de cada candidato
  leCandidatos(candidate, candidatesGroup);
  //Calculando média
  double media = calculaMedia(candidate, candidatesGroup);
  //Listando candidatos acima
  listAcima(candidate, candidatesGroup, media);
  return 0;
}
