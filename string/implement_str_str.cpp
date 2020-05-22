#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> computelps(string a)
{
    int n=a.length();
    vector<int> lps(n,0);

    int j=0;
    int i=1;
    while(i<n)
    {
        if(a[i]==a[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else
        {
            if(j==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                j=lps[j-1];
            }
            
        }
        
    }
    return lps;
}

int strStr(const string A, const string B) {
    
    string a=B;
    string b=a;
    // string temp=a;
    // a=b;
    // b=temp;
    
    int n=b.length();
    int m=a.length();
    
    
    if(m==0 || n==0 ||(m>n))
        return -1;
        
    vector<int> lps=computelps(a);

    int i=0;
    int j=0;
    while(i<n)
    {
        if(a[j]==b[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            return i-j; 
        }

        else if(i<n && a[j]!=b[i])
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=lps[j-1];
            }
            
        }
    }

    return -1;   
}

int main()
{
    cout<<"ayah";
    string patt="bbbbbbbbab";
    string text="baba";
    //cout<<strStr(patt,text);
    computelps(text);
}
