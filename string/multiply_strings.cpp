#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string multiplyStringChar(string a, int b)
{
    int n=a.length();
    int i=n-1;

    int carry=0;
    string ans="";
    int rem=0;
    while(i>=0)
    {
        int tempres=((a[i]-'0')*b)+carry;
        
        rem=tempres%10;
        carry=tempres/10;
        ans=to_string(rem)+ans;
        //cout<<tempres<<"\n";
        i--;
        
    }
    if(carry>0)
        ans=to_string(carry)+ans;

    return ans;
}


string multiply(string A, string B) {
    A.erase(0, min(A.find_first_not_of('0'), A.size()-1));
    B.erase(0, min(B.find_first_not_of('0'), B.size()-1));
    // cout<<"yaha";
    int m=A.length();
    int n=B.length();
    vector<string> ans(n);

    int padding =0;
    int maxlen=0;
    for(int i=n-1;i>=0;i--)
    {
        ans[i]=multiplyStringChar(A,(B[i]-'0'));
        
        for(int j=0;j<padding;j++)
        {
            ans[i]=ans[i]+"0";
        }
        padding++;
        int len=ans[i].length();
        maxlen=max(maxlen,len);
        cout<<ans[i]<<"\n";
    }

    //Add vectors
    cout<<"performing addition\n";

    string res="";
    int carry=0;
    int rem=0;
    for(int i=0;i<maxlen;i++)
    {
        int temp=0;

        for(int j=0;j<ans.size();j++)
        {
            if(ans[j].length()>i)
            {
                temp=temp+(ans[j][ans[j].length()-1-i]-'0');
            }
            else
            {
                temp=temp+0;
            }
            
        }
        cout<<temp<<"\n";
        temp=temp+carry;
        rem=temp%10;
        carry=temp/10;
        res=to_string(rem)+res;
    }
    if(carry>0)
    {
        res=to_string(carry)+res;
    }


     return res;
    
}

int main()
{
    string A="";
    string B="4";

    cout<<multiply("99999","99999");
    return 0;
}
