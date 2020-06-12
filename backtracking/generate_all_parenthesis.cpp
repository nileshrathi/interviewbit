 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

void find(vector<string> &res, string curr,int op, int cl, int len)
{
    if(curr.length()==(len*2))
    {
        res.push_back(curr);
        return ;
    }

    if(op<len)
    {
        find(res,curr+'(',op+1,cl,len);
    }
    if(cl<op )
    {
        find(res,curr+')',op,cl+1,len);
    }

    return;
}

vector<string> generateParenthesis(int A) {

    vector<string> res;
    string curr="";
    int op=0;
    int cl=0;
    find(res,curr,op,cl,A);
    return res;
}

int main()

{
    int A=3;
    vector<string> res=generateParenthesis(A);
        for(int i=0;i<res.size();i++)
    {
            cout<<res[i]<<"\n";
    }
}