#include <cstdio>

#include <map>

using namespace std;



const int MN = 200005;



int N;

int A[MN];



map<int,int> B;

typedef map<int,int>::iterator IT;



bool check(int M) {

	B.clear();

//	printf("M = %d :\n", M);

	for (int i = 1; i <= N; ++i) {

		if (A[i - 1] >= A[i]) {

			int j = A[i];

			while (j && ++B[j] == M)

				B[j--] = 0;

			if (!j) return 0;

		}

		else {

			IT it = B.end();

			if (it != B.begin()) {

				--it;

				while (it->first > A[i - 1]) {

					IT tmp = it;

					if (it != B.begin()) --it, B.erase(tmp);

					else {B.erase(tmp); break;}

				}

			}

		}

//		for (int j = 1; j <= A[i]; ++j)

//			printf("%c", B[j] + 'a');

//		puts("");

	}

	return 1;

}



int main() {

	int ok = 1;

	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {

		scanf("%d", A + i);

		if (A[i - 1] >= A[i])

			ok = 0;

	}

	if (ok) return puts("1"), 0;

	int lb = 2, rb = N, mid, ans = -1;

	while (lb <= rb) {

		mid = lb + rb >> 1;

		if (check(mid)) ans = mid, rb = mid - 1;

		else lb = mid + 1;

	}

	printf("%d\n", ans);

	return 0;

}