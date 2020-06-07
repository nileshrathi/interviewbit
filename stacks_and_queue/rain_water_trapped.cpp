 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

int trap(const vector<int> &A) {
 
    int n=A.size();
    vector<int>lmax(A.size());
    vector<int>rmax(A.size());

    lmax[0]=A[0];
    for(int i=1;i<A.size();i++)
    {
        lmax[i]=max(A[i],lmax[i-1]);
    }

    rmax[A.size()-1]=A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
    {
        rmax[i]=max(A[i],rmax[i+1]);
    }

    int capcity=0;
    
    for(int i=0;i<A.size();i++)
    {
        capcity=capcity+min(lmax[i],rmax[i])-A[i];
    }
    return capcity;

}

int main()
{
    vector<int> A={0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> res=slidingMaximum(A,3);

    // for(int i=0;i<res.size();i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    // cout<<"\n";
    cout<<trap(A);
    return 0;
}