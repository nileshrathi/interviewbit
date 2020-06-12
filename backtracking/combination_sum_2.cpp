 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;


void find(vector<int> &A,set<vector<int> > &sol,vector<int> curr,int currsum,int index,int target)
{
   
    if(currsum>target)
        return ;

    if(currsum==target)
        {
            sol.insert(curr);
            return ;
        }
    
    for(int i=index;i<A.size();i++)
    {
        //include the curr element
        currsum=currsum+A[i];
        curr.push_back(A[i]);

        find(A,sol,curr,currsum,i+1,target);
         
        
        currsum=currsum-A[i];
        curr.pop_back();

    }
    return ;
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {

        sort(A.begin(),A.end());
        vector<vector<int> > sol;
        set< vector<int> > sol_set;
        vector<int> curr;
        int  currsum=0;

        find(A,sol_set,curr,currsum,0,B);
        sol.resize(sol_set.size());
        copy(sol_set.begin(),sol_set.end(),sol.begin());
        return sol;

}



int main()
{

    vector<int> A={10,1,2,7,6,1,5};
    vector<vector<int> > res=combinationSum(A,8);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }
    
    // cout<<trap(A);
    return 0;
}