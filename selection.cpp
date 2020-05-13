#include<iostream>
using namespace std;
void invertir(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void mostrar(int *l, int t) {
   for(int i = 0; i<t; i++)
      cout << l[i] << " ";
   cout << endl;
}
void selectionSort(int *l, int n) {
   int minimo;
   int y=0;
   for(int i = 0; i<n-1; i++) {
      minimo = i;
      for(int j = i+1; j<n; j++)
      {
         y++;
         if(l[j] < l[minimo])
            minimo = j;}

      invertir(l[i], l[minimo]);
   }
   cout <<y<<endl;
}
int main() {

   int l[10]={4,23,342,341,123,342,54,2,6,2};

   cout << "lista original";
   mostrar(l, 10);
   selectionSort(l, 10);
   cout << "lista ordenada ";
   mostrar(l, 10);
}
