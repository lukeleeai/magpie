#include <cstdio>

#include <algorithm>

#include <cstring>

#define ll long long

using namespace std;

int a[100005];

int main(){

	int n,i,x;

	scanf("%d",&n);

	for(i=1;i<=n;i++){

        scanf("%d",&x);

        a[x]=i;

	}

	for(i=1;i<=n;i++){

        printf("%d ",a[i]);

	}

	return 0;

}
