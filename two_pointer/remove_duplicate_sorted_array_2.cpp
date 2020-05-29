#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n=A.size();
    int i=0;
    int ans=0;
    while(i<A.size())
    {
        //cout<<i<<" "<<A.size()<<"\n";
        int en=i;
        int count=0;    
        while(A[i]==A[en] && en<A.size())
        {
            en++;
            count++;
        }
        if(count>2)
        {
            ans++;
            
           // cout<<i+2<<" "<<count<<"\n";
            A.erase(A.begin()+i+2,A.begin()+i+count);

            // for(int j=0;j<A.size();j++)
            // {
            //     cout<<A[j]<<" ";
            // }
            // cout<<"\n";
            i=i+2;
            continue;
        }
        i++;
    }
    
    return A.size();
    
}

int main()
{
    vector<int> A={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    //    vector<int> A={1,1,1,2};
    cout<<removeDuplicates(A);
}
