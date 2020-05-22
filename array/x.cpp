#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
bool comp(int i, int j) {
	return i < j;
}


bool mycompare(int a,int b)
{
   string sa=to_string(a);
   string sb=to_string(b);
   string ab=sa+sb;
   string ba=sb+sa;
   
   return stoll(ab)>stoll(ba);
}



string largestNumber( vector<int> &A) {


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
	std::vector<int> v = { 3, 5, 2, 4, 7 };

	//std::sort(v.begin(), v.end(), mycompare);

    string ans=largestNumber(v);

    cout<<ans<<"\n";

	for (const auto &i: v)
		std::cout << i << ' ';

	return 0;
}