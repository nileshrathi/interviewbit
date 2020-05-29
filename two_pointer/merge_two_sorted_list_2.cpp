#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;



void merge(vector<int> &A, vector<int> &B) {

    int m=A.size();
    int n=B.size();
    A.resize(m+n);

    int i=m-1;
    int j=n-1;
    int curr=m+n-1;

    while(i>=0 && j>=0)
    {
        if(A[i]<B[j])
        {
            A[curr]=B[j];
            j--;
        }
        else
        {
            A[curr]=A[i];
            i--;
        }
        curr--;
    }

    while(j>=0)
    {
        A[curr]=B[j];
        curr--;
        j--;
    }


}

int main()
{
    vector<int> A={1,5,7};
    vector<int> B={6,9};
    merge(A,B);

    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }
}