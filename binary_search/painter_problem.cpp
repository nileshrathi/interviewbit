#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;
ll m=10000003;


ll painter_req(vector<int> &C, int maxelem)
{
    ll n=C.size();

    ll temp=0;
    ll nop=0;
    for(int i=0;i<n;i++)
    {
        temp=(temp+C[i])%m;

        if(temp>=maxelem)
        {
            nop++;
            temp=C[i];
        }
    }
    return nop;

}

int paint(int A, int B, vector<int> &C) {

    ll n=C.size();
    ll lo=*max_element(begin(C),end(C));

    ll hi=0;
    for(ll i=0;i<n;i++)
    {
        hi=(hi+C[i])%m;
    }

    while(lo<hi)
    {
        ll mid=(lo+hi)%m/2;

        ll nop=painter_req(C,mid);

        if(nop<=A)
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
        
    }

    return lo;
}

int main()
{
    int  A = 10;
    int B = 1;
    vector<int> C = {1, 8, 11, 3};
    cout<<paint(A,B,C);
    return 0;
}
