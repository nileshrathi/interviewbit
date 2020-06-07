 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

int evalRPN(vector<string> &A) {
    stack<int> st;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]=="+")
        {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            int res=op1+op2;
            st.push(res);
        }
        else if(A[i]=="-")
        {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            int res=op1-op2;
            st.push(res);
        }
        else if(A[i]=="*")
        {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            int res=op1*op2;
            st.push(res);
        }
        else if(A[i]=="/")
        {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            int res=op1/op2;
            st.push(res);
        }
        else
        {
            st.push(stoi(A[i]));
        }
        
    }
    if(!st.empty())
    return st.top();
    else
    {
        return 0;
    }
    
}

int main()
{
    vector<string> A={"4", "13", "5", "/", "+"};
    // vector<int> res=slidingMaximum(A,3);

    // for(int i=0;i<res.size();i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    // cout<<"\n";
    cout<<evalRPN(A);
    return 0;
}