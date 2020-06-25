#include<bits/stdc++.h>
#include<iostream>
using namespace std;



vector<int> solve(vector<int> &A, vector<int> &B)
{
 int n=A.size();

 sort(A.begin(),A.end());
 sort(B.begin(),B.end());

 priority_queue<pair<int,pair<int,int> > >pq;
 set<pair<int,int> >s;
 pair<int,int> temp=make_pair(n-1,n-1);
 pq.push(make_pair(A[n-1]+B[n-1],temp));
 s.insert(temp);
 vector<int> res;

 int k=n;
 while(k--)
 {
    pair<int,pair<int,int> > temp=pq.top();
    pq.pop();

    res.push_back(temp.first);
    
    int i=temp.second.first;
    int j=temp.second.second;

    //i,j-1;
    pair<int,int> next=make_pair(i,j-1);
    if(s.find(next)==s.end())
    {
        pq.push(make_pair(A[i]+B[j-1],next));
        s.insert(next);
    }

    next=make_pair(i-1,j);
    if(s.find(next)==s.end())
    {
        pq.push(make_pair(A[i-1]+B[j],next));
        s.insert(next);
    }


 }
 return res;

}

int main()
{
vector<int > a={ 3, 1, 3, 1};
vector<int > b={ 1, 4, 1, 4};
vector<int> res=solve(a,b);

for(int i=0;i<res.size();i++)
{
    cout<<res[i]<<" ";
}

return 0;
}