 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

vector<int> findSubstring(string A, const vector<string> &B) {
    if(A.size()==0 || B.size()==0)
    {
        return vector<int> {};
    }
    unordered_map<string,int> us;
    unordered_map<string,int> temp;
    for(int i=0;i<B.size();i++)
    {
        us[B[i]]++;
    }
    int l=B[0].length();
    vector<int> ans;

    for(int i=0;i<A.length()-l+1;i++)
    {
        string s=A.substr(i,l);
        bool found=0;
        

        if(us.find(s)!=us.end())
        {
            int i2=i;
            while(i2<A.length() && us.find(s)!=us.end() && us[s]>temp[s])
            {
                temp[s]++;
                i2=i2+l;
                s=A.substr(i2,l);
            }
            if(temp==us)
            {
                ans.push_back(i);
                
            }
            temp.clear();
        }
        
    }
    return ans;

}

int main()
{
    string A="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> B={"aaa", "aaa", "aaa", "aaa", "aaa"}; 
    vector<int> ans=findSubstring(A,B);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
    }
}
