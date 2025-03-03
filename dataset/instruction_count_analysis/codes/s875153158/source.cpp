#include <iostream>

#define rep(a,b,c) for(int a=b;a<c;a++)

#define rep_(a,b,c) for(int a=c-1;a>=b;a--)

using namespace std;



int main()

{

	cin.sync_with_stdio(false);

	cout.sync_with_stdio(false);

	int a[20005],b[20005],p[20005],t=0,n;

	cin >> n;

	rep(i,0,n) cin>>p[i],a[i]=i+1;

	rep(i,0,n) b[p[i]-1]=i-p[i];

	//rep(i,0,n) cout << a[i] << ' '; cout << endl;

	//rep(i,0,n) cout << b[i] << ' '; cout << endl;

	rep(i,1,n) 

	{

		t=max(max(0,a[i-1]-a[i]+1),max(0,b[i]-b[i-1]+1));

		b[i]-=t;

		a[i]+=t;

	}

	rep(i,0,n) cout << a[i] << ' '; cout << endl;

	rep(i,0,n) cout << b[i]-b[n-1]+1 << ' '; cout << endl;

}