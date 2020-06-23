 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

int maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

     unordered_map< double, int> um;
    int ans=1;
    int n=A.size();
     if(n==0)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {
       
        um.clear();
        int x1=A[i];
        int y1=B[i];
        int duplicate=0;
        int vertical =0;
        for(int j=i+1;j<n;j++)
        {
            int x2=A[j];
            int y2=B[j];

            if(x1==x2)
            {
                if(y1==y2)
                {
                    duplicate++;
                }
                else
                {
                    vertical++;
                }                
            }
            else
            {
                int num=(y2-y1);
                int denom=(x2-x1);
                double slope=0.0;
                if(y2!=y1)
                {
                    slope=(1.0*(double(num)/double(denom)));
                    // cout<<slope<<"\n";
                }
                if(um.find(slope)!=um.end())
                {
                    um[slope]++;
                }
                else
                {
                    um[slope]=1;
                }

            }
            

            
            
        }

    for(auto i=um.begin();i!=um.end();i++)
    {
        int curr=i->second+duplicate+1;
        ans=max(ans,curr);
    }

    if(vertical+duplicate+1>ans)
    {
        ans=vertical+duplicate+1;
    }

    }

    return ans; 
}

int main()
{
    vector<int> A={-6,-17,5,-16,-18,-17};
    vector<int> B={2,-4,5,-13,-2,20};

    cout<<maxPoints(A,B);
}