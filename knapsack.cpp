#include<bits/stdc++.h>

using namespace std;

int max(int a, int b);
int knapSack(int peso, int peso_valores[], int val[], int n);

int main(int argc, char ** argv){

  int aleatorio = rand() % 2;
  int n;
  int opcao;

  cout << "Digite 1 para uma lista um mochila pronta e 2 para colocar os valores da mochila: " << endl;
  cin >> opcao;

  int val[] = {60, 100, 120};
  int peso_valores[] = {10, 20, 30};
  int  peso;

  if (opcao == 1){
    n = sizeof(val)/sizeof(val[0]);

    if (aleatorio == 1){
      peso = 70;
    }else if (aleatorio == 2){
      peso = 60;
    }else{
      peso = 50;
    }
    cout << "Se o peso maximo for " << peso << " maior valor possivel é ";
    cout << knapSack(peso, peso_valores, val, n) << endl;
  }else{
    int  num;
    cout << "A quantidade de itens: ";
    cin >> num;

    int val2[num-1];
    int peso_valores2[num-1];
    n = sizeof(val2)/sizeof(val2[0]);

    cout << "Digite os itens seguidos de espaço: ";
    for (int i = 0; i < num ; i++){
      cin >> val2[i];
    }

    cout << "Digite os pesos dos itens seguidos de espaço: ";

    for (int i = 0; i < num ; i++){
      cin >> peso_valores2[i  ];
    }

    int n = sizeof(val2)/sizeof(val2[0]);

    cout << "Digite o peso que a mochila suporta";
    cin >> peso ;

    cout << "Se o Peso permitido fo " << peso << " maior valor possivel é ";
    cout << knapSack(peso, peso_valores2, val2, n) << endl;

  }

  return 0;
}

int max(int a, int b){
  return (a > b)? a : b;
}

int knapSack(int peso, int peso_valores[], int val[], int n){
  // Retorna o maior valor que cabe na mochila
  if (n == 0 || peso == 0)
    return 0;

  if (peso_valores[n-1] > peso)
    return knapSack(peso, peso_valores, val, n-1);
  else
    return  max( val[n-1] + knapSack(peso-peso_valores[n-1], peso_valores, val, n-1), knapSack(peso, peso_valores, val, n-1));

}