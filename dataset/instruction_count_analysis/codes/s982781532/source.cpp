#include"stdc++.h"



using namespace std;

#define PROBLEM "A"

int like[100000];



int main(){



	#ifdef DBG

	freopen("problem" PROBLEM ".in", "r", stdin);

	freopen("problem" PROBLEM ".out", "w", stdout);

	#endif



	memset(like, 0, sizeof(like));

	int N, M;

	cin >> N >> M;

	for(auto i = 0 ; i < N ; i++){



		int K = 0;

		cin >> K;

		int trash;

		for(auto j = 1 ; j <= K ; j++){



			cin >> trash;

			like[trash]++;

		}

	}



	int count = 0;

	for(int i = 1 ; i <= M ; i++){



		if(like[i] == N){



			count++; 

		}

	}

	cout << count << endl;



	return 0;

}