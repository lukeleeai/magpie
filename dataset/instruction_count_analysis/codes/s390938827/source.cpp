#include"iostream"

#include"cstring"

#include"string"

#include"algorithm"

#include"cmath"

#include"cstdio"

#include"cstdlib"

#include"vector"

#include"bitset"

#include"set"

#include"map"

#include"iomanip"

#include"queue"

#include"stack"

using namespace std;

typedef long long ll;

int arr[105];

int cheq[105];

int main() {

	int num; scanf("%d", &num);

	memset(cheq, 0, sizeof(cheq));

	memset(arr, 0, sizeof(cheq));

	int bp = 2, tot = 0;

	for (int i = 1; i <= num; ++i)

		scanf("%d", &arr[i]);

	for (int fp = 1; fp <= num; ++fp, ++bp) {

		if (arr[fp] == arr[bp] && !cheq[fp] && !cheq[bp]) {

			cheq[bp] = 1;

			tot++;

		}

	}

	cout << tot << endl;

	return 0;

}