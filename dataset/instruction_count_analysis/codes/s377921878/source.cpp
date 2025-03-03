#include <set>

#include <map>

#include <deque>

#include <queue>

#include <stack>

#include <cmath>

#include <ctime>

#include <bitset>

#include <cstdio>

#include <string>

#include <vector>

#include <cstdlib>

#include <cstring>

#include <cassert>

#include <iostream>

#include <algorithm>

#define mem(a,b) memset(a,b,sizeof (a))

#define gcd(a,b) __gcd(a,b)

#define all(a) a.begin(),a.end()

#define sz(s) s.size()

#define endl '\n'

#define pb push_back

typedef long long ll;

const int maxn=200010;

const int inf=1e9;

const ll mod=998244353;

const double pi=3.14159265358979;

const double ep=0.0;

using namespace std;

int a[2*maxn],b[maxn],c[2*maxn];

int main()

{

    int n;

    cin>>n;

    int xora=0,xorb=0;

    for (int i=0;i<n;i++)

    {

        cin>>a[i];

        a[i+n]=a[i];

        xora^=a[i];

    }

    for (int i=0;i<n;i++)

    {

        cin>>b[i];

        xorb^=b[i];

    }

    c[0]=a[0];

    for (int i=1;i<2*maxn;i++)

        c[i]=c[i-1]^a[i];

    vector<pair<int,int>>vec;

    for (int i=0;i<n;i++)

    {

        set<int>se;

        int t=20,r=xora^xorb;

        while (t--)

        {

            int x=rand()%n;

            se.insert(x);

        }

        map<int,int>ma;

        for (auto j:se)

        {

            ma[a[i+j]^b[j]]++;

            if (sz(ma)>1)

                break;

        }

        if (sz(ma)==1&&r==0)

            vec.pb(make_pair(i,(*(ma.begin())).first));

        else if (sz(ma)==1&&(*(ma.begin())).first==r)

            vec.pb(make_pair(i,r));

    }

    for (auto i:vec)

        cout<<i.first<<' '<<i.second<<endl;

    return 0;

}
