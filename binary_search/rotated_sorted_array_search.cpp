#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int modsearch(const vector<int> &A,int lo, int hi, int key)
{
    int mid=lo+(hi-lo)/2;

    if(lo > hi)
        return -1;

    if(A[mid]==key)
    {
        return mid;
    }

    //left half sorted
    if(A[lo]<=A[mid])
    {
        //key present in left half
        if(key>=A[lo] && key<=A[mid])
        {
            modsearch(A,lo,mid-1,key);
        }
        else
        {
            modsearch(A,mid+1,hi,key);
        }
        
    }
    else
    {
        if(key >=A[mid] && key <=A[hi])
        {
            modsearch(A,mid+1,hi,key);
        }
        else
        {

            modsearch(A,lo,mid-1,key);
        }
        
    }
    

}

int search(const vector<int> &A, int B) {

        return modsearch(A,0,A.size()-1,B);

}

int main()
{
    vector<int> A={101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100};
    int B=202;
    cout<<search(A,B);
}
