#include <map>

#include <set>

#include <cmath>

#include <ctime>

#include <stack>

#include <queue>

#include <cstdio>

#include <cctype>

#include <bitset>

#include <string>

#include <vector>

#include <cstring>

#include <iostream>

#include <iomanip>

#include <algorithm>

#include <functional>

#define fuck(x) cout<<"["<<x<<"]";

#define FIN freopen("input.txt","r",stdin);

#define FOUT freopen("output.txt","w+",stdout);

using namespace std;

typedef long long LL;

typedef pair<int, int> pii;

typedef long double ldb;



const int MX = 1e5 + 5;

const int INF = 0x3f3f3f3f;



int n;

bool ans[MX];

char S[MX], op[] = "SW";



bool check() {

    for(int i = 2; i <= n; i++) {

        if(S[i] == 'o') ans[i + 1] = ans[i - 1] ^ ans[i];

        else ans[i + 1] = ans[i - 1] ^ ans[i] ^ 1;

    }



    int ret = (ans[n + 1] == ans[1]);

    if(S[1] == 'o') ret &= (ans[n] == (ans[1] ^ ans[2]));

    else ret &= (ans[n] != (ans[1] ^ ans[2]));

    return ret;

}

int main() {

    // FIN;

    bool ok = 0;

    scanf("%d%s", &n, S + 1);

    for(int i = 0; i <= 1; i++) {

        for(int j = 0; j <= 1; j++) {

            ans[1] = i; ans[2] = j;



            if(check()) {

                ok = 1; goto ans;

            }

        }

    }

ans:

    if(!ok) printf("-1\n");

    else {

        for(int i = 1; i <= n; i++) {

            printf("%c", op[ans[i]]);

        }

        printf("\n");

    }

    return 0;

}