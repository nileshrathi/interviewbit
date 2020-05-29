#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

int removeElement(vector<int> &A, int B) {
    
    int n=A.size();
   int i=0;
   int count=0;
   int pos=0;
   while(i<n)
   {
       if(A[i]!=B)
       {
           swap(A[i],A[pos]);
           pos++;
       }
       i++;
   }

//    for(int i=0;i<A.size();i++)
//     {
//         cout<<A[i]<<" ";
//     }
   return pos; 
}

int main(){
    vector<int> A={4, 1, 1, 2, 1, 3};
    int B=1;
    cout<<removeElement(A,B)<<"\n";
    // for(int i=0;i<A.size();i++)
    // {
    //     cout<<A[i]<<" ";
    // }
}
