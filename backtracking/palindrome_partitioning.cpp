 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

bool is_palindrome(string s, int st, int en)
{
    while(st<en)
    {
        if(s[st]==s[en])
        {
            st++;
            en--;
        }
        else
        {
            return false;
        }
        
    }
    return true;
}

void find(string A,vector<vector<string> > &res, vector<string> &curr, int target, int index)
{
    if(index>=target)
    {
        res.push_back(curr);
        return ;
    }

    for(int i=index;i<target;i++)
    {
        if(is_palindrome(A,index,i))
        {
            curr.push_back(A.substr(index,i-index+1));
            find(A,res,curr,target,i+1);
            curr.pop_back();
        }
    }
    return;
}

vector<vector<string> > partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<string> > res;
    vector<string> curr;
    int target =A.length();
    find(A,res,curr,target,0);
    return res;
}



int main()
{
    string A="aab";
    vector<vector<string> > res=partition(A);
        for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
            cout<<"\n";
    }
}