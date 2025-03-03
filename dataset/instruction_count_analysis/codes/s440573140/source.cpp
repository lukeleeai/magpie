#include <iostream>

#include <cstdio>

using namespace std;



const int N = 100000;



int n, p;

int pre[N+1];



int find(int x)

{

    while (x != pre[x])

        x = pre[x];

    return x;

}



int main(void)

{

    while (scanf("%d%d", &n, &p) != EOF) {

        if (!n && !p) break;

        pre[1] = 1;

        for (int i = 2; i <= n; i ++)

            scanf("%d", &pre[i]);

        long long sum = 0;

        for (int i = 1; i <= p; i ++) {

            char s[2];

            int x;

            scanf("%s%d", s, &x);

            if (s[0] == 'M')

                pre[x] = x;

            else

                sum += find(x);

        }

        printf("%lld\n", sum);

    }



    return 0;

}
