 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

vector<int> prevSmaller(vector<int> &A) {

    stack<int> st;
    vector<int>res(A.size());
    for(int i=0;i<A.size();i++)
    {
        while(!st.empty() && st.top()>=A[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            res[i]=st.top();
        }
        else
        {
            res[i]=-1;
        }
        st.push(A[i]);
        
    }
    return res;
}

int main()
{
    vector<int> A={3,2,1};
    vector<int> res=prevSmaller(A);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    return 0;
}