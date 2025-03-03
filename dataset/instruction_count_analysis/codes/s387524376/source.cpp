#include <stdio.h>

#include <algorithm>

using namespace std;

int A, B, a[5000], b[5000];

int main() {

	scanf("%d%d", &A, &B);

	for(int i = 0; i < A; i++) scanf("%d", &a[i]);

	for(int i = 0; i < B; i++) scanf("%d", &b[i]);

	int ret = 0;

	for(int i = 0; i <= B - (ret ? ret : 1); i++) {

		int pos = i;

		for(int j = 0; j < A; j++) {

			if(pos == B) break;

			if(b[pos] == a[j]) pos++;

		}

		ret = max(ret, pos - i);

	}

	printf("%d\n", ret);

	return 0;

}