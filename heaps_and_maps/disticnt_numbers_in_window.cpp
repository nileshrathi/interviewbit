#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;

vector<int> dNums(vector<int> &A, int B) {

    int n=A.size();
    if(B>n)
        return vector<int> {};
    map<int,int> m;
// cout<<"hello";
    for(int i=0;i<B;i++)
    {
       if(m.find(A[i])!=m.end())
       {
           m[A[i]]=m[A[i]]+1;
       }
       else
       {
           m.insert(make_pair(A[i],1));
       }
       
    }
    
    // cout<<"hello";
    vector<int> res;
    for(int i=B;i<n;i++)
    {
        // for(auto it=m.begin();it!=m.end();it++)
        // {
        //     cout<<"key "<<it->first<<" value"<<it->second<<"\n";
        // }
        // cout<<"\n";
        res.push_back(m.size());
        
        // Delete the elemt B places back
        int elem_to_delete=A[i-B];
        if(m[elem_to_delete]>1)
        {
            m[elem_to_delete]=m[elem_to_delete]-1;
        }
        else
        {
            m.erase(elem_to_delete);
        }
        
        

        //insert a the new elemnt;
        if(m.find(A[i])!=m.end())
       {
           m[A[i]]=m[A[i]]+1;
       }
       else
       {
           m.insert(make_pair(A[i],1));
       }

        
    }
    res.push_back(m.size());
    return res;
    
}


int main()
{
    vector<int> A={1, 2, 1, 3, 4, 3};
    int B=3;
    vector<int> res=dNums(A,B);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    return 0;
}