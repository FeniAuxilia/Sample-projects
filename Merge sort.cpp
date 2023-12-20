#include<iostream>
using namespace std;
void merge_(int a[], int p, int q, int r)
{
    int n1, n2, L[n1], R[n2];
    n1=q-p+1;
    n2=r-q;
    for (int i=0; i<n1; i++)
        L[i]=a[p+i];
    for (int j=0; j<n2; j++)
        R[j]=a[q+1+j];
    int i, j, k;
    i=0;
    j=0;
    k=p;
    while(i<n1&&j<n2)
    {
        if (L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(i<n2)
    {
        a[k]=R[i];
        j++;
        k++;

    }
}
void mergeSort(int arr[], int l, int r)
{
  if (l<r)
  {
    int m=l+(r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge_(arr, l, m, r);
  }
}
void printArray(int arr[], int size_)
{
  for (int i=0; i<size_; i++)
  {
      cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main()
{
    int a[5];
    for(int i=0; i<5; i++)
    {
        cout<<"\nEnter the element: ";
        cin>>a[i];
    }
    int size_=sizeof(a)/sizeof(a[0]);
    mergeSort(a, 0, size_-1);
    cout<<"\nSorted array: ";
    printArray(a, size_);
    return 0;
}
