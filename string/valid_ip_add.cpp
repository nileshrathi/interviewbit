#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool check (vector<string> ip)
{
    for(int i=0;i<ip.size();i++)
    {
        if(ip[i]=="")
            return false;
            int temp=stoi(ip[i]);
        if(temp>255 || temp<0)
            return false;
        
        if(to_string(temp)!=ip[i])
            return false;
    }
    return true;
}

vector<string> restoreIpAddresses(string A) {

    int n=A.length();
    if(n<4 || n>12)
        return vector<string> {};
    
    vector<string> ans;
    set<string> s;

    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                for(int l=1;l<=3;l++)
                {
                    if(i+j+k+l!=n)
                        continue;
                    vector<string> ip(4);
                    ip[0]=A.substr(0,i);
                    ip[1]=A.substr(i,j);
                    ip[2]=A.substr(i+j,k);
                    ip[3]=A.substr(i+j+k,l);
                    bool flag=check(ip);
                   // cout<<"hello\n";
                    if(flag)
                    {
                        string temp=ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3];
                        ans.push_back(temp);
                    }
                    
                }
            }
        }
    }

    return ans;

}

int main()
{
    vector<string> res=restoreIpAddresses("25525511135");
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<"\n";
    }

}
