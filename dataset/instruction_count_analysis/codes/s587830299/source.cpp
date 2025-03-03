#include <iostream>

#include <cstdio>

#include <algorithm>

#include <vector>

#include <queue>

#include <set>

#include <map>

using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < n; i++)

const int mo = 1e9 + 7;

int d[3][3];

void solve()

{

    rep(i,3)rep(j,3)cin>>d[i][j];

    int a=d[0][2]-d[0][1],b=d[1][2]-d[1][1],c=d[2][2]-d[2][1];

    if(a!=b||b!=c){puts("No");return;}

    a=d[0][1]-d[0][0],b=d[1][1]-d[1][0],c=d[2][1]-d[2][0];

    if(a!=b||b!=c){puts("No");return;}

    a=d[2][2]-d[1][2],b=d[2][1]-d[1][1],c=d[2][0]-d[1][0];

    if(a!=b||b!=c){puts("No");return;}

    a=d[1][2]-d[0][2],b=d[1][1]-d[0][1],c=d[1][0]-d[0][0];

    if(a!=b||b!=c){puts("No");return;}

    puts("Yes");

}

main()

{

    cin.tie(0);

    ios::sync_with_stdio(0);

    solve();

    return 0;

}