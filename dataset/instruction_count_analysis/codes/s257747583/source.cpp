#include <cstdio>

#include <iostream>

#include <algorithm>

#include <cstring>

#include <queue> //priority_queue 优先队列

#include <map>

#include <set> //multiset  set<int>::reverse_iterator rit; for(rit=s.rbegin();rit!=s.rend();rit++)

#include <vector>

#include <stack>

#include <cmath>

#include <utility>

#include <sstream>

#include <string>

#define mod 1000000007

#define mod9 998244353

typedef unsigned long long ull;

typedef long long ll;

typedef double db;

const db eps=1e-6;

const int INF = 0x3f3f3f3f;

const ll inf=0x3f3f3f3f3f3f3f3f;

const int N=1e6+8;

inline ll read(){ll s=0,w=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();return s*w;}

using namespace std;



int t,n,m,k,ans=0,cnt=0;

char a[N]={0};

int b[N]={0};

int main(){

    scanf("%s",a+1);

    int len=strlen(a+1);

    for(int i=1;i<=len;i++) b[i]=a[i]-'0';

    for(int i=len;i>=0;i--){

        int sum=b[i];

        int pre=b[i-1];

        if(sum<5){

            ans+=sum;

        }else if(sum>5){

            ans+=10-sum;

            b[i-1]++;

        }else if(pre>=5){

            ans+=10-sum;

            b[i-1]++;

        }else{

            ans+=sum;

        }

    }

    printf("%d\n",ans);

    return 0;

}