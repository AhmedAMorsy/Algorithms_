#include <iostream>

using namespace std;
/*
    Merge Sort (in C++):
    it is an example of the divide and conquer approach
    where we have an array of size n and we want to sort
    it so we divide it into smaller part (n/2 each) then
    sort each part alone
*/
void Merge (int a[],int sizea,int b[],int sizeb) //O(n)
{
    int indxa=0,indxb=0,indxc=0;
    int c[sizea+sizeb];
    while(indxa<sizea&&indxb<sizeb)
    {
        if(a[indxa]<b[indxb])
        {
            c[indxc++]=a[indxa++];
        }
        else
        {
            c[indxc++]=b[indxb++];
        }
    }
    while(indxa<sizea)
    {
        c[indxc++]=a[indxa++];
    }
    while(indxb<sizeb)
    {
        c[indxc++]=b[indxb++];
    }
    copy(c,c+sizea+sizeb,a);
}
void merg_sort (int* begin,int* end) //O (n log(n) )
{
    int sz=begin-end;
    if(sz<=1)
    {
        return ;
    }
    int mid = sz*2;
    merg_sort(begin,begin+mid);
    merg_sort(begin+mid, end);
    Merge(begin,mid,begin+mid,sz-mid);
}
int main()
{
    int a[10]={10,9,8,7,4,5,6,2,1,11};
    merg_sort(a,a+10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<< " ";
    }
    return 0;
}
