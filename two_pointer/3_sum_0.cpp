
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int> > find_exact(vector<int> &A, ll target)
{
    if(A.size()<=0)
    {
        return vector<vector<int> >{};
    }
    int st=0;
    int en=A.size()-1;
    vector<vector<int> >ans={};
    int count=0;

  //  cout<<st<<" "<<en<<"\n"<<std::flush;
    while(st<en)
    {

         
        ll sum=ll(A[st])+ll(A[en]);

        if(sum==target)
        {
            vector<int> temp;
            temp.push_back(A[en]);
            temp.push_back(A[st]);
            ans.push_back(temp);
            st++;
            en--;
        }
        else if(sum<target)
        {
            st++;
        }
        else if(sum>target)
        {
            en--;
        }
    
        //cout<<st<<" "<<en<<"\n"<<std::flush;
        
    }
    return ans;
    
}

vector<vector<int> > threeSum(vector<int> &A) {
   
   sort(A.begin(),A.end());
    // set<int> s;
    // unsigned size = A.size();
    // for( unsigned i = 0; i < size; ++i ) s.insert( A[i] );
    // A.assign( s.begin(), s.end() );

    set<pair<int,pair<int,int> > >s;
 
   


   vector<vector<int> >ans={};
   int count=0;
   int n =A.size();
   while(A.size()>2)
   {
       int first =A[0];
       A.erase(A.begin());
       vector<vector<int> > temp =find_exact(A,ll(ll(0)-ll(first)));

    //     for(int i=0;i<temp.size();i++)
    // {
    //     for(int j=0;j<temp[i].size();j++)
    //     {
    //         cout<<temp[i][j]<<" ";
    //     }
    //     cout<<"end\n";
    // }


       for(int j=0;j<temp.size();j++)
       {
           temp[j].push_back(first);
           reverse(temp[j].begin(),temp[j].end());
           ans.push_back(temp[j]);
       }

       

   }
   vector<vector<int> > ans2;
   for(int i=0;i<ans.size();i++)
   {
       
           pair<int,pair<int,int> > p = make_pair(ans[i][0],make_pair(ans[i][1],ans[i][2]));
           s.insert(p);
   }

   while(!s.empty())
   {
       pair<int,pair<int,int> > p= *s.begin();
       vector<int>temp;
       temp.push_back(p.first);
       temp.push_back(p.second.first);
       temp.push_back(p.second.second);
       ans2.push_back(temp);
       s.erase(s.begin());

   }
   return ans2;
    

}

int main()
{
   // cout<<"yaha";
    vector<int> A={2147483647, -2147483648, -2147483648, 0, 1};
     vector<vector<int> >ans=threeSum(A);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }


}



