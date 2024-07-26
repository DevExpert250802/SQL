//  https://codeforces.com/problemset/problem/1165/D

/*
                                                 Almost All Divisors
time limit per test2 seconds
memory limit per test256 megabytes
We guessed some integer number x. You are given a list of almost all its divisors. Almost all means that there are all divisors except 1 and x in the list.

Your task is to find the minimum possible integer x that can be the guessed number, or say that the input data is contradictory and it is impossible to find such number.

You have to answer t independent queries.

Input
The first line of the input contains one integer t (1≤t≤25) — the number of queries. Then t queries follow.

The first line of the query contains one integer n (1≤n≤300) — the number of divisors in the list.

The second line of the query contains n integers d1,d2,…,dn (2≤di≤106), where di is the i-th divisor of the guessed number. It is guaranteed that all values di
 are distinct.

Output
For each query print the answer to it.

If the input data in the query is contradictory and it is impossible to find such number x that the given list of divisors is the list of almost all its divisors, print -1. Otherwise print the minimum possible x.





  */


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/*
    author    : Devansh
    created   : Friday 2024-07-26
    problem   : 1165 D. Almost All Divisors
*/

/*
add:                     Adds two numbers modulo mod.
sub:                    Subtracts two numbers modulo mod.
mul:                     Multiplies two numbers modulo mod.
isprime:                   Checks if a number is prime.
allprimebetween:          Finds all prime numbers between two given numbers.
getfreq:                  Gets the frequency of each character in a string.
YES:                       Prints "YES".
NO:                        Prints "NO".
getfactors:                Gets all factors of a number.
ispalindrome:             Checks if a string is a palindrome.
ncrmodp:                  Computes nCr % p using dynamic programming.
gethighestoddfactor:      Gets the highest odd factor of a number.
issorted:                 Checks if an array is sorted.
power:                    Computes x^y % p using binary exponentiation.
getarraygcd:              Computes the GCD of an array.
modulo_div:               Computes a / b % mod using modular inverse.
ncrfact:                  Computes nCr using factorials (not fully implemented).
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#define ull unsigned long long int // Corrected definition
#define ll long long int
#define eb emplace_back
#define pb push_back
#define mod 1000000007 
#define setull set <ull> 
#define mapull map<ull,ull>
#define pairull pair<ull,ull>
#define vull vector <ull>
#define vecpair vector<pair<ull,ull>>
#define printi(v) for(auto i : v) cout<<i<<" "; cout<<nw;
#define printj(v) for(auto j : v) cout<<j<<" "; cout<<nw;
#define printk(v) for(auto k : v) cout<<k<<" "; cout<<nw;
#define repi(s,e,t) for(ull i=s;i<=e;i+=t)
#define repj(s,e,t) for(ull j=s;j<=e;j+=t)
#define repk(s,e,t) for(ull k=s;k<=e;k+=t)
#define rep(v,s,e,t) for(ull v=s;v<=e;v+=t)
#define rev_rep(v,s,e,t) for(ull v=s;v>=e;v-=t)
#define rev_repi(s,e,t) for(ull i=s;i>=e;i-=t)
#define rev_repj(s,e,t) for(ull j=s;j>=e;j-=t)
#define rev_repk(s,e,t) for(ull k=s;k>=e;k-=t)
#define rev_str(s) reverse(s.begin(),s.end())
#define rev_vec(v) reverse(v.begin(),v.end())
#define rev_arr(a,n) reverse(a,a+n)
#define sort_str(s) sort(s.begin(),s.end())
#define sort_vec(v) sort(v.begin(),v.end())
#define sort_arr(a,n) sort(a,a+n)
#define sort_dec_str(s) sort(s.rbegin(),s.rend())
#define sort_dec_vec(v) sort(v.rbegin(),v.rend())
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
#define nw '\n'






ull add(ull x,ull y)
{
    ull ans=(((x%mod)+(y%mod))%mod);
    if(ans<0)
    {
        ans+=mod;
    }
    return ans;
}


ull sub(ull x,ull y)
{
    ull ans=(((x%mod)-(y%mod))%mod);
    if(ans<0)
    {
        ans+=mod;
    }
    return ans;
}


ull mul(ull x,ull y)
{
    ull ans=(((x%mod)*(y%mod))%mod);
    return ans;
}


bool isprime(ull n)
{
    if(n==1)
    {
        return false;
    }
    repi(2,sqrt(n),1)
    {
        if(n%i==0) 
        { 
            return false; 
        }
    }
    return true;
}


vector<ull> allprimebetween(ull l,ull r)
{
    vector<bool> v(1000005,true);
    v[0]=v[1]=false;
    for(ull i=2;i*i<=1000001;i++)
    {
        if(v[i])
        {
            for(ull j=i*i;j<=1000001;j+=i)
            {
                v[j]=false;
            }
        }
    }
    vector<ull> prime;
    for(ull i=l;i<=r;i++)
    {
        if(v[i])
        {
            prime.pb(i);
        }
    }
    return prime;
}


map<ull,ull> getfreq(string s)
{
    map<ull,ull> mp;
    for(ull i=0;i<s.size();i++)
    {
        mp[s[i]-'a']++;
    }
    return mp;
}


void YES()
{
    cout<<"YES"<<nw;
}


void NO()
{
    cout<<"NO"<<nw;
}


vector<ull> getfactors(ull n)
{
    vector<ull> v;
    for(ull i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            if((n/i)!=i)
            {
                v.pb(n/i);
            }
            else
            {
                break;
            }
        }
    }
    sort_vec(v);
    return v;
}


bool ispalindrome(string s)
{
    string t(s.rbegin(),s.rend());
    return s==t;
}


ull ncrmodp(ull n, ull r, ull p)
{
    if(r>(n-r))
    {
        r=n-r;
    }
    ull C[r+1];
    memset(C,0,sizeof(C));
    C[0]=1; 
    repi(1,n,1)
    {
        rev_repj(min(i,r),1,1)   //for (ull j = min(i, r); j > 0; j--)
        {
            C[j]=((C[j]+C[j-1])%p);
        }
    }
    return C[r];
}


ull gethighestoddfactor(ull n)
{
    while(n>0)
    {
        if(n%2!=0)
        {
            return n;
        }
        n=n/2;
    }
    return 1;
}


bool issorted(ull a[],ull n)
{
    ull b[n];
    repi(0,n-1,1)
    {
        b[i]=a[i];
    }
    sort_arr(b,n);
    repi(0,n-1,1)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}


ull power(ull x,ull y,ull p)
{
    ull res=1;   
    x=x%p; 
    if(x==0) return 0;
    while(y>0)
    {
        if(y%2!=0)
        {
            res=mul(res,x);
        }
        x=mul(x,x);
        y=(y/2);
    }
    return res;
}


ull getarraygcd(ull a[],ull n)
{
    ull ans=a[0];
    repi(0,n-1,1)
    {
        if(a[i]==0)
        {
            continue;
        }
        ans=__gcd(ans,a[i]);    
    }
    return ans;
}


ull modulo_div(ull a,ull b)
{
    return mul(a,power(b,mod-2,mod));
}
ull ncrfact(ull n,ull r)
{
    if(r==0 || r==n)
    {
        return 1;
    }
    // ull d=mul(fact[n-r],fact[r]);
    // return mul(fact[n],power(d,mod-2,mod));
}



int main()
{
    fio;

    ull testcases;
    cin>>testcases;
    while(testcases--)
    {
        ull n;
        cin>>n;
        vector<ull> a(n);
        for(ull i=0;i<n;i++)
        {
            cin>>a[i];
        }   
        sort_vec(a);
        ull originalnum=a[0]*a[n-1];
        vector<ull> b;
        for(ull i=2;i<=sqrt(originalnum);i++)
        {
            if(originalnum%i==0)
            {
                b.push_back(i);
                if(i!=(originalnum/i))
                {
                    b.push_back(originalnum/i);
                }
            }
        }
        sort_vec(b);
        if(a==b)
        {
            cout<<originalnum<<nw;
        }
        else
        {
            cout<<-1<<nw;
        }
    }
    return 0;   
} 




