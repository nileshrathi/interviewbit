 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

string fractionToDecimal(int A, int B) {
    
    ll a=A;
    ll b=B;
    bool neg=(a<0)^(b<0);
    // cout<<"abs "<<llabs((ll)a);
    a=abs(a);
    b=abs(b);

    // cout<<a<<" "<<b;
    string res;
    if(neg)
    {
        res= "-"+res;
    }   
    
    ll integral_part=a/b;
    res=res+to_string(integral_part);

    
    if(a%b==0)
    {
        return res;
    }

    res=res+".";
    ll rem=a%b;
    unordered_map<int,int> m;
    ll index=0;
    bool repeating=false;

    while(rem>0)
    {
        if(m.find(rem)!=m.end())
        {
            index=m[rem];
            repeating=true;
            break;
        }
        else
        {
            m[rem]=res.size();
        }

        rem=rem*10;

        res=res+to_string(rem/b);
        rem=rem%b;
    }

    if(repeating)
    {
        res.insert(index,"(");
        res=res+")";
        return res;
    }
    
    return res;
}


int main()
{
    cout<<fractionToDecimal(-2147483648,-1);
    return 0;
}