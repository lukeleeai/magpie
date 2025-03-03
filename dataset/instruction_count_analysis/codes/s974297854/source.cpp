#include<algorithm>

#include<string>

#include<math.h>



using namespace std;



const int N = 200010;



int n,x,y;

int a[N],b[N];

int main(){

	scanf("%d",&n);

	for(int i=0;i<n;i++){

		scanf("%d%d",&x,&y);

		a[i]=x+y;

		b[i]=x-y;

	}

	sort(a,a+n);

	sort(b,b+n);

	printf("%d",max(a[n-1]-a[0],b[n-1]-b[0]));

	return 0;

}