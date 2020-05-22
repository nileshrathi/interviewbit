#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int searchMatrix(vector<vector<int> > &A, int B) {

    int m=A.size();
    int n=A[0].size();

    int lo=0,hi=m-1;

    //find the row number
    
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;

        if(A[mid][0]==B)
        {
            return 1;
        }
        else if(A[mid][0]<B)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
        
    }

    if(hi<0)
    {
        return 0;
    }
    int target_row=hi;
    


     lo=0,hi=n-1;

    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;

        if(A[target_row][mid]==B)
        {
            return 1;
        }
        else if(A[target_row][mid]<B)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
        
    }
    return -1;


}


int main()
{
  //  cout<<"yaha";
    vector< vector<int> > A= {
  {2, 3, 4, 4, 5, 5, 6},
  {10, 11, 12, 13, 13, 14, 15},
  {16, 25, 25, 26, 28, 28, 30},
  {30, 32, 33, 39, 39, 40, 41},
  {44, 44, 47, 49, 51, 55, 57},
  {57, 60, 60, 61, 61, 62, 63},
  {64, 65, 66, 67, 68, 71, 71},
  {75, 77, 77, 77, 78, 79, 80},
  {81, 83, 84, 85, 86, 88, 88},
  {91, 92, 93, 93, 95, 95, 98}
};
      int B=1;

    cout<<searchMatrix(A,B);
}