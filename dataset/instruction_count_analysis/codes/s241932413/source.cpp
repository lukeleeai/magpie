#include<string>

#include<stdio.h>

#include<vector>

#include<set>

#include<map>

#include<queue>

#include <iomanip>

#include<cmath>

#include<stack>

#include <algorithm>

#include<cstdio>

#include <cstring>

#include <iostream>

#define inf 0n7fffffff

using namespace std;

int main()

{

    string ch[1010];

    int n,d;

    cin>>n>>d;

    for(int i=1;i<=n;i++)

        cin>>ch[i];

    sort (ch+1,ch+n+1);

    for(int i=1;i<=n;i++)

        cout<<ch[i];

    return 0;

}
