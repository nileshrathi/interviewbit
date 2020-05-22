#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> getlps(string a){
   // cout<<"yaha";
    int n=a.length();
    vector<int> lps(n,0);

    lps[0]=0;
    
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

    // for(int i=0;i<n;i++)
    // {
    //     cout<<"lps at "<<i<<" ="<<lps[i]<<"\n";
    // }
    return lps;
}

int solve(string A) {

    int n=A.length();
    string temp=A;
    
    reverse(begin(temp),end(temp));
    
    temp=A+"*"+temp;
    vector<int> lps=getlps(temp);
    return n-lps[lps.size()-1];

}



int main()
{
    
    cout<<solve("AACECAAAA");
}