#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int isNumber(const string A) {
    string s=A;
//remov  white spaces
    while(s[0]==' ') s.erase(s.begin());
    bool sign=false;
      if(s[0]=='-' || s[0]== '+')
        {
            sign=true;
            s.erase(s.begin());
        }

    int index=0;
    bool first_num=false;
    while( index<s.length() && s[index]>='0' && s[index]<='9')
    {
        first_num=true;
        index++;
    }
    bool decimal=false;

    if(s[index]=='.')
    {
        decimal=true;
        index++;
    }
    bool sec_num=false;
    while( index<s.length() && s[index]>='0' && s[index]<='9')
    {
        sec_num=true;
        index++;
    }

    bool exp=false;

    if(s[index]=='e')
    {
        exp=true;
        index++;
    }

    if(s[index]=='+' || s[index]=='-')
    {
        index++;
    }
    bool third_num=false;
    while( index<s.length() && s[index]>='0' && s[index]<='9')
    {
        third_num=true;
        index++;
    }
    while(index<s.length() && s[index]==' ') index++;

    int ans=0;
    if(index==s.length())
    {
        if(first_num==true)
        {
            if(decimal==false || (decimal==true && sec_num== true))
            {
                if(exp==false || (exp==true && third_num== true))
                {
                    ans=1;
                }
            }
            
        }
        else
        {
            if((decimal==true && sec_num== true))
            {
                if(exp==false || (exp==true && third_num== true))
                {
                    ans=1;
                }
            }
        }
        
    }

        return ans;
    
}
int main()
{
    cout<<isNumber("32467826570812365702673647926314796457921365792637946579269236594265794625762375621765476592146926410592659021465904652.687236478235187653874637824647856428756387264578245676579032657906097542609  ");
    cout<<isNumber("0.1e10");
    cout<<isNumber("3e0.1");
    cout<<isNumber("1u");
    cout<<isNumber("-01.1e-10");
}
