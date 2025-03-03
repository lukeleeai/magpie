#include <algorithm>

#include <cstdio>

using namespace std;



int A[5565];



int main()

{

    int n, k;

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)

    {

        scanf("%d", A + i);

    }

    sort(A, A + n);

    int sum = 0;

    for (int i = 0; i < k; i++)

    {

        sum += A[i];

    }

    printf("%d\n", sum);



    return 0;

}
