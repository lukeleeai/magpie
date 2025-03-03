#include<cstdio>



using namespace std;



char s[100002];

int z[26];

int main(){

	int n;

	scanf("%d%s",&n,s+1);

	for(int i=1;i<=n;i++)

		z[s[i]-'a']++;

	int ans=1;

	for(int i=0;i<26;i++)

		ans=1ll*ans*(z[i]+1)%1000000007;

	printf("%d\n",(ans-1+1000000007)%1000000007);

}