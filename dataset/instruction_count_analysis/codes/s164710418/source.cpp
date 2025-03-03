#include <cstdio>



using namespace std;



int main() {

    int N;

    scanf("%d", &N);



    int a[100];

    for (int i=0; i<N; ++i)

        scanf("%d", &a[i]);



    int res=1<<28;

    for (int i=-100; i<=100; ++i) {

        int cur=0;

        for (int j=0; j<N; ++j)

            cur += (a[j]-i)*(a[j]-i);



        if (res > cur)

            res = cur;

    }



    printf("%d\n", res);

    return 0;

}
