 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;


int largestRectangleArea(vector<int> &A) {
    stack<int> st;
    int n=A.size();
    int max_area=0;
    int i=0;
    while(i<n)
    {
        if(st.empty() || A[st.top()]<=A[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            int top=st.top();
            st.pop();
            int len;
            if(st.empty())
            {
                len=i;
            }
            else
            {
                len=i-st.top()-1;
            }
            int area=A[top]*len;
            if(max_area<area)
                max_area=area;
            
        }
        
    }

    while(!st.empty())
    {
        int top=st.top();
        st.pop();
        int len;

        if(st.empty())
            {
                len=i;
            }
            else
            {
                len=i-st.top()-1;
            }
       int area=A[top]*len;
       if(max_area<area)
        max_area=area; 
    }
    return max_area;

}



int main()
{
    vector<int> A={2, 1, 5, 6, 2, 3};
    // vector<int> res=prevSmaller(A);

    // for(int i=0;i<res.size();i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    // cout<<"\n";
    cout<<largestRectangleArea(A);
    return 0;
}