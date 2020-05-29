#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // all three elemts need to be cose to one another to reduce the diffrence

    int p=A.size();
    int q=B.size();
    int r=C.size();
    int i=0,j=0,k=0;

    int diff=INT_MAX;
    while(i<p && j<q && k<r)
    {
        int minelem=min(A[i],min(B[j],C[k]));
        int maxelem=max(A[i],max(B[j],C[k]));

        if(abs(maxelem-minelem)<diff)
        {
            diff=abs(maxelem-minelem);
        }

        if(minelem==A[i])
            i++;
        else if(minelem==B[j])
            j++;
        else
            k++;
    }
    return diff;
}


int main()
{
    vector<int> A={1,4,10};
    vector<int> B={2,15,20};
    vector<int> C={10,12};   
    cout<<minimize(A,B,C);
    return 0;
}