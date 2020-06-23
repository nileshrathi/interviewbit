 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;


int find_product(string s)
{
    int prod=1;
    for(int i=0;i<s.length();i++)
    {
        prod=prod*(s[i]-'0');
    }
   // cout<<prod<<"\n";
    return prod;
}

int colorful(int A) {
    set<int> s;
    string num=to_string(A);

    for(int i=0;i<num.length();i++)
    {
        for(int j=i;j<num.length();j++)
        {
            int prod=find_product(num.substr(i,j-i+1));
            if(s.find(prod)!=s.end())
            {
                return 0;
            }
            s.insert(prod);
            
        }
    }
    return 1;

}

int main()
{
    
    cout<<colorful(325);

}