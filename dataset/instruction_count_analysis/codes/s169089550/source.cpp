#include<iostream>

#include<algorithm>

#include<string>

#include<cstdlib>

#include<map>

#include<iomanip>

#include<sstream>

#include<vector>

#include<stack>

#include<math.h>

#include<queue>

#include<complex>

#include<random>

#include<ctime>

using namespace std;



//ユークリッドの互除法　a,bは最大公約数を求めたい２つの数

class Euclid_Gojyohou{

    public:

    long long int gcd(long long int a, long long int b) {

        long long int tmp;

        long long int r = 1;

        if (b > a) {

            tmp = a;

            a = b;

            b = tmp;

        }

        r = a % b;

        while (r != 0) {





            a = b;

            b = r;

            r = a % b;



        }

        return b;

    }

};





const long long int mod=1000000007;

const long long int INF=99999999999999999;



long long int n,l[200000],r[200000],a[200000],res=1;



int main() {

	cout << fixed << setprecision(18);

	Euclid_Gojyohou euc;

	cin>>n;

	for(int i=0;i<n;i++){

		cin>>a[i];

	}

	l[0]=a[0];

	r[n-1]=a[n-1];

	for(int i=1;i<n;i++){

		l[i]=euc.gcd(l[i-1],a[i]);

	}

	for(int i=n-2;i>=0;i--){

		r[i]=euc.gcd(r[i+1],a[i]);

	}

	res=max({res,l[n-2],r[1]});

    for(int i=0;i<n-2;i++){

        res=max(res,euc.gcd(l[i],r[i+2]));

    }

    cout<<res;

} 
