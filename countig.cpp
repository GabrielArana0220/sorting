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

void Counting_Sort(int A[],int B[],int n,int k)
{
	int C[k];
	for(int i=0;i<k+1;i++)
	{

		C[i]=0;
	}
	for(int j=1;j<=n;j++)
	{
		C[A[j]]++;
	}
	for(int i=1;i<=k;i++)
	{
		C[i]+=C[i-1];
	}
	for(int j=n;j>=1;j--)
	{
		B[C[A[j]]]=A[j];

		C[A[j]]=C[A[j]]-1;
	}
}
int main()
{

    int A[8] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
	int B[n];
	int k=maximo(A,n);
	Counting_Sort(A,B,n,k);

	for(int i=1;i<=n;i++)
	{
		cout<<B[i]<<" ";
	}

	cout<<endl;
	return 0;
}
