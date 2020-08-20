#include<iostream>
using namespace std;

int Partition(int arr[], int spos, int epos){
    int i=spos,j=spos-1,k=spos;
    int piv=arr[epos];
    for(;i<epos;i++){
        if(arr[i]<=piv){
            swap(arr[i],arr[j+1]);
            j++;
        }
    }
    swap(arr[j+1],arr[epos]);
    return j+1;
}

void quick_sort(int arr[], int spos, int epos){
    if(spos>=epos) return;
    int p=Partition(arr,spos,epos);
    quick_sort(arr,spos,p-1);
    quick_sort(arr,p+1,epos);
}

int main(){
    int n; cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    quick_sort(arr,0,n-1);
    cout<<"Sorted array:";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
