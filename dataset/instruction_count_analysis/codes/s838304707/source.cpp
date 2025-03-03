#include <cstdio>

#include <cstring>



using namespace std;



#define rep1(i,x) for(int i=1;i<=(x);++i)



int a[100001];

int memo[100001];

int start[100001];



int main()

{

    int n, k;

    while (scanf("%d %d", &n, &k), n || k) {

        memset(a, 0, sizeof(a));

        memset(memo, 0, sizeof(memo));

        memset(start, 0, sizeof(start));



        bool f = false;



        rep1(i, k) {

            int tmp; scanf("%d", &tmp);

            if (tmp == 0) f = true;

            else a[tmp] = true;

        }



        rep1(i, n) {

            if (a[i]) {

                if (i - 1 >= 0 && a[i - 1]) {

                    start[i] = start[i - 1];

                    memo[start[i]]++;

                } else {

                    start[i] = i;

                    memo[start[i]]++;

                }

            }

        }



        int ma = 0;

        int now = -1;



        rep1(i, n) {

            if (a[i]) {

                if (now == start[i]) continue;

                if (ma < memo[start[i]]) {

                    ma = memo[start[i]];

                    now = start[i];

                }

            } else if (f) {

                int v;

                if (i + 1 <= n && a[i - 1] && a[i + 1]) {

                    v = memo[start[i - 1]] + memo[start[i + 1]] + 1;

                    if (ma < v) {

                        ma = v;

                        now = start[i + 1];

                    }

                } else if (a[i - 1]) {

                    v = memo[start[i - 1]] + 1;

                    if (ma < v) {

                        ma = v;

                        now = start[i - 1];

                    }

                } else if (i + 1 <= n && a[i + 1]) {

                    v = memo[start[i + 1]] + 1;

                    if (ma < v) {

                        ma = v;

                        now = start[i + 1];

                    }

                }

            }

        }



        printf("%d\n", ma);

    }

}