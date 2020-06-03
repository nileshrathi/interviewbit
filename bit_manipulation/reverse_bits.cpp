#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


unsigned int reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A==0)
        return 0;
    
    int ans=0;
    while(A>0)
    {
       // cout<<A<<"haha";
        ans=ans<<1;
        if(A&1)
        {
            ans=ans^1;
        }
        
        A=A>>1;
    }
        
    return ans;
}

int main()
{
    cout<<reverse(3);
}