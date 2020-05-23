#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<string> fullJustify(vector<string> &A, int B) {

vector<string> ans;

vector<vector< string> > ans_vec;
int l=0;
int i=0;
bool first=true;
int line=0;
vector<int>space_count;
while(i<A.size())
{   
    vector<string> temp;
    //push the first string;
    temp.push_back(A[i]);

    int l=A[i].length();
    int j=i+1;
    int space_left=B;
    space_left=space_left-l;
    while(j<A.size() && l<B)
    {
        int curr_string_len=1+A[j].length();
        if((l+curr_string_len)<=B)
        {
            space_left=space_left-curr_string_len+1;
            temp.push_back(A[j]);
            l=l+curr_string_len;
            j++;
        }
        else
        {
            
            break;            
        }
        
    }
    

    //cout<<"space left "<<space_left<<"\n";
    space_count.push_back(space_left);
    ans_vec.push_back(temp);
    i=j;
    line++;
    
}

vector<vector<int> > spaces;

for(int i=0;i<ans_vec.size()-1;i++)
{
    int number_of_spaces=ans_vec[i].size()-1;
    
    int x,extra;
    if(number_of_spaces!=0)
    {
        x=space_count[i]/number_of_spaces;
        extra=space_count[i]%number_of_spaces;   
    }
    else
    {
        x=0;
        extra=0;
    }

    vector<int> temp;
    for(int i=0;i<number_of_spaces;i++)
    {
        if(i<extra)
        {
            temp.push_back(x+1);
        }
        else
        {
            temp.push_back(x);
        }
        
    }
    spaces.push_back(temp);
}


for(int i=0;i<ans_vec.size()-1;i++)
{
    int k=0;
    string temp="";
    for(int j=0;j<ans_vec[i].size();j++)
    {
        temp=temp+ans_vec[i][j];
        string sp="";
        if(j<spaces[i].size())
        {
            for(int x=0;x<spaces[i][j];x++)
            {
                sp=sp+" ";
            }
        }
        temp=temp+sp;
    }
    while(temp.length()<B) temp=temp+" ";
    ans.push_back(temp);
}

string temp=ans_vec[ans_vec.size()-1][0];
int count=ans_vec[ans_vec.size()-1][0].length();
for(int i=1;i<ans_vec[ans_vec.size()-1].size();i++)
{
    count=count+ans_vec[ans_vec.size()-1][i].length()+1;
    temp=temp+" "+ans_vec[ans_vec.size()-1][i];
}
if(count!=0)
    count=B-count;;
while(count--)
{
    temp=temp+" ";
}
ans.push_back(temp);

return ans;
}


int main()
{
    vector<string> A={""};
    int L=10;
    vector<string> x=fullJustify(A,L);

    for(int i=0;i<x.size();i++)
    {
        cout<<x[i]<<"yaha"<<"\n";
    }
    return 0;
}