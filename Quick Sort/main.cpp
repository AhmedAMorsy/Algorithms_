#include <iostream>

using namespace std;
int partion (int a[],int l,int r) //O(n)
{
    int p=a[l];
    int i=l+1;
    for(int j=l+1;j<r;j++)
    {
        if(a[j]<p)
        {
            swap(a[j],a[i]);
            i++;
        }
    }
    swap(a[l],a[i-1]);
    return i-1;
}
void quick_sort(int arr[],int low ,int high)
{
    if(low<high)
    {
        int p=partion(arr,low,high);
        quick_sort(arr,low,p);
        quick_sort(arr,p+1,high);
    }
}
int main()
{
    int arr[8]={3,1,5,8,9,6,5,2};
    quick_sort(arr,0,8);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    return 0;
}
