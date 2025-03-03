#include "stdc++.h"



using namespace std;



typedef long long ll;

const int maxn = (int) 2e5 + 1;





int n;

int ans = maxn;

int get(int x){

    int y = n - x, res = 0;

    while(x > 9){

        res += (x % 10);

        x /= 10;

    }

    res += x;

    while(y > 9){

        res += (y % 10);

        y /= 10;

    }

    res += y;

    return res;

}





int main(){

    cin >> n;

    for(int i = 1; i <= n / 2; i++){

        ans = min(ans, get(i));

    }

    cout << ans ;

}
