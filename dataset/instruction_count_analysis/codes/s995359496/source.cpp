#include<cstdio>

#include<cstring>

using namespace std;



char s[102];

int a[101];

int main(){

	scanf("%s",s+1);

	int n=strlen(s+1),k;

	scanf("%d",&k);

	for(int i=1,o=1;i<=n;i++){

		if(s[i]!=s[i+1]){

			a[++a[0]]=i-o+1;

			o=i+1;

		}

	}

	long long ans=0;

	if(s[1]==s[n]){

		if(a[0]==1)ans=1ll*n*k/2;

		else{

			for(int i=2;i<a[0];i++)

				ans+=1ll*a[i]/2*k;

			ans+=a[1]/2+a[a[0]]/2;

			ans+=1ll*(a[1]+a[a[0]])/2*(k-1);

		}

	}

	else for(int i=1;i<=a[0];i++)

		ans+=1ll*a[i]/2*k;

	printf("%lld\n",ans);

}
