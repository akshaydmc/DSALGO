#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    int currSum = 0,finSum = INT_MIN;
    for(int i=0;i<N;i++){
        currSum += v[i];
        currSum = max(currSum,0);
        finSum = max(finSum,currSum);
    }
    //If the input contains all negative numbers, the sum of subarray will be zero, so return the max element among the negative numbers.
    if(finSum==0){
        cout<<*max_element(v.begin(),v.end())<<endl;
    }else{
        cout<<finSum<<endl;
    }
}