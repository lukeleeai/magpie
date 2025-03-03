#include <iostream>

using namespace std;

int a[200005];

int main(int argc, char** argv) {

	int n,m;

	cin >> n >> m;

	if(m==1||m==2*n-1)

	{

		puts("No");

		return 0;

	}

	puts("Yes");

	a[n]=m;

	a[n-1]=m-1;

	a[n+1]=m+1;

	int now=0;

	for(int i=1;i<n*2;i++)

	{

		if(i==n||i==n-1||i==n+1)

			continue;

		++now;

		if(now==m-1)

			now=m+2;

		a[i]=now;

	}

	for(int i=1;i<n*2;i++)

		cout << a[i] << endl;

	return 0;

}