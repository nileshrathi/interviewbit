#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findMinXor(vector<int> &A) {

    sort(A.begin(),A.end());
    int res=INT_MAX;

    for(int i=0;i<A.size()-1;i++)
    {
            int temp=A[i]^A[i+1];
            res=min(temp,res);
    }
    return res;
}

int main()
{
    vector<int> A={0, 2, 5, 7};
    cout<<findMinXor(A);
}

