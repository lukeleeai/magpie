#include<cstdio>

#include<vector>

#include<algorithm>



using namespace std;



int main(){

	int N;

	vector<int> data;



	while (1){

		data.clear();

		scanf("%d", &N);

		if (N == 0)break;



		for (int i = 0; i < N; i++){

			int temp;

			scanf("%d", &temp);

			data.push_back(temp);

		}

		bool flag = false;

		for (int i = 0; i < N; i++){

			if (data[i] > 1){

				flag = true;

				break;

			}

		}

		if (!flag){

			printf("NA\n");

		}

		else{

			if(N == 1)

				printf("2\n");

			else{

				int ans = 1;

				for (int i = 0; i < N; i++){

					if (data[i] != 0 )ans++;

				}

				printf("%d\n", ans);

			}

		}

	}

	return 0;

}