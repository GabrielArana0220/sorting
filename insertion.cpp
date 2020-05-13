#include<iostream>
using namespace std;

void insertion_sort(int lista[],int f)
{
    int iteraciones=0;
    for(int k=1; k<f; k++)
    {
        int temp = lista[k];
        int j= k-1;
        while(j>=0 && temp <= lista[j])
        {
            iteraciones++;
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = temp;
        if(j==k-1)
            iteraciones++;

    }
    cout << "comparaciones "<<iteraciones<<endl;
}

int main ()
{
    int lista[12] ={ 10,9,8,7,6,5,4,3,2,1,0,-1};
    int f=12;

    insertion_sort(lista,f);

    for(int i=0;i<f;i++)
    {
        cout <<lista[i]<<" ";
    }
}
