#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string intToRoman(int A) {

    vector<pair<int , string > > v;
    v.push_back(make_pair(1000,"M"));
    v.push_back(make_pair(900,"CM"));
    v.push_back(make_pair(500,"D"));
    v.push_back(make_pair(400,"CD"));
    v.push_back(make_pair(100,"C"));
    v.push_back(make_pair(90,"XC"));
    v.push_back(make_pair(50,"L"));
    v.push_back(make_pair(40,"XL"));
    v.push_back(make_pair(10,"X"));
    v.push_back(make_pair(9,"IX"));
    v.push_back(make_pair(5,"V"));
    v.push_back(make_pair(4,"IV"));
    v.push_back(make_pair(1,"I"));


    int div_index=0;
    string ans="";
    while(A>0)
    {
        int count=0;
        if((A/v[div_index].first)>0)
        {
            count=count+(A/v[div_index].first);
            A=A%(v[div_index].first);
        }
        
        while(count--)
        {
            ans=ans+v[div_index].second;
        }
        div_index++;
    }

    return ans;
}

int main()
{
    cout<<intToRoman(0);
}