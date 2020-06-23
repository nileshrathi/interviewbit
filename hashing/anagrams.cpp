 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

vector<vector<int> > anagrams(const vector<string> &A) {
vector<string> temp(A.begin(),A.end());
int n=A.size();
map<string,vector<int> > m;
for(int i=0;i<n;i++)
{
    sort(temp[i].begin(),temp[i].end());
    m[temp[i]].push_back(i+1);
}
vector<vector<int > >ans;
for(auto i=m.begin();i!=m.end();i++)
{
    ans.push_back(i->second);
}
return ans;

}
int main()
{
    const vector<string> A={"cat" ,"dog" ,"god", "tca"};
    vector<vector<int> >  res=anagrams(A);
        for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}