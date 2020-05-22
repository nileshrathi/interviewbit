#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef  long long  int ll ;
ll  m=1000000007;





static const int MODULUS = 1000000007;

// compute 2^k modulo MODULUS
int power2modulo(int k)
{
    long result = 1;
    for (int i=0; i<k; i++) {
        result = (result + result) % MODULUS;
    }
    return result;
}

// compute greatest common divisor
int gcd(int A, int B) {
    int T;
    if (A < B)
        std::swap(A, B);
    while (B != 0) {
        T = B;
        B = A % B;
        A = T;
    }
    return A;
}

// compute binomial coefficient with modulo arithmetic
long binomial(int n, int r)
{
    priority_queue<int> numerator, denominator;
    priority_queue<int> new_numerator, new_denominator;
    int a = std::max(r, n - r);
    int b = n - a;
    long result = 1;
    long T;
    
    // do not compute factorials, but push the terms that make up the factorials
    for (int i=a+1; i<=n; i++) {
        numerator.push(i);
    }
    for (int i=2; i<=b; i++) {
        denominator.push(i);
    }
    
    // we try to cancel out the GCD of each numerator with each denominator
    int n_len = numerator.size();
    for (int i=0; i<n_len; i++) {
        int num = numerator.top();
        numerator.pop();
        if (num == 1)
            break;  // we can exit here because we use priority_queue
        int d_len = denominator.size();
        for (int j=0; j<d_len; j++) {
            int den = denominator.top();
            denominator.pop();
            // we reduce numerator and denominator using GCD
            long factor = gcd(num, den);
            num /= factor;
            den /= factor;
            if (den != 1) {
                new_denominator.push(den);
            }
            if (num == 1) {
                break;
            }
        }
        if (num != 1) {
            new_numerator.push(num);
        }
        while (!new_denominator.empty()) {
            denominator.push(new_denominator.top());
            new_denominator.pop();
        }
    }

    // at this point we should have exhausted all the denominators    
    assert(denominator.empty());
    
    // now we multiply the remaining numerator terms using modulo arithmetic
    while (!new_numerator.empty()) {
        result *= new_numerator.top();
        result %= MODULUS;
        new_numerator.pop();
    }
    
    return result;
}










ll  combination(ll  mpn,ll  m,ll  n)
{
    // ll  ans=1;

    // for(ll  i=n+1;i<=mpn;i++)
    // {
    //     ans=ans*i;
    //     ans=ans/(i-n);
    //     //cout<<ans<<" ";
    // }
    // return ans;
    return binomial(mpn,n);
}
ll power(ll a,ll b)
{
    ll  ans=1;
    for(ll  i=1;i<=b;i++)
    {
        ans=(ans*a)%m;
    }
    return ans;
}
int solve(int A, vector<int> &B) {
    
    sort(B.begin(),B.end());
    
    if(B.size()==1)
    {
        ll left=B[0]-1;
        ll right=A-B[0];
        return combination(left+right,left,right);   
    }

    ll ans=0;

    ll  left=B[0]-1;
    ll  right=B[1]-B[0]-1;
    ll  lval=1;
    ll  rval=power(2,right-1);
    ans=(ans+(lval*rval))%m;
    ans=(ans*combination(left+right,left,right))%m;

    //cout<<lval<<" "<<rval<<" "<<left<<" "<<right<<" "<<combination(left+right,left,right)<<"\n";
    left=left+right;

    ll si=2;
    while(si<B.size())
    {
        //cout<<right<<" ";
        right=B[si]-B[si-1]-1;
        lval=ans;
        rval=power(2,right-1);
        ll temp=(lval*rval)%m;
        temp=(temp*combination(left+right,left,right))%m;
        ans=temp;
        si++;
        left=left+right;
        
    }

    right=A-B[B.size()-1];
    lval=ans;
    rval=1;
    ll temp=(lval*rval)%m;
    temp=(temp*combination(left+right,left,right))%m;
    if(temp>0)
        ans=temp;

       
return ans;
}


int main()
{
    int A=100;
    vector<int> B={79, 76, 26, 27, 73, 81, 56, 94, 84, 1, 62};
    cout<<solve(A,B);
  //cout<<combination(3,1,2);
    return 0;
}