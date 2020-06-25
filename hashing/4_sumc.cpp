 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

vector<vector<int> > fourSum(vector<int> &A, int B) {
    unordered_map<int,vector<pair<int,int> > > um;
    int n=A.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=A[i]+A[j];
            um[sum].push_back(make_pair(i,j));
          ///  cout<<"pushing "<<i<<" "<<j<<"\n";
        }
    }
    set<vector<int> >res;

    for(auto i =um.begin();i!=um.end();i++)
    {

        for(auto j=i;j!=um.end();j++)
        {

                int sum=i->first + j->first;
                if(sum==B)
                {
                    for(int ii=0;ii<i->second.size();ii++)
                    {
                        for(int jj=0;jj<j->second.size();jj++)
                        {
                           // cout<<i->second[ii].first<<" "<<i->second[ii].second<<" "<<j->second[jj].first<<" "<<j->second[jj].second<<"\n";
                            unordered_set<int> s;
                            s.insert(i->second[ii].first);
                            s.insert(i->second[ii].second);
                            s.insert(j->second[jj].first);
                            s.insert(j->second[jj].second);
                            if(s.size()==4)
                            {
                                vector<int> x(s.begin(),s.end());
                                for(int k=0;k<x.size();k++) x[k]=A[x[k]];
                                sort(x.begin(),x.end());
                                res.insert(x);
                            }
                            
                        }
                    }
                }
               // break;

        
        }
    }


    vector<vector<int> > ans(res.begin(),res.end());

    return ans;
}


int main()
{
    vector<int> A={1,0,-1,0,-2,2,0,0,1};
    vector<vector<int> > res=fourSum(A,0);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

