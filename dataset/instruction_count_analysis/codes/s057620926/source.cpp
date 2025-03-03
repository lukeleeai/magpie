#include<cstdio>

using namespace std;

int A, B, C;

int X;

int solve(){

int result = 0;

for(int i = 0; i <= A; ++i){

for(int j = 0; j <= B; ++j){

for(int k = 0; k <= C; ++k){

int tmp = i * 500 + j * 100 + k * 50;

if(tmp == X) result++;

}

}

}

return result;

}

int main(){

scanf("%d%d%d%d", &A, &B, &C, &X);

int result = solve();

printf("%d\n", result);

return 0;

}