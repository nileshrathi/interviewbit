#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int divide(int A, int B) {

    if(A==INT_MIN && B==-1)
        return INT_MAX;

ll N=(A);
ll D=(B);
N=abs(N);
D=abs(D);

ll ans=0;

bool neg=(A<0)^(B<0);

//cout<<N<<" "<<D<<"wsd";


while(N>=D)
{
    ll count=0;

    ll temp=D;
    while(temp<=N)
    {
        temp=temp<<1;
        count++;
    }
    //cout<<count<<"cds\n";
    ans=ans+(1<<(count-1));
    N=N-(D<<(count-1));
}


if(neg)
    ans= -ans;


return ans;

        
}

int main()
{
    int a=-2147483648;
    int b=1;
    cout<<divide(a,b);
}