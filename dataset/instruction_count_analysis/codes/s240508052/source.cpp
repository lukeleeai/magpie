#include <iostream>

using namespace std;

#define rep(i,N)  for(int i=0;i<N;i++)

int a[4];

int main(){

	int c;

	cin>>c;

	rep(i,4){

		a[3-i]=c%10;

		c/=10;

	}

	rep(i,8){

		c=a[0];

		int b=1;

		rep(j,3){

			if(i&b)

				c+=a[j+1];

			else

				c-=a[j+1];

			b<<=1;

		}

		if(c==7){

			b=1;

			rep(j,3){

				cout<<a[j]<<(i&b?'+':'-');

				b<<=1;

			}

			break;

		}

	}

	cout<<a[3]<<"=7\n";

	return 0;

}
