 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

int factorial(int n) {
    if (n > 12) return INT_MAX;
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

void find(string &ans,vector<int> &num_seq, int k)
{
    //cout<<"hello";
    if(num_seq.size()==0)
        {
            
            return;
        }
    
    
    
    int fact_n_minus_1= factorial(num_seq.size()-1);
    int swap_elem_index=k/fact_n_minus_1;
   // cout<<num_seq.size()<<" "<<swap_elem_index<<"\n";
    ans=ans+to_string(num_seq[swap_elem_index]);
    num_seq.erase(num_seq.begin()+swap_elem_index);
    find(ans,num_seq,k%fact_n_minus_1);
    return;
}


string getPermutation(int A, int B) {
    B--;
    string ans="";
    int k=B;
    vector<int> num_seq;
    for(int i=1;i<=A;i++)
    {
        num_seq.push_back(i);
    }
    find(ans,num_seq,k);
    return ans;


}


int main()
{
    cout<<getPermutation(3,4);
}