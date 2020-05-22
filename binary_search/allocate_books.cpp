#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll get_no_of_stu(vector<int> &A, int min_books)
{
    ll count=1;
    
    ll temp=0;
    for(ll i=0;i<A.size();i++)
    {
        temp=temp+A[i];

        if(temp>min_books)
        {
            count++;
            temp=A[i];
        }
    }
    return count;

}

int books(vector<int> &A, int B) {
    
    ll n=A.size();
    //max pages in obe book..= min(maxpages alloted to a child)
    ll lo=*max_element(begin(A),end(A));


    //all books alloted to one child
    ll hi=0;
    for(ll i=0;i<n;i++)
    {
        hi+=A[i];
    }

    while(lo<hi)
    {
        //split the current group into half and check if we have enough no. of child

        ll mid=lo+(hi-lo)/2;

        ll no_of_stu_req=get_no_of_stu(A,mid);


        if(no_of_stu_req<=B)
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
        
    }
    return lo;

}
int main()
{
    vector<int> A={12, 34, 67, 90};
    int B=1;
    cout<<books(A,B);
}
