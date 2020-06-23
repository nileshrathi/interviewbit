 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

vector<int> equal(vector<int> &A) {
    int n=A.size();
    unordered_map<int,vector<pair<int,int> > > um;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=A[i]+A[j];
            um[sum].push_back(make_pair(i,j));
        }
    }
    int ra=INT_MAX;
    int rb=INT_MAX;
    int rc=INT_MAX;
    int rd =INT_MAX;

    for(auto x=um.begin();x!=um.end();x++)
    {
        vector<pair<int,int> > v=x->second;
        if(v.size()>1)
        {
            for(int i=0;i<v.size();i++)
            {
                for(int j=i+1;j<v.size();j++)
                {
                    int a=v[i].first;
                    int b=v[i].second;
                    int c=v[j].first;
                    int d=v[j].second;

                    //  cout<<"sum ="<<x->first <<" "<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
                    if(a<b && c<d && a<c && b!=d && b!=c && a<=ra && b<=rb && c<=rc && d<=rd)
                    {
                        ra=a;
                        rb=b;
                        rc=c;
                        rd=d;
                        // vector<int> temp={ra,rb,rc,rd};
                        // return temp;
                        // sort(temp.begin(),temp.end());
                        // s.insert(temp);
                        
                    } 
                    else if(c<d && a<b && c<a && d!=b && d!=a && c<=ra && d<=rb && a<=rc && b<=rd)
                    {
                        ra=c;
                        rb=d;
                        rc=a;
                        rd=b;
                        // vector<int> temp={rc,rd,ra,rb};
                        // return temp;
                        // sort(temp.begin(),temp.end());
                        // s.insert(temp);
                        
                    }
                }
            }
        }
    }

    vector<int> res={};
    if(ra!=INT_MAX)
    {
        res.push_back(ra);
        res.push_back(rb);
        res.push_back(rc);
        res.push_back(rd);
    }
    return res;
    
}


int main()
{
    vector<int> A={3, 4, 7, 1, 2, 9, 8};
    vector<int> res=equal(A);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}