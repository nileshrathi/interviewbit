#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int atoix(const string A) {

//remove all preceding white spaces;
    string s=A;
    while(s[0]==' ')
        s.erase(s.begin());

    bool negative=false;

    if(s[0]=='-' || s[0]== '+')
        {
            if(s[0]=='-')
                negative=true;
            s.erase(s.begin());
        }

    string res="";

    int i=0;
    while(s[i]>='0' && s[i]<='9' && i<s.length())
    {
        res=res+s[i];
        i++;
    }
   // cout<<"res "<<res<<"\n";
    ll ans=0;
    ll multilier=1;
    bool overflow=false;
    for(i=res.length()-1;i>=0;i--)
    {

        ll temp=(res[i]-'0')*multilier;
        ans=ans+temp;

        if(ans>INT_MAX)
            {
                overflow=true;
                break;
            }
        multilier*=10;
      //  cout<<"ans "<<res[i]<<"\n";
    }

    if(overflow)
    {
        if(negative)
            return INT_MIN;
        else
            return INT_MAX;
    }

    if(negative)
        return 0-ans;
    
        return ans;
}

int main()
{
    cout<<atoix("-88297 248252140B12 37239U4622733246I218 9 1303 44 A83793H3G2 1674443R591 4368 7 97");
}