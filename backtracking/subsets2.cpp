 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

void findsubet(vector<int> &A,vector<vector<int> > &res,vector<int> &curr, int index)
{
    res.push_back(curr);
    for(int i=index;i<A.size();i++)
    {
        curr.push_back(A[i]);

        if(i==index || A[i]!=A[i-1])
            findsubet(A,res,curr,i+1);
        
        curr.pop_back();
    }
    return ;

}

vector<vector<int> > subsets(vector<int> &A) {

    sort(A.begin(),A.end());
    vector<vector<int> > res;
    vector<int> curr;
    findsubet(A,res,curr,0);
    return res;
    
}

int main()
{
    vector<int> A={1,2,2};
    vector<vector<int> > res=subsets(A);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
            cout<<"\n";
    }
    cout<<"\n";
    // cout<<trap(A);
    return 0;
}