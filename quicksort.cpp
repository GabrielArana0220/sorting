#include <iostream>
using namespace std;

void invertir(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}

int partition (int l[], int low, int high)
{
    int pivot = l[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (l[j] < pivot)
        {
            i++;
            invertir(l[i], l[j]);
        }
    }
    invertir(l[i + 1], l[high]);
    return (i + 1);
}

void quickSort(int l[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(l, low, high);
        quickSort(l, low, pi - 1);
        quickSort(l, pi + 1, high);
    }
}

void printArray(int l[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << l[i] << " ";
    cout << endl;
}


int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "ordenado "<<endl;
    printArray(arr, n);
    return 0;
}
