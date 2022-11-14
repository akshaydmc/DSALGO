//print set bits from 1 to n in o(n)
#include<bits/stdc++.h>
using namespace std;

int main(){

	vector<int>v;
	v.push_back(0); //base case
	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		if(i&1){ // if i is odd number
			v.push_back(v[i/2]+1);
		}
		else
			v.push_back(v[i/2]);
	}


	for(int i=1;i<=n;++i)
		cout<<v[i]<<" ";
	cout<<endl;
}