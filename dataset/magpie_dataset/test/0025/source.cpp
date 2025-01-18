#include        <map>

#include      <cmath>

#include      <queue>

#include     <string>

#include     <cstdio>

#include     <vector>

#include    <cstring>

#include   <iostream>

#include  <algorithm>

using namespace std;

#define ll long long

const ll inf = 0x3f3f3f3f;

const int maxn = 1e5+5;

const ll mod = 1e9+7;



int main(){

    int k,x;

    scanf("%d%d",&k,&x);

    int t = min(x+k-1,1000000);

    for(int i=max(x-k+1,-1000000);i<=t;i++)

        printf("%d%c",i," \n"[i==t]);

    return 0;

}
