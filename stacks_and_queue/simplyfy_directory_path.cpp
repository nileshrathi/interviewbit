 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;


string simplifyPath(string A) {
    stack<string> direc_stack;

    if(A[A.length()-1]!='/')
        A=A+"/";

    string delim="/";

    auto pos=0;
    
    while((pos=A.find(delim))!=std::string::npos)
    {
       string token=A.substr(0,pos);
       //cout<<token<<"\n";

       if(token=="..")
       {
           if(!direc_stack.empty())
           {
             //  cout<<"popping "<<direc_stack.top()<<"\n";
               direc_stack.pop();
               
           }
                 
       } 
       else if(token==".")
       {

       }
       else
       {
           if(token!="")
           {
               direc_stack.push(token);
               //cout<<token<<" pushing\n";
           }
           
           
       }

        A.erase(0,pos+delim.length());
    }



    //string res="";


    string res="/";
    while(!direc_stack.empty())
    {
        res=res.insert(0,"/"+direc_stack.top());
        direc_stack.pop();
    }
    if(res.length()>1)
        res=res.substr(0,res.length()-1);

    
    return res;
}


int main()
{
    cout<<simplifyPath("/a/b/c/d/");
}