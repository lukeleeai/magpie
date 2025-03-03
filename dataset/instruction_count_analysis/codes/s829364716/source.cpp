#include <cstdio>

int ans[100005],n;

char a[100005];

int check() {

	for(int i = 1;i <= n;i ++) {

		int l = i - 1,r = i + 1;

		if(l == 0) l = n; 

		if(r == n + 1) r = 1;

		if(ans[i] == 1) {

			if(a[i] == 'o' && ans[l] != ans[r]) return 0;

			if(a[i] == 'x' && ans[l] == ans[r]) return 0;

		}

		else {

			if(a[i] == 'o' && ans[l] == ans[r]) return 0;

			if(a[i] == 'x' && ans[l] != ans[r]) return 0;

		}

	}

	return 1;

}

void init() {

	for(int i = 2;i <= n - 1;i ++) {

		if(ans[i] == 1) {

			if(a[i] == 'o') ans[i + 1] = ans[i - 1];

			if(a[i] == 'x') {

				if(a[i] == 'o') ans[i + 1] = ans[i - 1];

				else ans[i + 1] = (ans[i - 1] == 1?2:1);

			}

		}

		if(ans[i] == 2) {

			if(a[i] == 'x') ans[i + 1] = ans[i - 1];

			if(a[i] == 'o') {

				if(a[i] == 'o') ans[i + 1] = (ans[i - 1] == 1?2:1);

				else ans[i + 1] = ans[i - 1];

			}

		}

	}

}



void print() {

	for(int i = 1;i <= n;i ++) {

		if(ans[i] == 1) printf("S");

		else printf("W");

	}

}

int main() {

	scanf("%d",&n);

	scanf("%s",a + 1);

	ans[1] = ans[2] = 1;

	init();

	if(check()) {

		print();

		printf("\n");

		return 0;

	}

	ans[1] = ans[2] = 2;

	init();

	if(check()) {

		print();

		printf("\n");

		return 0;

	}

	ans[1] = 1,ans[2] = 2;

	init();

	if(check()) {

		print();

		printf("\n");

		return 0;

	}

	ans[1] = 2,ans[2] = 1;

	init();

	if(check()) {

		print();

		printf("\n");

		return 0;

	}

	printf("-1\n");

	return 0;

} 