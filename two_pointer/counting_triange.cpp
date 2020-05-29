#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

int nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    ll count=0;
    int n=A.size();
    for(int i=0;i<n-2;i++)
    {
        int k=i+2;
        for(int j=i+1;j<n;j++)
        {
           // int k=j+1;
            while(k<n && ll(A[i])+ll(A[j])>ll(A[k]))
            {
                k++;
            }
            
            if(k>j)
             count=(count+k-j-1)%mod;

        }
    }
    return count;

}

int main()
{
    vector<int> A={1, 1, 1, 2, 2};
    cout<<nTriang(A);

}