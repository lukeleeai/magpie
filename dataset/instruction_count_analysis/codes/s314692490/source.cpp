#include <algorithm>

#include <cstdio>

#include <deque>

#include <vector>



#define rep(i,n) for(int i=0;i<(n);i++)



using namespace std;



bool check(vector<int> a,int k,int d){

	int n=a.size();

	rep(i,n) a[i]%=d;

	sort(a.begin(),a.end());



	deque<int> D(a.begin(),a.end());

	while(D.size()>=2){

		int x=D.front(),y=d-D.back();

		if     (x<=y && x<=k) D.pop_front(), D.back ()+=x, k-=x;

		else if(x> y && y<=k) D.pop_back (), D.front()-=y, k-=y;

		else return false;

	}

	return true;

}



int main(){

	int n,k; scanf("%d%d",&n,&k);

	vector<int> a(n);

	rep(i,n) scanf("%d",&a[i]);



	int ans=0,sum=0;

	rep(i,n) sum+=a[i];

	for(int d=1;d*d<=sum;d++) if(sum%d==0) {

		if(check(a,k,  d  )) ans=max(ans,  d  );

		if(check(a,k,sum/d)) ans=max(ans,sum/d);

	}

	printf("%d\n",ans);



	return 0;

}
