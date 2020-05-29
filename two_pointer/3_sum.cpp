#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll find_closest(vector<int> &A, ll target)
{
    ll ans=UINT_MAX;
    ll st=0;
    ll en=A.size()-1;
    ll l=st;
    ll r=en;
    ll diff=INT_MAX;
    while(st<en)
    {
        
        if(abs(A[st]+A[en]-target)<diff)
        {
            ans=A[st]+A[en];
            diff=abs(A[st]+A[en]-target);
        }

        if(A[st]+A[en]==target)
        {
            return target;
        }
        else if(A[st]+A[en]<target)
        {
            st++;
        }
        else if(A[st]+A[en]>target)
        {
            en--;
        }
        
        
    }
    return ans;
}

int threeSumClosest(vector<int> &A, int B) {

ll ans=INT_MAX;
ll n=A.size();
sort(A.begin(),A.end());
int diff=INT_MAX;
for(ll k=0;k<n-1;k++)
{
    ll first=A[k];
    A.erase(A.begin()+k);
    ll closest_sum=find_closest(A,B-first);
    A.insert(A.begin()+k,first);

    if(abs(closest_sum+first-B)<diff)
    {
        ans=closest_sum+first;
        diff=abs(closest_sum+first-B);
    }

}

return ans;

}


int main()
{
    vector<int> A={ 5, -2, -1, -10, 10};
    int B=5;

    cout<<threeSumClosest(A,B);

}