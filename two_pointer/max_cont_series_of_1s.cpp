#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

vector<int> maxone(vector<int> &A, int B) {

    int n=A.size();
    
    int st=0;
    int en=0;
    int finalst=0;
    int finalen=0;
    int max_count=0;
    int count=0;
    int bits_fliped=0;
    while(en<n)
    {
        if(bits_fliped<=B)
        {
            if(A[en]==0)
            {
                bits_fliped++;
            }
            en++;
        }

        if(bits_fliped>B)
        {
            if(A[st]==0)
            {
                bits_fliped--;
            }
            st++;
        }


        int count=en-st;
        if(count>max_count && bits_fliped<=B)
        {
            max_count=count;
            finalst=st;
            finalen=en;
        }

    }

    cout<<finalst<<" "<<finalen<<"\n";
    vector<int> res;
    for(int i=finalst;i<finalen;i++)
    {
        res.push_back(i);
    }
    return  res;

    
}

int main()
{
    vector<int> A={1, 1, 0, 0, 0, 0, 0, 1};
    int M=4;
    vector<int> ans=maxone(A,M);

}