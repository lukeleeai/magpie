#include<cstdio>

#include<cstring>

#include<cmath>

#include<iostream>

#include<cstdlib>

#include<map>

#include<stack>

#include<algorithm>

using namespace std;

const int N = 300000;



int main()

{

    int n,ch[N];

    long long int ans=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++)

        scanf("%d",&ch[i]);

    if(ch[0]!=0) {printf("-1\n");return 0;}

    for(int i=1;i<n;i++)

    {

        if(ch[i]-ch[i-1]>=2) {printf("-1\n");return 0;}

        else if(ch[i]-ch[i-1]==1) ans++;

        else ans+=ch[i];

    }

    printf("%lld\n",ans);

    return 0;

}
