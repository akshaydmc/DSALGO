void func( vector<int>f, int &s)
{
    for(int i=0;i<26;i++)
    {
        if(f[i]!=0)
        {f[i]--;
        s++;
        func( f, s);
        f[i]++;}
    }
}

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int s=0;
        vector<int> f(26,0);
        for(int i=0;i<tiles.size();i++)
        {
            f[tiles[i]-'A']++;
        }
        func( f, s);
        
        return s;
    }
};
