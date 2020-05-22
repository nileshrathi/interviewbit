#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string solve(string A) {

    string s =A;
    int index=0;
    // /remove prevailing white spaces
    while(s[0]==' ') s.erase(s.begin());

    string ans="";

    string temp="";
    bool space =false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=' ')
        {
            space=false;
            temp=temp+s[i];
        }
        else
        {
            ans=temp+ans;
            temp="";
            if(!space)
            {
                ans=" "+ans;
                space=true;
            }
        }
    }


    if(temp!="")
        ans=temp+ans;

    while(ans[0]==' ') ans.erase(ans.begin());
    return ans;
    

}

int main()
{
    cout<<solve("   the sky     is blue   ");
}