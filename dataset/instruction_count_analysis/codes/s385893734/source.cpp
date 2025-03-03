/*|In The Name Of Allah|*/



#include "stdc++.h"



using namespace std;



const int N = 111;

const int M = 11;



int n;

int k;

int v[N];

int mem[N][N][N];



int go(int l , int r , int stp){

    if(stp < 0)

        return -1e9;

    if(l > r || stp == 0)

        return 0;

    if(~mem[l][r][stp])

        return mem[l][r][stp];

    int ret = 0;

    int c1 , c2 , c3 , c4;

    c1 = go(l + 1 , r , stp - 1) + v[l];

    c2 = go(l , r - 1 , stp - 1) + v[r];

    c3 = go(l + 1 , r , stp - 2);

    c4 = go(l , r - 1 , stp - 2);

    return mem[l][r][stp] = max(0 , max(max(c1 , c2) , max(c3 , c4)));

}



int main(){

    scanf("%d%d" , &n , &k);

    for(int i = 1; i <= n; i++){

        scanf("%d" , &v[i]);

    }

    memset(mem , -1 , sizeof mem);

    printf("%d\n" , max(go(1 , n , k) , 0));

}
