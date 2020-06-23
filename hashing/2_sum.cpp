 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

vector<int> twoSum(const vector<int> &A, int B) {

    unordered_set<int>  us;

    int index1=-1;
    int index2=-1;
    vector<int> res;
    bool find=false;
    for(int i=0;i<A.size();i++)
    {
        int target=B-A[i];
        if(us.find(target)!=us.end())
        {
          //  cout<<"yaha";
            index1=i+1;
            
            
            for(int j=0;j<A.size();j++)
            {
                if(j!=i && A[j]==target)
                {
                    index2=j+1;
                }
            }

            
            find=true;
            break;
            
        }
        else
        {
            us.insert(A[i]);
        }
        
        
    }

    if(find)
    {
        if(index1>index2)
        {
            swap(index2,index1);
        }


    for(int i=0;i<index1-1;i++)
    {
        if(A[index1-1]==A[i])
        {
            index1=i+1;
        }
    }

    for(int i=0;i<index2-1;i++)
    {
        if( index1!=(i+1) && A[index2-1]==A[i])
        {
            index2=i+1;
        }
    }
    res.push_back(min(index2,index1));
    res.push_back(index2+index1-res[0]);
    return res;
    }



    return vector<int> {};
}

int main()
{
    vector<int> A={4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    vector<int> res=twoSum(A,-3);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<"\n";
    }

}