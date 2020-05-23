#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string convert(string A, int B) {

    int n=A.length();
    string ans="";

    int i=0;
    int direction=1; //true=down flase=up

    ans="";

    int row=0;

    while(row<B)
    {
        int i=row;
        while(i<n)
        {
            
            int next_index;
            if(direction==1)
            {
                cout<<"down\n";
                next_index=2*(B-row-1);
            } 
            else if(direction==0)
            {
                cout<<"up\n";
                next_index=2*row;
            }
            
            if(next_index!=0)
                ans=ans+A[i];
            i=i+next_index;
            direction=1-direction;
        }
        row++;
    }

    return ans;
    
}

int main()
{
    cout<<convert("ABCDEFGHIJKLMNOPQRS",6);     //AKBJLCIMSDHNREGOQFP

}