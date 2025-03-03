#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <cmath>

#include <vector>

#include <stdio.h>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <queue>

#include <ctime>

#include <cassert>

#include <complex>

#include <string>

#include <cstring>

#include <chrono>

#include <random>

#include <queue>

#include <bitset>

#include <iomanip>

using namespace std;





typedef long long ll;

//typedef pair<string, int> pii;

//typedef pair<ll, ll> pll;

typedef vector<int> vi;

//typedef vector<pii> vpi;

typedef vector<vi> vvi;

typedef pair <int,int> pii;

typedef pair <int,pii> pi;

#define fi first

#define se second

#define pb push_back

#define szz(x) (int)x.size()

#define rep(i,n) for(int i=0;i<n;i++)

#define all(x) x.begin(),x.end()

#define sv(v) sort(v.begin(),v.end())

#define floop(a,n) for(int i=a; i<n; i++)

#define max3(a,b,c) max(a, max(b,c))

#define max4(a,b,c,d) max(a, max(b,max(c,d)))

#define min3(a,b,c) min(a, min(b,c))

#define min4(a,b,c,d) min(a, min(b,min(c,d)))

vector <int> v;

string int_to_string(int a){return to_string(a);}

int string_to_int(string s){stringstream x(s);int a=0; x>>a; return a;}

//long long int gcd(long long int a, long long int b){if(a%b==0)return b;return gcd(b, a%b);}

//long long int lcm(long long int a, long long int b){return (a*b)/gcd(a, b);}



//long long int factorial(int a){if(a==0)return 1;elsereturn a*factorial(a-1);}







int main()

{

    map <string,int>mp;

    

    int a,b,c,max=0;

    string s,p;

    

    cin >> a;

    while(a--)

    {

        cin >> s;

        mp[s]++;

    }

    

    cin >> a;

    while(a--)

    {

        cin >> s;

        mp[s]--;

    }

    

    for(auto it = mp.cbegin(); it!=mp.cend(); ++it)

    {

        if(it -> second > max)

            max = it -> second;

    }

    

    cout << max << endl;

    

}


