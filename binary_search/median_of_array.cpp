#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    if(A.size()>B.size())
    {
        return findMedianSortedArrays(B,A);

    }

   int x=A.size();
   int y=B.size();

   int lo=0;
   int hi=x;

   while(lo<=hi)
   {
       int partx=(lo+hi)/2;
       int party=(x+y+1)/2 -partx;


       int maxLeftx;
       int minrightx;
       int maxLefty;
       int minrighty;

       if(partx==0)
            maxLeftx=INT_MIN;
        else
            maxLeftx=A[partx-1];
    
        if(partx==x)
            minrightx=INT_MAX;
        else
            minrightx=A[partx];

        
        if(party==0)
            maxLefty=INT_MIN;
        else
            maxLefty=B[party-1];
    
        if(party==y)
            minrighty=INT_MAX;
        else
            minrighty=B[party];

        

        if(maxLeftx<=minrighty && maxLefty<=minrightx)
        {
            if((x+y)%2==0)
            {
                return double(max(maxLeftx,maxLefty)+min(minrightx,minrighty))/2.0;
            }
            else
            {
                return max(maxLeftx,maxLefty);
            }
            
        }
        else
        {
            if(maxLeftx>minrighty)
                {
                    hi=partx-1;
                }
            else
            {
                /* code */
                lo=partx+1;
            }
            
        }
        
            

   }     

}

int main()
{
    vector<int> A={1,4,5};
    vector<int > B={2,3};
    cout<<findMedianSortedArrays(A,B);
}