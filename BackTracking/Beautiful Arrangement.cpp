int func(int n, int &s, vector<int>&v)
{
   
    if(n<=1)
    {
        return 1;
    }
    int p=0;
    for(int i=1;i<=n;i++)
    {
        if(n%v[i]==0 || v[i]%n==0)
       { 
        swap(v[i],v[n]);
        p+=func(n-1,p, v);
        swap(v[i],v[n]);}
    }
    return p;
}



class Solution {
public:
    int countArrangement(int N) {
       
        vector<int>v;
        
        for(int i=0;i<=N;i++)
        {
            v.push_back(i);
        }
        int s=0;
        
        s=func(N, s,v);
        return s;
    }
};
