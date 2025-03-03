

#include "stdc++.h"

#define FRU                                  freopen("out.txt","w",stdout);

#define FRO                                  freopen("in.txt","r",stdin);

#define pb                                   push_back

#define pf                                   push_front

#define ppb                                  pop_back()

#define ppf                                  pop_front()

#define mp                                   make_pair

#define ff                                   first

#define ss                                   second

#define flash                                ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

#define mem(ara,n)                           memset(ara,n,sizeof ara)

#define fr(i,j,n)                            for(i=j;i<n;i++)

#define rf(i,j,n)                            for(i=n;i>=j;i--)

#define inf                                  2147483647

#define ll                                   long long

#define ull                                  unsigned long long

#define pii                                  pair<int,int>

#define vi                                   vector<int>

#define vll                                  vector <long long>

#define vch                                  vector <char>

#define itr                                  ::iterator

#define msi                                  map<string,int>

#define psi                                  pair <string,int>

#define vii                                  vector <pair<int,int> >

#define all(n)                               n.begin(),n.end()

#define INF                                  10000000000000000LL

#define pi                                   3.1415926535897932384626434

#define sii                                  set <int>

#define max3(a,b,c)                          max(a,max(b,c))

#define min3(a,b,c)                          min(a,min(b,c))

#define mid3(a,b,c)                          min(max(a,b),max(b,c),max(a,b))

#define max4(a,b,c,d)                        max(max(a,b),max(c,d))

#define min4(a,b,c,d)                        min(min(a,b),min(c,d))

#define endl                                 '\n'

#define endll                                cout<<"\n";

#define spc                                  ' '

#define ld                                   long double



using namespace std;







int main()

{

    flash

    string s,st;

    ll n,t,T,i,j,J,I,k,m;

    char ch;

    cin>>n;

    m=0;

    fr(i,1,n+1)

    {

        if(i%3==0||i%5==0)  continue;

        m+=i;

    }

    cout<<m;

    return 0;

}


