#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int isPalindrome(int A) {
    
    string reverseint;
    
    int x=A;
    
    int temp=10;
    while(x>0)
    {
        int rem=x%10;
        reverseint=reverseint+to_string(rem);
        x=x/10;
    }

    string orig=to_string(A);
    for(int i=0;i<orig.length();i++)
    {
        if(orig[i]!=reverseint[i])
            return 0;
    }
    return 1;
   // cout<<stoi(reverseint)<<" ";
    
}

int main()
{
    cout<<isPalindrome(121)<<"\n";
    return 0;
}
