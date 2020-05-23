#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


struct divison
{
    int remainder;
    string divident;
};

divison divide_by_2(string A)
{
   // A.erase(0, min(A.find_first_not_of('0'), A.size()-1));
    divison d;
    d.divident="";
    d.remainder=0;
    int n=A.length();
    int i=0;
    int prev=0;
    string divi="";
    int div;
    int rem;
    while(i<n)
    {
        int curr= (prev*10)+A[i]-'0';
        
        div=curr/2;
        rem=curr%2;
        prev=rem;
        divi=divi+to_string(div);
        i++;
    }

    d.remainder=rem;
    d.divident=divi;
        if(n==0)
            d.divident="";
    return d;

}


int power(string A)
{
   // A.erase(0, min(A.find_first_not_of('0'), A.size()-1));
    if(A=="0")
        return 0;
 
 while (A.length()!=1 &&  (A[A.length()-1]-'0')%2==0)
 {
     divison d=divide_by_2(A);
     cout<<d.divident<<" "<<d.remainder<<"\n";
     if(d.remainder!=0)
        return 0;
    (d.divident).erase(0, min((d.divident).find_first_not_of('0'), (d.divident).size()-1));
    A=d.divident;
    if(A=="0")
     
        return 0;
 }



 if(A=="2" ||A=="4"||A=="8")
    return 1;

    return 0;
 

}

int main()
{
    ll x=INT_MAX;
    x++;
    int d= power("00000000000000000000320");
    cout<<d;

    
    return 0;
}