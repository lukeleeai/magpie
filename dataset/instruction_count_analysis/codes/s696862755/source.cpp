#include <iostream>

#include <cstdio>

#include <set>

#include <map>

#include <stack>

#include <vector>

#include <queue>

#include <string>

#include <cstring>

#include <cmath>

#include <algorithm>

#define esp 1e-9

#define INF 0x3f3f3f3f

#define Pi acos(-1.0)

const int maxn = 1e3;

typedef long long ll;

using namespace std;

struct strstrstr

{

    string s;

};

strstrstr t[maxn];

bool cmp(struct strstrstr &a, struct strstrstr &b)

{

    return a.s < b.s;

}

int main()

{

    int n, l;

    cin>>n>>l;

    for(int i=0;i<n;i++)

    {

        string str;

        cin>>str;

        t[i].s = str;

    }

    sort(t, t+n, cmp);

    for(int i=0;i<n;i++)

        cout<<t[i].s;

    cout<<endl;

    return 0;

}
