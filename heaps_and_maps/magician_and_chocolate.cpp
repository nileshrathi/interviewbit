#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;
ll mod= 1000000007;

int nchoc(int A, vector<int> &B) {

    int n=B.size();
    priority_queue<int> pq;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        pq.push(B[i]);
    }
    while(A--)
    {
        int curr_max=pq.top();
        pq.pop();
        ans=(ans+curr_max)%mod;
        int new_choc=floor(double(curr_max)/2.0);
        pq.push(new_choc);
    }
    return ans;
}

int main()
{
    int A=5;
    vector<int> B={2, 4, 6, 8, 10};
    cout<<nchoc(A,B);
    return 0;
}