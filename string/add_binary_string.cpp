#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string addRem(string R, int carry)
{

    int i=R.size()-1;
    string rem="";
    while(i>=0)
    {
        int cbit=R[i]-'0';
        int sum=cbit+carry;
        int bsum=sum%2;
        if(sum>=2)
            carry=1;
        else
            carry=0;
        rem=to_string(bsum)+rem;
        i--;
    }
    if(carry==1)
    {
        rem="1"+rem;
    }
    return rem;

}


string addBinary(string A, string B) {

    int m=A.length();
    int n=B.length();
    if (m>n)
    {
        return addBinary(B,A);
    }

    int i=m-1;
    int j=n-1;

    string ans="";
    int carry=0;
    while(i>=0 && j>=0)
    {
        int abit=A[i]-'0';
        int bbit=B[j]-'0';
        int sum=(abit+bbit+carry);
        int bsum=sum%2;
        if(sum>=2)
            carry=1;
        else
            carry=0;
        ans=to_string(bsum)+ans;
        i--;
        j--;
    }
   // cout<<i<<"\n";

   if(i==j)
   {
       if(carry==1)
            ans=to_string(carry)+ans;
       return ans;
   }
    string rem="";
    if(j>=0)
    {
        rem=addRem(B.substr(0,j+1),carry);
    }
    ans=rem+ans;

 return ans;   
}

int main()
{
    cout<<addBinary("11","111");
}
