#include <bits/stdc++.h> 
using namespace std;   
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
int part (int arr[], int l, int r)  
{  
    int pivot = arr[r];   
    int i = (l - 1);   
  
    for (int j = l; j <= r - 1; j++)  
    {    
        if (arr[j] < pivot)  
        {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[r]);  
    return (i + 1);  
}  

void quickSort(int arr[], int l, int r)  
{  
    if (l < r)  
    {  
        int pi = part(arr, l, r);   
        quickSort(arr, l, pi - 1);  
        quickSort(arr, pi + 1, r);  
    }  
}  
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
 
int main()  
{  
    int arr[] = {15, 64, 24, 5, 13, 18};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Array after sorting is: \n";  
    printArray(arr, n);  
    return 0;  
}  