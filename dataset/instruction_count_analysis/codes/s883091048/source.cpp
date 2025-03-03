#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;



typedef long long ll;

const int MAXN=2e5+5;



int n;

ll d[MAXN],cnt[30],sum;

char s[MAXN];



int main(){

    scanf("%s",s+1);

    n=strlen(s+1);

    d[1]=1,sum=1,cnt[s[1]-'a']=1;

    for(int i=2;i<=n;i++){

        d[i]=(ll)d[i-1]+sum-cnt[s[i]-'a'];

        cnt[s[i]-'a']++;

        sum++;

    }

    printf("%lld",d[n]);

}
