#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
typedef long long int ll;
int reverse(int  A) {
    cout<<"hahoxsa";
    ll temp=A;
     if(temp>0)
    {
        cout<<A<<"pos";
        ll x=A;
        if(x>INT_MAX)
            return 0;
        string s= to_string(A);
        if(s>to_string(INT_MAX))
            return 0;
        std::reverse(s.begin(),s.end());
        // int res=stoi(s);
        // return res;
    }
    else
    {   
        cout<<ll(temp)<<"neg";
        ll x=-1*A;
        if(x+2>INT_MAX)
            return 0;
        string s= to_string(x);
        std::reverse(s.begin(),s.end());
       cout<<s<<"\n";
       int res;
        try{
        res=0-stoi(s);

        }
        catch(exception e)
        {
            return 0;
        }
        
        return res;
    }
}


int main()
{
    cout<<reverse(-1146467285)<<"\n";
    return 0;
}
