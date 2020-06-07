 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;

int braces(string A) {

    stack<char> s;

    int redundant=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='(')
            s.push('(');
        else if(A[i]=='+'||A[i]=='-'||A[i]=='*'||A[i]=='/')
            s.push('e');
        else if(A[i]==')')
        {
            if(s.empty() || s.top()!='e')
            return 1;
        while(!s.empty() && s.top()!='(')
            s.pop();
        s.pop();
            
        }
    }
    return redundant;

}

int main()
{
    cout<<braces("(((a)))");
}
