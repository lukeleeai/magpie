#include "iostream"

#include "algorithm"

#include "string"

#include "vector"

#include "cmath"

#include "bitset"

#define lp(n) for (int i = 0; i < n; i++)

#define lop(n,i) for (int i = 0; i < n; i++)

#define mod 1000000007

#define ll long long int

#define sp ' '

#define intmax 2147483647

#define intmin -2147483647

#define llmax 9223372036854775807

using namespace std;



int n, mem, a[100000], cnt;



int main(){

	cnt = 0;

	cin >> n;

	lp(100000)

		a[i] = 0;

	lp(n) {

		cin >> mem;

		if (mem > 100000)cnt++;

		else a[mem - 1]++;

	}

	lp(100000) {

		if (a[i] < i + 1)cnt += a[i];

		else cnt += a[i] - (i + 1);

	}

	cout << cnt << endl;

	return 0;

}