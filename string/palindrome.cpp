
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isPalindrome(string A) {
    
     string s="";
    int n=A.length();
    for(int i=0;i<n;i++)
    {
        if('a'<=A[i] && A[i]<='z')
        {
            s+=A[i];
        }
        
        if('A'<=A[i] && A[i]<='Z')
        {
            
            s+=A[i]-'A'+'a';
        }
        
        if('0'<=A[i] && A[i]<='9')
        {
            // int inc=A[i]-'0';
            // char x='0' +inc;
            s+=A[i];
        }   
         
    }
    
    // cout<<s<<" d";
    
   
    // string x=s;
    // reverse(s.begin(),s.end());
    int x=s.length();
    for(int i=0;i<=x/2;i++)
    {   
       // cout<<s[i]<<" "<<s[s.length()-i-1]<<"\n";
        if(s[i]!=s[x-i-1])
            return 0;
        
    }
    return 1;
}

int main()
{
    cout<<isPalindrome("A man, a plan, a canal: Panama");
     cout<<isPalindrome("");
}