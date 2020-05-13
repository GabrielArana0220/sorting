#include<iostream>
using namespace std;

int maximo(int l[], int n)
{
    int mx = l[0];
    for (int i = 1; i < n; i++)
        if (l[i] > mx)
            mx = l[i];
    return mx;
}

void countSort(int l[], int n, int e)
{
    int salida[n];
    int i;
    int contado[10] = {0};

    for (i = 0; i < n; i++)
        contado[ (l[i]/e)%10 ]++;

    for (i = 1; i < 10; i++)
        contado[i] += contado[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        salida[contado[(l[i]/e)%10]-1] = l[i];
        contado[(l[i]/e)%10]--;
    }

    for (i = 0; i < n; i++)
        l[i] = salida[i];
}

void radixsort(int l[], int n)
{
    int m = maximo(l, n);

    for (int e = 1; m/e > 0; e *= 10)
        countSort(l, n, e);
}

void print(int l[], int n)
{
    for (int i = 0; i < n; i++)
        cout << l[i] << " ";
}

int main()
{
    int l[8] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
    radixsort(l, n);
    print(l, n);
    return 0;
}
