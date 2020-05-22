#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> searchRange(const vector<int> &A, int B) {
    
    int n=A.size();
    
    int lo=0;
    int hi=n-1;
    
    while(lo<hi)
    {
        int mid=lo+(hi-lo)/2;

        if(A[mid]>=B)
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
        
    }


    if(A[hi]!=B)
    {
        return vector<int> {-1,-1};
    }
    int start=hi;


    lo=0;
    hi=n-1;

    while(lo<hi)
    {
        int mid=lo+(hi-lo)/2;

        if(A[mid]<=B)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid;
        }
        
    }

    
    int end;

    if(lo==(n-1))
    {
        end=hi;
    }
    else
    {
        end=hi-1;
    }
    


    

    return vector<int> {start,end};

    // int st=hi,en=hi;

    // while(A[en]==A[st])
    // {
    //     en++;
    // }    
    // return vector<int> {st,en-1};
}

int main()
{
    // vector<int> A= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    vector<int> A={10};
    int B=10;
    vector<int> res =searchRange(A,B);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}