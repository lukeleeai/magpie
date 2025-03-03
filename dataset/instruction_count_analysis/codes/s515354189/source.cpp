#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <string>

#include <cmath>

#include <algorithm>

#include <vector>

#include <map>

#include <queue>

#include <set>

using namespace std;

typedef long long LL;

const int MaxN = 1e5;

const int Inf = 1 << 30;



char s[55][55],t[55][55];



int main()

{

	int N,M,pos;

	bool ok;

	while(~scanf("%d%d",&N,&M)){

		ok = false;

		for(int i = 1;i <= N;i++) scanf("%s",s[i] + 1);

		for(int i = 1;i <= M;i++) scanf("%s",t[i] + 1);

		for(int i = 1;i <= N - M + 1;i++){

			for(int j = 1;j <= N - M + 1;j++){

				pos = 0;

				for(int k = 0;k < M;k++){

					for(int l = 0;l < M;l++){

						if(s[i + k][j + l] == t[k + 1][l + 1]) pos++;

						else{

							pos = 0;

							break;

						}

					}

					if(!pos) break;

				}

				if(pos == M * M){

					ok = true;

					break;

				}

			}

			if(ok) break;

		}

		if(ok) printf("Yes\n");

		else printf("No\n");

	}

    return 0;

}