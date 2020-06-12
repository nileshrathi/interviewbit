 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

bool find(vector<vector<int> > &A, vector<vector<int> > &sol, int x, int y, int n)
{
    if(x==n-1 && y==n-1 && A[x][y]==1)
    {   sol[x][y]=1;
        return true;
    }
   // cout<<"hello\n";
        
    if(A[x][y]==1)
    {
        
        sol[x][y]=1;
        //down
        if(x+1<n && A[x+1][y]==1)
        {
            bool ans=find(A,sol,x+1,y,n);
            if(ans==true)
                return true;
        }
        //right
        if(y+1<n && A[x][y+1]==1)
        {
            bool ans=find(A,sol,x,y+1,n);
            if(ans==true)
                return true;
        }
        sol[x][y]=0;
        return false;
    }

    return false;
    
}

vector<vector<int> > solve(vector<vector<int> > &A) {

    vector<vector<int> > sol;
    int n=A.size();
    if(n<=0)
    {

        return vector<vector<int> > {};
    }
    sol.resize(n);
    for(int i=0;i<n;i++)
    {
        sol[i].resize(n,0);
    }

    bool ans=find(A,sol,0,0,n);

    if(ans==true)
     return sol;
    else
        return vector<vector<int> > {};
}

int main()
{
    vector<vector<int> > A ={{1, 1, 1}, 
                            {1, 0, 1},
                            {0, 0, 1}};

    vector<vector<int> > res=solve(A);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }


}