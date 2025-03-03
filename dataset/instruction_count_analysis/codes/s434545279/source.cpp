#include"stdc++.h"

using namespace std;

constexpr int N = 100000 + 2;

long long n;

// long long collect(int n, int m){

//     long long ans = 1;

//     for (int i = 1; i <= m;i++){

//         ans *= (n - i + 1);

//         ans /= i;

//     }

//     return ans;

// }

// long long store[43];

// int ans[201];

// int main(){

//     cin >> n;

//     for (int i = 2; i <= 42;i += 2){

//         for (int j = 2; j <= i;j += 2)

//             store[i] += collect(i, j);

//         //cout << store[i] << endl;

//     }

//     int x = 1;

//     int y = 42;

//     int z = 1;

//     while (y >= 2){

//         if (store[y] <= n){

//             for (int i = 1; i <= y;i++)

//                 ans[z++] = x;

//             x++;

//             n -= store[y];

//         }

//         else

//             y -= 2;

//     }

//     cout << z - 1 << endl;

//     for (int i = 1; i < z;i++)

//         printf("%d%c", ans[i], i == z - 1 ? '\n' : ' ');

//     return 0;

// }



// int main(){

//     cout << collect(4, 4) << endl;

//     return 0;

// }

int a[N], b[N];

int main(){

    cin >> n;

    n++;

    constexpr int sup = 90;

    int m = sup;

    int i = 0, j = 0;

    while (n > 1)

    {

        if (n & 1){

            a[++i] = m--;

            n--;

        }

        else{

            b[++j] = m--;

            n >>= 1;

        }

    }

    cout << ((i + j) << 1) << endl;

    for (int k = 1; k <= i; k++)

        cout << a[k] << ' ';

    for (int k = j; k;k--)

        cout << b[k] << ' ';

    for (int k = sup - i - j + 1; k <= sup; k++)

        cout << k << ' ';

    return 0;

}