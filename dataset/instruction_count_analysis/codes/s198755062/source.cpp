#include<cstdio>

using namespace std;

const int MAX = 100000, mod = 1e9+7;

int A[MAX];

int main(){

    int n;

    long long sum = 1;

    scanf("%d", &n);

    A[0] = 3;

    

    for (int i = 0; i < n; i++)

    {

        int a;

        scanf("%d", &a);

        sum = (sum * A[a]) % mod;

        A[a]--;

        A[a+1]++;

    }

    printf("%ld", sum);

}