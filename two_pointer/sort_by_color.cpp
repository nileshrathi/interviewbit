#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

void sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int i=0;
    int pos=0;

    while(i<n)
    {
        if(A[i]==0)
        {
            swap(A[i],A[pos]);
            pos++;
        }
        i++;
    }

    i=pos;
    while(i<n)
    {
        if(A[i]==1)
        {
            swap(A[i],A[pos]);
            pos++;
        }
        i++;
    }

    i=pos;
    while(i<n)
    {
        if(A[i]==2)
        {
            swap(A[i],A[pos]);
            pos++;
        }
        i++;
    }


    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }

}

int main()
{
    vector<int> A={0,1,2,0,1,2};
    sortColors(A);
}