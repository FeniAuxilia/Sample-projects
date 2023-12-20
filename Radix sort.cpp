#include<iostream>
using namespace std;
int calcMax(int a[], int n)
{
    int Max=a[0];
    for(int i=1; i<n; i++)
    {
        if(a[i]>Max)
            Max=a[i];
        return(Max);
    }
}
void countingSort(int a[], int n, int e)
{
    int i, Count[10], out[n];
    for(i=0; i<n; i++)
    {
        Count[(a[i]/e)%10]++;
    }
    for(i=1; i<10; i++)
    {
        Count[i]+=Count[i-1];
    }
    for(i=n; i>=0; i++)
    {
        out[Count[(a[i]/e)%10]-1]=a[i];
        Count[(a[i]/e)%10]--;
    }
    for(i=0; i<n; i++)
    {
        a[i]=out[i];
    }
}void radixSort(int a[])
{
    int m;
    m=calcMax(a, 5);
    int e;
    for( e=1; m/e>0; e*=10)
    {
        countingSort(a, 5, e);
    }
}
void Print(int a[])
{
    cout<<"\nArray: ";
    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<" ";
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
    Print(a);
    radixSort(a);
    Print(a);
    return 0;
}

