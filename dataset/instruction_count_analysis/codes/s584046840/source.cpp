#include <iostream>

#include <string>

#include <set>

#include <cmath>

#include <vector>

#include <algorithm>

using namespace std;

using ll =long long;

typedef long double ld;

const long double eps=1e-12;



ld mypow(ld a,ll i){

    if(i==0) return 1;

    ld t=mypow(a,i>>1);

    t*=t;

    if(i&1) t=(ld)(t*a);

    return t;

}



int main()

{

    int n,m;

    ld sum;

    while(scanf("%d%d",&n,&m)!=EOF){

        sum=0;

        for(ll i=1;i<=n;i++){

            ll r=i,cnt=0;

            while(r<m) r*=2,cnt++;

            //cout << cnt << endl;

            sum+=(ld)((1.0/n)*mypow(1.0/2,cnt));

        }

        printf("%.12Lf",sum);

    }

    return 0;

}