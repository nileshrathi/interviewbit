 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;


void find(vector<int> &A,vector<vector<int> > &sol,vector<int> curr,int currsum,int index,int target)
{
   
    if(currsum>target)
        return ;

    if(currsum==target)
        {
            sol.push_back(curr);
            return ;
        }
    
    for(int i=index;i<A.size();i++)
    {
        //include the curr element
        currsum=currsum+A[i];
        curr.push_back(A[i]);

         if(currsum>target)
         {
             find(A,sol,curr,currsum,i+1,target);
         }
         else
         {
             find(A,sol,curr,currsum,i,target);
         }
         
        
        currsum=currsum-A[i];
        curr.pop_back();

    }
    return ;
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {

    set<int> s;
    for(int i=0;i<A.size();i++)
    {
        s.insert(A[i]);
    }

     vector<int> C(s.begin(),s.end());   
        vector<vector<int> > sol;
        vector<int> curr;
        int  currsum=0;

        find(C,sol,curr,currsum,0,B);
        return sol;

}



int main()
{

    vector<int> A={2,3,6,7};
    vector<vector<int> > res=combinationSum(A,7);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }
    
    // cout<<trap(A);
    return 0;
}