#include <iostream>

using namespace std;
int n;
/*
    Insertion sort (in C++) :-
    Take each number place it in its correct position in the array
    Ex: 5 4 3 2 1
        4 5 3 2 1
        4 3 2 1 5
    Number 5 is placed in its right position now we take the second
    number(4) to place it in its right position and so on
*/
void insertion_sort (int arr[]) //O(n^2)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}
void insertion_sort_book (int arr[]) //O(n^2)
{
    for(int j=1;j<n;j++)
    {
        int key = arr[j];
        int i=j-1;
        while(i>=0&&arr[i]<key)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}
int main()
{
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //insertion_sort(arr);
    insertion_sort_book(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
