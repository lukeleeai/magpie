#include "stdc++.h"

#define ll long long

#define pb push_back

#define mp make_pair

int cnt[501];

bool was[501];

using namespace std;

int N;

bool can = true;

int a[250001];

int pos[500];

vector<pair<int , int> > g;

int main()

{

    memset(a , -1 , sizeof a);

    scanf("%d" , &N);

    for(int i = 1; i <= N; i++)

    {

        cnt[i] = 1;

        int x;

        scanf("%d" , &x);

        pos[i] = x;

        a[x] = i;

        g.pb(mp(x , i));

    }

    sort(g.begin() , g.end());

    for(int i = 0; i < g.size(); i++)

    {

        int curPos = g[i].first;

        int x = g[i].second;

        int cur = x;

        for(int i = 1; i < curPos; i++)

        {

            if(a[i] != -1)

                continue;

            if(cnt[cur] < cur)

            {

                a[i] = cur;

                cnt[cur]++;

            }

        }

        if(cnt[cur] != cur)

        {

            printf("No");

            return 0;

        }

    }

    for(int i = 1; i <= N; i++)

    {

        for(int j = pos[i] + 1; j <= N * N; j++)

        {

            if(a[j] != -1)

                continue;

            if(cnt[i] < N)

            {

                a[j] = i;

                cnt[i]++;

            }

        }

        if(cnt[i] < N)

        {

            printf("No");

            return 0;

        }

    }

    if(!can)

    {

        printf("No");

        return 0;

    }

    printf("Yes\n");

    for(int i = 1; i <= N * N; i++)

        printf("%d " , a[i]);

}
