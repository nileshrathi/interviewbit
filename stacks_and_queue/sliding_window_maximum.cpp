 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;



vector<int> slidingMaximum(const vector<int> &A, int B) {

    deque<int> dq(B);
    int n=A.size();
    vector<int> res;
    int i=0;
    while(i<B)
    {
        while(!dq.empty() && A[dq.back()]<=A[i])
            dq.pop_back();
        dq.push_back(i);
        i++;
    }


    while(i<n)
    {
        res.push_back(A[dq.front()]);

        while(!dq.empty() && dq.front()<=i-B)
            dq.pop_front();

        while(!dq.empty() && A[dq.back()]<=A[i])
            dq.pop_back();
        dq.push_back(i);
        i++;
    }
    res.push_back(A[dq.front()]);
    return res;
}


int main()
{
    vector<int> A={1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> res=slidingMaximum(A,3);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
  //  cout<<largestRectangleArea(A);
    return 0;
}