#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m=1000000007;


// C++ program to compute LCM of array elements modulo M 
#include <bits/stdc++.h> 
#define F first 
#define S second 
#define MAX 10000003 
using namespace std; 
  
typedef long long ll; 
const int mod = 1000000007; 
  
int prime[MAX]; 
unordered_map<int, int> max_map; 
  
// Function to return a^n 
int power(int a, int n) 
{ 
    if (n == 0) 
        return 1; 
    int p = power(a, n / 2) % mod; 
    p = (p * p) % mod; 
    if (n & 1) 
        p = (p * a) % mod; 
    return p; 
} 
  
// Function to find the smallest prime factors 
// of numbers upto MAX 
void sieve() 
{ 
    prime[0] = prime[1] = 1; 
    for (int i = 2; i < MAX; i++) { 
        if (prime[i] == 0) { 
            for (int j = i * 2; j < MAX; j += i) { 
                if (prime[j] == 0) { 
                    prime[j] = i; 
                } 
            } 
            prime[i] = i; 
        } 
    } 
} 
  
// Function to return the LCM modulo M 
ll lcmModuloM(const int* ar, int n) 
{ 
  
    for (int i = 0; i < n; i++) { 
        int num = ar[i]; 
        unordered_map<int, int> temp; 
  
        // Temp stores mapping of prime factor to 
        // its power for the current element 
        while (num > 1) { 
  
            // Factor is the smallest prime factor of num 
            int factor = prime[num]; 
  
            // Increase count of factor in temp 
            temp[factor]++; 
  
            // Reduce num by its prime factor 
            num /= factor; 
        } 
  
        for (auto it : temp) { 
  
            // Store the highest power of every prime 
            // found till now in a new map max_map 
            max_map[it.first] = max(max_map[it.first], it.second); 
        } 
    } 
  
    ll ans = 1; 
  
    for (auto it : max_map) { 
  
        // LCM is product of primes to their highest powers modulo M 
        ans = (ans * power(it.F, it.S)) % mod; 
    } 
  
    return ans;

}




ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b); 
}

ll power(ll x,ll y)
{
    if (y == 0) 
        return 1; 
    int p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}

ll modInverse(ll a) 
{ 
 
 return power(a, m-2); 
}

int findminrotations(string s)
{
    
    ll n=s.length();

    if(n==1)
    {
        return 1;
    }
  //  cout<<"yaha";
    vector<ll> lps(n,0);
    lps[0]=0;

    ll i=1;
    ll len=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }

    ll size=lps[n-1];

    if(n%(n-size)==0)
    {
        n=n-size;
    }

    
  //  cout<<"yaha"<<size;
    for(ll i=1;i<n;i++)
    {
        ll temp=(i*(i+1))/2;
        if(temp%n==0)
        {
            return i;
        }
    }

    return n;
    
    

}

int solve(vector<string> &A)
{

    ll n=A.size();
    
    vector<ll> lcm(n);
    for(ll i=0;i<n;i++)
    {

        lcm[i]=findminrotations(A[i]);
        cout<<"rot "<<lcm[i]<<"\n";
    }
    
    // ll a=lcm[0];


    // for(ll i=1;i<n;i++)
    // {
    //     ll gc=gcd(a,lcm[i]);
    //     ll mul=(a*lcm[i]);
    //     ll modIngcd;

    //    // if(mul%gc==0)
    //     {
    //        // modIngcd=gc;
    //          a=mul/gc;
            
    //     }
    //     // else
    //     // {
    //     //         modIngcd=modInverse(gc);
    //     //          a=(mul*modIngcd)%m;
    //     // }
        

    //    // cout<<"mul "<<mul<<" gcd "<<gc<<"\n";
    //     //a=mul/gc;
    
    
    // }
    //  a=a%m;
    
    
    // return a;
    // ll res=1;
    // for(int i=0; i<lcm.size(); i++)
    // {
    //     for(int j=i+1; j<lcm.size(); j++)
    //         lcm[j] = lcm[j]/__gcd(lcm[i], lcm[j]);
            
    //     res = (res*lcm[i])%m;
    // }
    // return res;


    int arr[lcm.size()];
    for (int i=0;i<lcm.size();i++)
    {
        arr[i]=lcm[i];
    }
    //std::copy(lcm.begin(),lcm.end(),arr);
    return lcmModuloM(arr,lcm.size());

}


