 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
int isValidSudoku(const vector<string> &A) {
    
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        unordered_set<char> row;
        for(int j=0;j<n;j++)
        {
            if( A[i][j]!='.' && row.find(A[i][j]!=row.end())
            {
                return 0;
            }
            else if(A[i][j]!='.' && A[i][j]>='0' && A[i][j]<='9')
            {
                row.insert(A[i][j]);
            }
            else if(A[i][j]!='.' && (A[i][j]<'0' || A[i][j]>'9'))
            {
                return -1;
            }
            
        }
    }
    
    // 
    
      for(int j=0;j<n;j++)
    {
        unordered_set<char> row;
        for(int i=0;i<n;i++)
        {
            if( A[i][j]!='.' && row.find(A[i][j]!=row.end())
            {
                return 0;
            }
            else if(A[i][j]!='.' && A[i][j]>='0' && A[i][j]<='9')
            {
                row.insert(A[i][j]);
            }
            else if(A[i][j]!='.' && (A[i][j]<'0' || A[i][j]>'9'))
            {
                return -1;
            }
            
        }
    }
    
    
    int si=0;
    int sj=0;
    
    for(si=0;si<3;si++)
    {
        for(sj=0;sj<3;sj++)
        {
            unordered_set<char> row;
            for(int i=3*si;i<(3*si+3);i++)
            {
                for(int i=3*si;i<(3*si+3);i++)
                {
                    if( A[i][j]!='.' && row.find(A[i][j]!=row.end())
                    {
                        return 0;
                    }
                    else if(A[i][j]!='.' && A[i][j]>='0' && A[i][j]<='9')
                    {
                        row.insert(A[i][j]);
                    }
                    else if(A[i][j]!='.' && (A[i][j]<'0' || A[i][j]>'9'))
                    {
                        return -1;
                    }
                }
            }
            
        }
    }
    
    return 1;
}
