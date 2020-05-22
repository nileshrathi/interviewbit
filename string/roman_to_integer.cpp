#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int romanToInt(string A) {

    int res=0;
    int i=0;

    map<char,int> m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    
    for(int i=0;i<A.length();i++)
    {
        int v1=m[A[i]];

        if(i+1<A.length())
        {
            int v2=m[A[i+1]];

            if(v2>v1)
                {
                    res=res+v2-v1;
                    i++;
                }
            else
            {
                res=res+v1;
            }
            
        }
        else
        {
            res+=v1;
        }
           

    }

    return res;
    
}

int main()
{
    cout<<romanToInt("XIV");
}