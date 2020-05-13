#include<iostream>
using namespace std;
void invertir(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *l, int t) {
   for(int i = 0; i<t; i++)
      cout << l[i] << " ";
   cout << endl;
}
void merge(int *l, int p, int m, int r) {
   int i, j, k, nl, nr;

   nl = m-p+1; nr = r-m;
   int la[nl], ra[nr];

   for(i = 0; i<nl; i++)
      la[i] = l[p+i];
   for(j = 0; j<nr; j++)
      ra[j] = l[m+1+j];
   i = 0; j = 0; k = p;
   while(i < nl && j<nr) {
      if(la[i] <= ra[j]) {
         l[k] = la[i];
         i++;
      }else{
         l[k] = ra[j];
         j++;
      }
      k++;
   }
   while(i<nl) {
      l[k] = la[i];
      i++; k++;
   }
   while(j<nr) {
      l[k] = ra[j];
      j++; k++;
   }
}
void mergeSort(int *a, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      mergeSort(a, l, m);
      mergeSort(a, m+1, r);
      merge(a, l, m, r);
   }
}
int main() {
   int n;
   cout << "ingresa numero de elementos ";
   cin >> n;
   int arr[n];
   cout << "elementos" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "lista ";
   display(arr, n);
   mergeSort(arr, 0, n-1);
   cout << "lista ordenada ";
   display(arr, n);
}
