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

bool find(vector<vector<string> > &res,vector<string> &curr,int row,int column,int n, vector<pair<int,int> > prevqueens)
{
    // cout<<"printing board\n";
    
    // for(int i=0;i<curr.size();i++)
    // {
    //     cout<<curr[i]<<"\n";
    // }

    if(column==n)
        return true;

    if(row==n)
    {
     //   cout<<"pushing back\n";
        res.push_back(curr);
        curr.resize(0);
        int first_queen_col=column+1;
        if(prevqueens.size()>0)
            first_queen_col=prevqueens[0].second;
       // cout<<first_queen_col<<"\n";
        prevqueens.resize(0);
        find(res,curr,0,first_queen_col+1,n,prevqueens);
        return true;
    }
        
    

    if(curr.size()==0)
    {
        
        curr.resize(n);
        for(int j=0;j<n;j++)
        {
            curr[j].resize(n);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        curr[row][i]='.';
    }

    int start=0;

    if(row==0)
        start=column;

    for(int col=start;col<n;col++)
    {
        

        // cout<<"row "<<row<<" col "<<col<<"\n";
         curr[row][col]='Q';
         prevqueens.push_back(make_pair(row,col));

        if(isSafe(row,col,prevqueens))
        {
           
             //cout<<"waha\n";
            if(find(res,curr,row+1,column,n,prevqueens))
                    return true;
        }

        curr[row][col]='.';
        prevqueens.pop_back();
    }

    return false;

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
    bool ans=find(res,curr,row,column,A,prevqueens);

    return res;
}

int main()
{
    int n=5;
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
