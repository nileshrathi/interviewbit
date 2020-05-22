#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(string A) {
    int n=A.length();
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U'||A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u')
        {
            res.push_back(n-i);
        }

    }

    int sum=0;
    for(int i=0;i<res.size();i++)
    {
        sum=(sum+res[i])%10003;
    }
    return sum;
}

int main()
{
    cout<<solve("ABEC");
}