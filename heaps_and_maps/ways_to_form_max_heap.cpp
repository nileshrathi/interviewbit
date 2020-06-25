#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;
ll dp[110];
ll nck[110][110];
ll lg[110];
#define mod 1000000007ll
ll fact[110];
ll ifact[110];

ll powerx(ll a,ll b)
{
    
    a = a%mod;
    ll res = 1;
    while(b)
    {

        // cout<<"b is "<<res<<"\n";
        if(b&1)
            res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}

ll inverse(ll a)
{
    return powerx(a,mod-2);
}

ll precompute_fact()
{
    fact[0]=1;
    ifact[0]=1;
    for(int i=1;i<110;i++)
    {
    fact[i]=(i*fact[i-1])%mod;
    ifact[i]=(inverse(i)*ifact[i-1])%mod;
    }
}



ll comb(ll n,ll k)
{
    if(k>n)
        return 0;
    ll ans=fact[n];
    //  cout<<ans<<"\n";
    ans=(ans*ifact[n-k])%mod;
    //  cout<<ans<<"\n";
    ans=(ans*ifact[k])%mod;
    // cout<<ans<<"\n";
    return ans;
} 


ll getLeft(ll n)
{
if(n<=1)
    return 0;
ll height=log2(n);
ll total_minus_last=powerx(2,height) -1;
ll last=n-total_minus_last;
ll left_total_minus_last=powerx(2,height-1)-1;
return min(total_minus_last,left_total_minus_last+last);

}

ll func(ll n)
{
    if(dp[n]!=-1)
        return dp[n];
    
    ll left=getLeft(n);

    ll c=comb(n-1,left);
    // cout<<"c is "<<left<<"\n";
    ll ans=(c*func(left))%mod;
    ans=(ans*func(n-1-left))%mod;
    dp[n]=ans;
    return ans;
}

int solve(int A) {

    if(A<=2)
        return 1;

    precompute_fact();
    // cout<<"comb "<<comb(4,3)<<"\n";
    for(ll i=0;i<110;i++)
    {
        dp[i]=-1;
    }
    
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    // cout<<"dp4="<<dp[4]<<"\n";

    ll ans=func(A);
    
    
    return ans;

}


int main()
{
    cout<<solve(3);

}