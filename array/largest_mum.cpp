#include<iostream>
#include<bits/stdc++.h>
#include<string>
typedef long long int ll;
bool mycompare(int a,int b)
{
   string sa=to_string(a);
   string sb=to_string(b);
   string ab=sa+sb;
   string ba=sb+sa;
   
   if(stoll(ab)>stoll(ba))
        return true;
    else 
        return false;
}

string largestNumber(const vector<int> &A) {
    sort(A.begin(),A.end(),mycompare);
    
    string solution=to_string(A[0]);
    
    for(int i=1;i<A.size();i++)
    {
        solution=solution+to_string(A[i]);
    }
    
    return solution;
}


int main()
{

    vector<int> a={52,157};
    string s=largestNumber(a);
    cout<<s;
    return 0;

}
