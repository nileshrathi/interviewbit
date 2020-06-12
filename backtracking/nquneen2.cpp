 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

bool isSafe(int row, int column,vector<pair<int,int> > prevqueens)
{
    
   if(prevqueens.size()==0)
        return true;

    for(int i=0;i<prevqueens.size();i++)
    {
        int prow=prevqueens[i].first;
        int pcol=prevqueens[i].second;

        
        //same row
        if(prow==row && pcol!=column)
            return false;

        
        //same col
        if(pcol==column && prow!=row)
            return false;
        
        if( prow!=row && pcol!=column && (prow+pcol)==(row+column))
            return false;
        
        if( prow!=row && pcol!=column && (prow-pcol)==(row-column))
            return false;
    }

    // cout<<"hehe\n";
   

    return true;
}

void find(vector<vector<string> > &res,vector<string> curr,int row,int column,int n, vector<pair<int,int> > prevqueens)
{
    // cout<<"printing board\n";
    
    // for(int i=0;i<curr.size();i++)
    // {
    //     cout<<curr[i]<<"\n";
    // }

    if(row==n)
        {
            res.push_back(curr);
            curr.resize(0);
            prevqueens.resize(0);
            return ;
        }

    
    for(int i=0;i<n;i++)
    {
        if(isSafe(row,i,prevqueens))
        {
            curr[row][i]='Q';
            prevqueens.push_back(make_pair(row,i));
            find(res,curr,row+1,column,n,prevqueens);
            curr[row][i]='.';
            prevqueens.pop_back();

        }
    }

}


vector<vector<string> > solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<string> >res;
    vector<string> curr;
    vector<pair<int,int> > prevqueens;
    int row=0;
    int column=0;

    curr.resize(A);
        for(int j=0;j<A;j++)
        {
            curr[j].resize(A);
        }

        for(int i=0;i<A;i++)
        {
            for(int j=0;j<A;j++)
            {
                curr[i][j]='.';
            }
        }
    find(res,curr,row,column,A,prevqueens);

    return res;
}

int main()
{
    int n=4;
    vector<vector<string> > res=solveNQueens(n);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<"\n";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
