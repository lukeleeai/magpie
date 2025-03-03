#include"stdc++.h"

using namespace std;



typedef long long ll;

typedef vector<int> vi;



#define Forn(i, n) for(int i=1; i<=(n); i++)

#define forn(i, n) for(int i=0; i<(n); i++)

#define lid id<<1|1

#define rid (id<<1)+2

#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it!=(a).end(); it++)

#define pb push_back

#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define mid l+r>>1

#define lson lid, l, mid

#define rson rid, mid, r 

#define f first

#define s second

#define int long long



const int MAX=1e5+5;



int N, M, ptr, ret, a[MAX];



struct Seg

{

    int tag1[MAX*4], tag2[MAX*4];

    Seg()

    {

        memset(tag1, 0, sizeof(tag1));

        memset(tag2, 0, sizeof(tag2));

    }

    inline void update(int id, int l, int r, int a, int b, int k1, int b1)

    {

       if(r<=a||b<=l) return;

       if(a<=l&&r<=b)

       {

           tag1[id]+=k1;

           tag2[id]+=b1;

           return;

       }

       update(lson, a, b, k1, b1);

       update(rson, a, b, k1, b1);

    }

    inline void update(int l, int r, int k1, int b1)

    {

        if(l>=r) return;

        update(0, 0, ptr, l, r, k1, b1);

    }

    inline void print(int id, int l, int r, int &ret)

    {

        if(l+1==r)

        {

            if(l) ret=min(ret, tag1[id]*l+tag2[id]);

            return;

        }

        

        tag1[lid]+=tag1[id];

        tag2[lid]+=tag2[id];

        

        tag1[rid]+=tag1[id];

        tag2[rid]+=tag2[id];

        

        print(lson, ret);

        print(rson, ret);

    }

}S;



signed main()

{

    scanf("%lld %lld", &N, &M);

    forn(i, N)

        scanf("%lld", &a[i]);

    ptr=M+1;

    

    forn(i, N-1)

    {

        if(a[i]==a[i+1]) continue;

        if(a[i]<a[i+1])

        {

            S.update(1, a[i]+1, 0, a[i+1]-a[i]);

            S.update(a[i]+1, a[i+1]+1, -1, a[i+1]+1);

            S.update(a[i+1]+1, ptr, 0, a[i+1]-a[i]);

        }

        else

        {

            S.update(1, a[i+1]+1, -1, a[i+1]+1);

            S.update(a[i+1]+1, a[i]+1, 0, M-a[i]+a[i+1]);

            S.update(a[i]+1, ptr, -1, M+a[i+1]+1);

        }

    }

    ret=2e18;

    S.print(0, 0, ptr, ret);

    printf("%lld\n", ret);

    return 0;

}