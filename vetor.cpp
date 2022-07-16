#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

class MeuVetorFavorito
{

public:
    MeuVetorFavorito(int tam);
    ~MeuVetorFavorito();
    bool add(int valor);
    bool rem(int pos);
    int index(int pos);
    int buscar(int valor);
    void ordenar();
private:

    int *vetor;
    int tam;
    int posA;

};
MeuVetorFavorito::MeuVetorFavorito(int tam){
    this->tam = tam;
    this->vetor = (int*)malloc(sizeof(int)*tam);
};
MeuVetorFavorito::~MeuVetorFavorito(){
    free(this->vetor);
};
bool MeuVetorFavorito::add(int valor)
{
    if(this->posA<this->tam){
        this->vetor[this->posA++]=valor;
        return true;
    }
    return false;
}
bool MeuVetorFavorito::rem(int pos){
    int i, j;
    int vet[this->tam];

    if(pos>this->tam)
        return false;

    for(i = 0; i<this->tam; i++){
        vet[i] = this->vetor[i];
    }

    for(i = 0, j = 0; j<(this->tam-1); i++, j++){
        if(i!=pos){
            this->vetor[j] = vet[i];
        }
        else{
            j--;
        }
    }

    return true;
}
int MeuVetorFavorito::index(int pos){
    if (pos>=0 && pos<this->tam){
        return this->vetor[pos];
    }
}
int MeuVetorFavorito::buscar(int valor){
    int i;
    for(i = 0;i<this->tam;i++){
        if(valor == vetor[i]){
            return valor;
        }
    }
    return -1;
}
void MeuVetorFavorito::ordenar(){
    int n = sizeof(this->vetor)/sizeof(this->vetor[0]);
    sort(this->vetor, this->vetor + n);
}

int main()
{
    MeuVetorFavorito vetor(20);

    if(!(vetor.add(45)))
    {
        cout<<"Erro ao adicionar"<<endl;
    }
    vetor.add(2);
    vetor.ordenar();
    cout << vetor.index(0) << endl;
    cout << vetor.rem(0) << endl;
    cout << vetor.index(0) << endl;

    return 0;
}
