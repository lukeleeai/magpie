/*|In The Name Of Allah|*/



#include "stdc++.h"



using namespace std;



const int N = 2e5+5;



int n;

int d;

int a;

long long add[N];

pair < int , int > monster[N];



int main(){

    scanf("%d%d%d" , &n , &d , &a);

    for(int i = 0; i < n; i++){

        int x , h;

        scanf("%d%d" , &x , &h);

        monster[i] = {x , h};

    }

    sort(monster , monster + n);

    long long ans = 0 , cur = 0;

    for(int i = 0; i < n; i++){

        long long need = (monster[i].second + a - 1) / a;

        cur += add[i];

        if(need < cur)

            continue;

        long long extra = need - cur;

        cur += extra;

        int idx = upper_bound(monster , monster + n , make_pair(monster[i].first + 2 * d + 1, -1)) - monster;

        ans += extra;

        add[idx] -= extra;

    }

    printf("%lld\n" , ans);

}
