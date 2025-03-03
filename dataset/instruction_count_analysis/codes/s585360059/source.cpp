/*

    把h*w矩形分为三部分,求最大面积与最小面积之差最小值

    首先,n或m为三的倍数,面积差最小值为0

    其次,暴力枚举所有情况

    先将矩形,分为两部分,横切或者竖切,剩下的那块对半分

    最大h*w会爆int

*/

#include<cstdio>

#include<algorithm>

using namespace std;

typedef long long ll;

const ll inf = 9e18;

ll Max(ll a,ll b,ll c){

    return max(a, max(b, c));

}

ll Min(ll a,ll b,ll c){

    return min(a, min(b, c));

}

int main(){

    ll h, w, ans;

    scanf("%lld%lld", &h, &w);

    if(!(h%3)||!(w%3)){

        puts("0");

        return 0;

    }

    ans = inf;

    for (ll i = 1; i < h;i++){

        ll tmp = h - i;//剩下部分

        ll h1 = (tmp + 1) / 2;  //向上取整

        ll h2 = tmp / 2;//向下取整

        //为1时不能再横切

        if(tmp!=1){

            ans=min(ans,Max(i*w,h1*w,h2*w)-Min(i*w,h1*w,h2*w));

        }

        ll w1 = (w + 1) / 2;

        ll w2 = w / 2;

        //竖切,w初始为2

        ans=min(ans,Max(i*w,tmp*w1,tmp*w2)-Min(i*w,tmp*w1,tmp*w2));

    }

    for (ll i = 1; i < w;i++){

        ll tmp = w - i;//

        ll w1 = (tmp + 1) / 2;  //向上取整

        ll w2 = tmp / 2;//向下取整

        if(tmp!=1){

            ans=min(ans,Max(i*h,w1*h,w2*h)-Min(i*h,w1*h,w2*h));

        }

        ll h1 = (h + 1) / 2;

        ll h2 = h / 2;

        ans=min(ans,Max(i*h,tmp*h1,tmp*h2)-Min(i*h,tmp*h1,tmp*h2));

    }

    printf("%lld", ans);

    return 0;

}