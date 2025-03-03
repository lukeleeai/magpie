#include "stdc++.h"

using namespace std;

int main(){



    int a,b,c; cin >> a >> b >> c;



    int cnt = 0;

    if(a != b)cnt++;

    if(a != c)cnt++;

    if(b != c)cnt++;

    if(cnt != 0)cout << cnt;

    else cout << 1;



}