#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll number_of_digits(ll n)
{
    ll digitcount=0;
    if(n==0)
    {
        return 1;
    }
    while(n!=0)
    {
        n=n/10;
        digitcount++;
    }
    return digitcount;
}
int solve(vector<int> &A, int B, int C) {
    ll digi_count_c=number_of_digits(C);
    if(digi_count_c<B)
    {
        return 0;
    }
    string cs=to_string(C);
    reverse(cs.begin(),cs.end());
    ll cr=stoll(cs);
    //cout<<cs<<"\n";
    ll count=1;
    vector<ll> res;
    bool same=true;
    
    int b=1;
    while(cr>0)
    {
        //cout<<"computing for place "<<B<<"th\n";
        ll curr_digit=cr%10;
        ll index_next_higher=lower_bound(A.begin(),A.end(),curr_digit)-A.begin();

        bool less_than=false;

        if(index_next_higher==A.size() && same==true)
        {
            //All elemnt smaller
            if(A[0]==0 && b==1)
            {
                res.push_back(index_next_higher-1);    
            }
            else
            res.push_back(index_next_higher);
            //cout<<"yaha";
            same=false;
        }
        else if(same==true)
        {
            
            if(A[index_next_higher]==curr_digit)
            {
                //cout<<"yaha "<<curr_digit<<"\n";
                if(A[0]==0 && b==1)
                {
                    res.push_back(index_next_higher+1-1);
                }
                else
                res.push_back(index_next_higher+1);
            }
            else
            {
                
                if((index_next_higher-1)>=0)
                {
                    if(A[0]==0 && b==1)
                    {
                        res.push_back(index_next_higher-1+1-1);
                    }
                    else
                    res.push_back(index_next_higher-1+1);
                    
                }
                else
                {
                    return 0;
                }
                same=false;
                
            }
            
        }
        else
        {
            cout<<"yaha";
                if(A[0]==0 && b==1)
                    {
                        
                        res.push_back(A.size()-1);
                    }
                    else
                    res.push_back(A.size());
        }
        
        cr=cr/10;
        b++;
    }

    if(res.size()==0)
    {
        return 0;
    }

    for(ll i=0;i<res.size();i++)
    {
        count=count*res[i];
    }
    if(same==false)
        return count;
    else
        return count-1;

}
int main()
{
    vector<int> A={0,1,2,5};

    cout<<solve(A,2,40);
}