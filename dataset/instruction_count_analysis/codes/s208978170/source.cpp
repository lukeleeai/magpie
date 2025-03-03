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

const int maxn=(int)1e5+10;



ld p[maxn];



void mypow(){

    p[0]=1;

    for(int i=1;i<maxn;i++){

        p[i]=p[i-1]*0.5;

    }

}



int main()

{

    int n,m;

    ld sum;

    mypow();

    while(scanf("%d%d",&n,&m)!=EOF){

        sum=0;

        for(ll i=1;i<=n;i++){

            ll cnt=0,r=i;

            while(r<m) r*=2,cnt++;

            //cout << cnt << endl;

            sum+=(ld)((1.0/n)*p[cnt]);

        }

        printf("%.12Lf",sum);

    }

    return 0;

}