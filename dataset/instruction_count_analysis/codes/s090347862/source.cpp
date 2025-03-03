#include"stdc++.h"

using namespace std;

//万合以致，向阳而生——背叛时代，忠于时间//

#pragma GCC optimize(3,"Ofast","inline")

typedef long long ll;

typedef pair<int,int> pi;

typedef vector<int> vi;

typedef unsigned long long ull;



#define f first

#define s second

#define pb push_back

#define mp make_pair

#define forn(i, n) for(register int i=0; i<n; i++)

#define Forn(i, n) for(register int i=1; i<=n; i++)

#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it!=(a).end(); it++)

#define Foreach(it, a) for(__typeof((a).rbegin()) it=(a).rbegin(); it!=(a).rend(); it++)

#define mid l+r>>1

#define lid id<<1|1

#define rid (id<<1)+2

#define lson lid, l, mid

#define rson rid, mid, r



inline int in()

{

    char c=getchar();

    int neg=1, x=0;

    while(!isdigit(c)) (c=='-')?neg=-1, c=getchar():c=getchar();

    while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48), c=getchar();

    return neg*x;

}

inline int lcm(int a, int b){return a*b/__gcd(a, b);}



const int MAX=20e5+5;



int N, M, ret, ptr, mark[MAX], fail[MAX], cnt[MAX];

char tt[MAX];

set<int> tmp;

string s, t;

vi v;



inline void kmp()

{

    fail[0]=ptr=-1;

    Forn(i, M)

    {

        while(ptr>-1&&t[ptr]!=t[i-1]) ptr=fail[ptr];

        fail[i]=++ptr;

    }

    

    ptr=0;

    forn(i, s.size())

    {

        while(ptr>-1&&s[i]!=t[ptr])

            ptr=fail[ptr];

        ptr++;

        if(ptr>=M) mark[i-M+1]=1;

    }

}



int main()

{

    memset(cnt, -1, sizeof(cnt));

    scanf("%s", tt); s=tt;

    scanf("%s", tt); t=tt;

    while(s.size()<t.size()) s+=s;

    N=s.size(), M=t.size();

    s+=s;

    

    kmp();

    forn(i, N) if(cnt[i]==-1)

    {

        int p=i, c=0;

        tmp.clear();

        while(mark[p])

        {

            if(tmp.count(p))

            {

                puts("-1");

                return 0;

            }

            if(~cnt[p])

            {

                c=cnt[p];

                break;

            }

            v.pb(p), tmp.insert(p);

            p=(p+M)%N;

        }

        if(!v.size()) cnt[i]=0;

        else

        {

            c++;

            while(v.size())

                cnt[v.back()]=c,

                c++, v.pop_back();

            ret=max(ret, c-1);

        }

    }

    printf("%d\n", ret);

    return 0;

}

// baaab

//abaaba
