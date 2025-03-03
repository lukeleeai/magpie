#include"stdc++.h"

using namespace std;

const int MAXN = 111111;

int L, N, T, p[MAXN];

int main(){

	cin>>N>>L>>T;

	int X, W, pos = 1;

	char fx;

	for(int i = 1;i <= N; i++){

		cin>>X>>W;

		if(W == 1){

			p[i] = (X + T) % L;

			pos += (X + T) / L;

		}

		else{

			if(T - X > 0){

				pos--;

				p[i] = L - (T - X) % L;

				if(p[i] == L)p[i] = 0;

				if((T - X) % L == 0)pos -= (T - X) / L - 1;

				else pos -= (T - X) / L;

			}

			else{

				p[i] = X - T;

			}

		}

		if(pos <= 0)pos += N;

		if(pos > N) pos -= N;

	}

	sort(p + 1, p + 1 + N);

	for(int i = 1;i <= N; i++){

		printf("%d\n", p[pos]);

		pos++;

		if(pos == N + 1)pos = 1;

	}

	return 0;

}

/*

4 20 9

7 2

9 1

12 1

18 1

*/ 