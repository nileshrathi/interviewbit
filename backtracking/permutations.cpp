 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

void find(vector<vector<int> > &res,vector<int> curr,int index,vector<int> A)
{
    if(index==A.size()-1)
    {
        res.push_back(A);
    }
   
   for(int i=index;i<=A.size()-1;i++)
   {
       swap(A[i],A[index]);

       find(res,curr,index+1,A);

       swap(A[i],A[index]);

   }

   return ;
    
}

vector<vector<int> > permute(vector<int> &A) {
    vector<vector<int> > res;
    vector<int> curr;
    int index=0;
    find(res,curr,index,A);
    return res;
}



int main()
{

    vector<int> A={1,2,3};
    vector<vector<int> > res=permute(A);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }
    
    // cout<<trap(A);
    return 0;
}