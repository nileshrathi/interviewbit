 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

string minWindow(string A, string B) {
    int lenp=B.length();
    int lens=A.length();
    if(lenp>lens)
    {
        return "";
    }
    vector<int> smap(256,0);
    vector<int> pmap(256,0);
    for(int i=0;i<lenp;i++)
    {
        pmap[B[i]]++;
    }

    int start=0;
    int final_start=-1;
    int curr_len=0;
    int min_win_len=INT_MAX;

    for(int i=0;i<lens;i++)
    {
        smap[A[i]]++;

        if(pmap[A[i]]>0 && smap[A[i]]<=pmap[A[i]])
        {
            curr_len++;
        }

        if(curr_len==lenp)
        {
            while(smap[A[start]]>pmap[A[start]] || pmap[A[start]]==0)
            {
                
                if(smap[A[start]]>pmap[A[start]])
                {
                    smap[A[start]]--;
                }
                start++;
            }

            int curr_win_len=i-start+1;
            if(curr_win_len<min_win_len)
            {
                min_win_len=curr_win_len;
                final_start=start;
            }
        }
    }

    if(curr_len!=lenp)

    return A.substr(final_start,min_win_len);

    
}

int main()
{
    cout<<minWindow("ADOBECODEBANC","ABC");
    return 0;
}