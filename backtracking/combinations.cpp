 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

void find(int n,int k, vector<vector<int> > &res,vector<int> &curr,int index)
{
    if(curr.size()==k)
    {
        res.push_back(curr);
        
    }
        
    
    for(int i=index;i<=n;i++)
    {
        curr.push_back(index);
        find(n,k,res,curr,i+1);
        curr.pop_back();
    }
    return;
}

vector<vector<int> > combine(int A, int B) {
    vector<vector<int> > res;
    vector<int> curr;
    find(A,B,res,curr,1);
    return res;
}


int main()
{
    vector<int> A={1,2,3};
    vector<vector<int> > res=combine(2,1);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }
    
    // cout<<trap(A);
    return 0;
}