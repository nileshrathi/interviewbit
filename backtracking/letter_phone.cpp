 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

vector<string> mapping={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void find(string A, vector<string> &res, string curr, int target ,int index)
{
    if(curr.length()==target)
        {
            res.push_back(curr);
            return;
        }

    for(int i=index;i<target;i++)
    {
        
            for(int j=0; j<mapping[A[i]-'0'].length();j++)
            {
                //char possible with index i and j
                char x=mapping[A[i]-'0'][j];
                curr.push_back(x);
                find(A,res,curr,target,i+1);
                curr.pop_back();
            }    
    
        
    }
    return;
}

vector<string> letterCombinations(string A) {
    int target=A.length();
    vector<string> res;
    string curr="";
    find(A,res,curr,target,0);
    return res;
}


int main()
{
    string A="2";
    vector<string> res=letterCombinations(A);

    for(int i=0;i<res.size();i++)
    {

            cout<<res[i]<<"\n";
            
    }
    cout<<"\n";
    // cout<<trap(A);
    return 0;
}