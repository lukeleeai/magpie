#include"stdc++.h"

 

using namespace std;

const int maxn = 1010;

int x[maxn], y[maxn], n, d[maxn], m, flg[2];

 

void solve(int a, int b){

    for(int i=0; i<m-flg[0]; i++){

        if(abs(a)>abs(b)){

            if(a>0) putchar('R'),a-=d[i];

            else    putchar('L'),a+=d[i];

        }else{

            if(b>0) putchar('U'),b-=d[i];

            else    putchar('D'),b+=d[i];

        }

    }

    if(flg[0]) putchar('L');

    puts("");

}

int main(){

    cin >> n;

    for(int i = 0; i < n; i++) 

        cin >> x[i] >> y[i], flg[(abs(x[i])+abs(y[i]))%2]=1;

    if(flg[0]&&flg[1]) return puts("-1"),0;

    for(int j = 30; j >= 0; j--)  d[m++]=(1<<j);

    if(flg[0]) d[m++] = 1;

    printf("%d\n", m); 

    for(int i=0;i<m;i++)printf("%d%c",d[i]," \n"[i==m-1]);

    for(int i = 0; i < n; i++) solve(x[i]+flg[0],y[i]);

    return 0;

}
