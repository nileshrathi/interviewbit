#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int compare(string a, string b)
{
    a.erase(0, min(a.find_first_not_of('0'), a.size()-1));
    b.erase(0, min(b.find_first_not_of('0'), b.size()-1));
  //  cout<<"A "<<a<<"\n";
  //  cout<<"B "<<b<<"\n";
    if(a.length()>b.length())
        return 1;
    else if(a.length()<b.length())
        return -1;

    for(int i=0;i<a.length();i++)
    {
        if(a[i]>b[i])
            return 1;
        else if(a[i]<b[i])
            return -1;
    }
   // cout<<"yaha";
    return 0;

}

int compareVersion(string A, string B) {
    
    
    vector<string> aToken;
    vector<string> bToken;

    stringstream stream(A);
    string intermediate;
    while(getline(stream,intermediate,'.'))
    {
        aToken.push_back(intermediate);
    }

    stringstream stream2(B);
    string intermediate2;
    while(getline(stream2,intermediate2,'.'))
    {
        bToken.push_back(intermediate2);
    }

    for(int i=0;i<aToken.size() && i<bToken.size();i++)
    {
       
       int c=compare(aToken[i],bToken[i]);

        if(c!=0)
            return c;
        
    }

    if(aToken.size()>bToken.size())
    {
        for(int i=bToken.size();i<aToken.size();i++)
        {
            int c=compare(aToken[i],"0");
                if(c!=0)
                    return c;
        }
    }
        
    else if(aToken.size()<bToken.size())
    {
        
        for(int i=aToken.size();i<bToken.size();i++)
        {
            int c=compare(bToken[i],"0");
                if(c!=0)
                    return c;
        }
    }
    
        return 0;

    
}

int main()
{
    cout<<compareVersion("13.0","13.0.8");
}