int main()
{
    vector<string> A{"babbaabbbaabababbbbbaaabbaabaabbaaabaaaaabbbabababbabbaa", "aabababbbaabaabbbaaaabaaabbbbaababbbaaabaaabababaabaaaaaba", "aaabaaababbbbabaaabaabbbbbbaabaababbaaaab", "baaababaa", "baabbababbabbaaaababbabbaabbaabaabbbbabbbaaaaaaabbbababbbbbbbabbbaabaaabaaaaaaaabbaaba", "abbaabbbaabbabbabbabaabaaaaaaaaabbabaaabaaaabaabbaabbabbaabaaabab", "bababbababbaabbbaababbaaaaabaaaaaaabbaabbaaabbbbba", "abbababaabbabbaaaaaaaaaabbbbabaaaaaaabaaabbbabbbaabaabaaabbaabaabaababaaabababaa", "baaaaaabbabaaaaaababbbaabbbabbaaaa", "aaaababbabbaabbbaabbbaabbbbbbbbabbaabbabbbaba", "abbaaaaaba", "bbbabbaabaaaabba", "aaabbbbbbbbbbbabaaabaaab", "abaabbaaabbbabbaaabbaabaaabbaabbbbbbbbbbbaabbbbabbbbbbaabbbababaaabbbaaabaaaababa", "babbaaababbbbbbbabbababbbbbbabbbbaabbaabbabbb", "aabbabababababbaaaababbabbaaa", "aaaababbabaabbbabaabbabababbabbabbababaabba", "aaabaaabbbbabbbbaba", "aabaabababbabbbbbaaabbabaaabbabbbaabbaaabbaaaabbababbaabababbbbabbbbbbbbabbabbabaabbabbbaba", "bbaaaabababaaaabbabaaabbbaaaaaabaabaabaabbabaabbbabbababbabbbbabaababaaabaabbbbababbbaabaaabbbabbaa", "aaabbababaaaabbababaabbbaab", "abbababaaaaaaaabaabbaababbbababbbbbbbabbbabbaa", "aabaabbababbbaaabbbaaaaababaabbbbabbaabbbbaababaaabaababbaabbbabbbabaaabbababaabbbbbaabbabbbaba", "bbbbbbaaababaaababaabbababbaababababaabaabbaabbabbaabaabbbaaaabbbaabaaaabbab", "bbabaaaaababbaabbbabbaabaabb", "aaaaababbabbabaabaaaabbabbaaaabaababbaaabbbbaa", "baababb", "babbabaa", "bbbabbbaaaabaaaaaabbbaabbbbbbbbbaababaabbaababaabbaababaaabbbaaaaaaba", "bbbbbbababaabbaabaabaabaaaaabbaaababbaabaab", "bbabaaaaabaabbababbaababaaaabbbabbbb", "bbabbbaabbaabbbabaabbaaaabbbaabababbbbbabababaaaabbbbaabbbbba", "bbaaabaaababbbbbbbaabaabb", "aababaabbabbabaaabbbaaabbbbbaabbbabaabbbaaaababbbaaabbbaaabbaaababbbbbabbbbbbaabbbbaaaaaab", "aabaabbbaaababababbbaaaaaaabababbabababbbbabaaabbbababbabbbababaaaabaaabbaaaaabaabbaabaaaaabab", "ababbabbabbababbaababaabaabaaaaababababbbbbbbaababbbbbaaabaabab", "aabbbaaabbbababababbaababbabbbbbaabbbbbabbbabaaababba", "bbbbaabaabababababababbaaaabbaaaabaaabaaabbaabbababbbbbbbabbabbaabbaabaaa", "abbabaabbbaabbaaabbabbbaaaaaaaabbbbbbbaaaaabbbbaaaababaabaaaaababa", "abbabbbbaaaaababbabbbbbbaaaabababaabbbabbaabbaba", "abaabbabaaaabaabbbaabbabbbbaababbabaabbabbaaaabbbbbaabaabbabaaabbbbbaabbabbaaab", "baaaaaabbaababbbaaabbbabbabbaaaaaaaa", "abbaababaabaaabababbbabbababbabbabbaaabaaaaabaaaabb", "babaabbbaababaababbababaabaabbaaaaaabbbbaabbbbbbaaaaabaaabbbabaabaaba", "aaaabbbababbabaaaabbaaaaaaabbabbabbabbaabbbbbbb"};
    cout<<solve(A);

}