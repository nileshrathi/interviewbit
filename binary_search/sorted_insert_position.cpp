#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int lo=0;
    int hi=n-1;
    bool less=false;
    int mid=0;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;

        if(A[mid]==B)
        {
            return mid;
        }
        else if(A[mid]<B)
        {
            lo=mid+1;
            less=true;
        }
        else
        {
            hi=mid-1;
            less=false;
        }
    }

    if(less)
    {
        return mid+1;
    }
    else
    {
        return mid;
    }
    
    
}

int main()
{
    vector<int> A={1,3};
    int B=2;
    cout<<searchInsert(A,B);
}