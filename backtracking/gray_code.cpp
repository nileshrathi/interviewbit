 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

void find(vector<int> &res, int n,int &curr_num)
{
    if(n==0)
    {
        res.push_back(curr_num);
        return;
    }

    find(res,n-1,curr_num);

    //invert the last bit of curr_num
    curr_num = curr_num ^ (1 << (n - 1));

    find(res,n-1,curr_num);
    return;
    
}

vector<int> grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int curr_num=0;
    vector<int>res;
    find(res,A,curr_num);
    return res;
}

int main()
{
    int A=2;
    vector<int> res=grayCode(A);
        for(int i=0;i<res.size();i++)
    {
            cout<<res[i]<<"\n";
    }
}
