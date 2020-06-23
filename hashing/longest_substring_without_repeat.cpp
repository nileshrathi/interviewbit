 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

int lengthOfLongestSubstring(string A) {

    int n=A.length();

    unordered_map<char,int> um;
    int max_len=0;
    int curr_len=0;
    for(int i=0;i<n;i++)
    {
        // cout<<"yaha";
        char curr_char=A[i];
        if(um.find(curr_char)==um.end())
        {
            um[curr_char]=i;
            curr_len++;
            if(curr_len>max_len)
            {
                max_len=curr_len;
            }
        }
        else
        {
         int temp=um[curr_char];
          i=(temp); 
          um.clear();
          curr_len=0;
        }
        
    }
    return max_len;
}

int main()
{
    cout<<lengthOfLongestSubstring("abcabcbb");
    return 0;
}