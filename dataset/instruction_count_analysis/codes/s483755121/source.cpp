#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#include <time.h>

#include <iostream>

#include <algorithm>

#include <string>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <bitset>

#include <vector>

using namespace std;



#define bll long long

#define dou double

#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)

#define Rof(i,a,b) for (int i=(a),_##i=(b); i>=_##i; --i)

#define Mem(a,b) memset(a,b,sizeof(a))

#define Cpy(a,b) memcpy(a,b,sizeof(b))



const int maxn=2e5+100;

int N;

char s[maxn];

int match[maxn];

vector <int> pos[30];

int tr[maxn];



void add(int x,int v,int len,int a[])

{

    for (int i=x; i<=len; i+=(i&(-i))) a[i]+=v;

}



int que(int x,int a[])

{

    int ret=0;

    for (int i=x; i; i-=(i&(-i))) ret+=a[i];

    return ret;

}



long long solve()

{

    static int p[maxn];

    static int num[maxn];

    long long ans=0;

    int tot=0;

    int m=0;

    For(i,1,N)

    {

        if (match[i]>i)

        {

            num[i]=num[match[i]]=++tot;

            ans+=i-tot;

        }

        else if (match[i]<i)

        {

            p[++m]=num[i];

        }

        else

        {

            p[++m]=(N>>1)+1;

        }

    }

    memset(tr,0,sizeof(tr[0])*(m+2));

    For(i,1,m)

    {

        ans+=que(p[i],tr);

        add(p[i],1,m,tr);

    }

    return ans;

}



int main()

{

    for (; scanf("%s",s+1)!=EOF; )

    {

        N=strlen(s+1);

        For(i,0,25) pos[i].clear();

        For(i,1,N) pos[s[i]-'a'].push_back(i);

        int odd=0;

        For(i,0,25)

        {

            if (((int)pos[i].size())&1) ++odd;

            int j=0,k=pos[i].size()-1;

            for (; j<=k; ++j,--k) match[pos[i][j]]=pos[i][k],match[pos[i][k]]=pos[i][j];

        }

        if (odd>1)

        {

            printf("-1\n");

        }

        else

        {

            printf("%lld\n",solve());

        }

    }

    return 0;

}
