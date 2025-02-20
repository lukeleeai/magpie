#include<cstdio>
#include<algorithm>

using namespace std;

#define MAX 1000000

int n;

pair<int, int> T[MAX];

int main(){

    int id, m, s;

    while( scanf("%d", &n) && n ){

    for ( int i = 0; i < n; i++ ){

        scanf("%d", &id);

        int sum = 0;

        for ( int j = 0; j < 4; j++ ){

            scanf("%d%d", &m, &s);

            sum += m*60 + s;

        }

        T[i] = std::make_pair(sum, id);

    }

    sort( T, T + n );



    printf("%d\n", T[0].second);

    printf("%d\n", T[1].second);

    printf("%d\n", T[n-2].second);

    }

}
