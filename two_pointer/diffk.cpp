#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;


int diffPossible(vector<int> &A, int B) {

    int n=A.size();
    for(int j=0;j<n;j++)
    {
        int i=j+1;
        int target=B+A[j];

        int st=j+1;
        int en=n-1;
        while(st<=en)
        {
            int mid=st+(en-st)/2;

            if(A[mid]==target && mid!=j)
            {
                return 1;
            }
            else if(A[mid]<target)
            {
                st++;
            }
            else if(A[mid]>target)
            {
                en--;
            }
        }
    }
    return 0;
}

int main()
{
    vector<int> A={1,3,5};
    int B=4;
    cout<<diffPossible(A,B);
}