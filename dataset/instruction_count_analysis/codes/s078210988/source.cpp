#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

using namespace std;



int main(){

	int ans = 1,n,k;

	scanf("%d %d",&n,&k);

	for(int i = 0;i < n;i++){

		ans += min(ans,k);

	}

	printf("%d",ans);

	return 0;

}