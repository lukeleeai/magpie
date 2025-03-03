#include<iostream>

#include<cstdio>

#include<algorithm>

#define int long long

using namespace std;

int n,L,R,a[55],ans1,ans2,cnt1,cnt2;

bool cmp(int a,int b){return a>b;}

int C[55][55];

void init(){

    C[0][0]=1;

    for(int i=1;i<=50;i++){

        C[i][0]=1;

        for(int j=1;j<=i;j++)

        C[i][j]=C[i-1][j]+C[i-1][j-1];

    }

}

signed main(){

    init();

    cin>>n>>L>>R;

    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    sort(a+1,a+1+n,cmp);//从大到小排序

    for(int i=1;i<=L;i++) ans1+=a[i];//求和，求平均值

    for(int i=1;i<=n;i++) if(a[i]==a[L]) cnt1++;//临界值数个数

    for(int i=1;i<=L;i++) if(a[i]==a[L]) cnt2++;//1~L中临界值数个数

    if(a[1]==a[L])//特判

        for(int i=L;i<=R;i++) ans2+=C[cnt1][i];

    else ans2=C[cnt1][cnt2];

    printf("%lf\n%lld",(double)ans1/L,ans2);

}