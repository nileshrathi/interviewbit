#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string longestPalindrome(string A) {

    int n=A.length();

    vector<vector<bool> > table;
    table.resize(n);
    for(int i=0;i<n;i++)
        table[i].resize(n);

    int start=0;
    int maxlen=0;
    for(int i=0;i<n;i++)
    {
        table[i][i]=true;

        if(maxlen!=1)
        {
             start=i;
            maxlen=1;
        }
       
    }



    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        {
            table[i][i+1]=true;
            
            if(maxlen!=2)
            {
                start=i;
                maxlen=2;

            }
            
        }
    }


    for(int len=3;len<=n;len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
            int j=i+len-1;

            if(table[i+1][j-1]==true && (A[i]==A[j]))
            {
                table[i][j]=true;
                if(len>maxlen)
                {
                    start=i;
                    maxlen=len;
                }
                
            }
        }
    }

    return A.substr(start,maxlen);


}

int main()
{
    cout<<longestPalindrome("");
}


