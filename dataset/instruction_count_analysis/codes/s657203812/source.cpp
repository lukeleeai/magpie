#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>



#define MAX 2020



inline int lowbit(const int& i){

	return i & (-i);

}



int m_arr[MAX * 2];



int get(int loc){

	int res = 0;

	while(loc > 0){

		res += m_arr[loc];

		loc -= lowbit(loc);

	}

	return res;

}



void set(int loc, int num){

	while(loc < MAX * 2){

		m_arr[loc] += num;

		loc += lowbit(loc);

	}

}



int loc1[MAX], loc2[MAX];



int cnt[MAX][MAX][2];

int tmparr[MAX * 2];

long long int dp[MAX][MAX];



void init(int num){

	int i, j;



	memset(m_arr, 0, sizeof(m_arr));

	for(i = 1; i <= num; i++){

		cnt[i - 1][0][0] = loc1[i] - get(loc1[i]) - 1;

		set(loc1[i], 1);

	}

	

	memset(m_arr, 0, sizeof(m_arr));

	for(i = 1; i <= num; i++){

		cnt[0][i - 1][1] = loc2[i] - get(loc2[i]) - 1;

		set(loc2[i], 1);

	}

	

	memset(tmparr, 0, sizeof(tmparr));

	for(i = 1; i <= num; i++){

		memcpy(m_arr, tmparr, sizeof(tmparr));

		set(loc1[i], 1);

		memcpy(tmparr, m_arr, sizeof(tmparr));

		for(j = 1; j <= num; j++){

			cnt[i][j - 1][1] = loc2[j] - get(loc2[j]) - 1;

			set(loc2[j], 1);

		}

	}

	

	memset(tmparr, 0, sizeof(tmparr));

	for(i = 1; i <= num; i++){

		memcpy(m_arr, tmparr, sizeof(tmparr));

		set(loc2[i], 1);

		memcpy(tmparr, m_arr, sizeof(tmparr));



		for(j = 1; j <= num; j++){

			cnt[j - 1][i][0] = loc1[j] - get(loc1[j]) - 1;

			set(loc1[j], 1);

		}

	}

}





void getdp(int num){

	int i, j;



	for(i = 1; i <= num; i++){

		dp[i][0] = dp[i - 1][0] + cnt[i - 1][0][0];

	}



	for(i = 1; i <= num; i++){

		dp[0][i] = dp[0][i - 1] + cnt[0][i - 1][1];

	}

	

	for(i = 1; i <= num; i++){

		for(j = 1; j <= num; j++){

			dp[i][j] = dp[i][j - 1] + cnt[i][j - 1][1];

			dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + cnt[i - 1][j][0]);

		}

	}

}



int main()

{

	int num, lo, i;

	char ch;

	while(~scanf("%d", &num)){

		for(i = 1; i <= num * 2; i++){

			getchar();

			scanf("%c", &ch);

			scanf("%d", &lo);

			if(ch == 'W'){

				loc1[lo] = i;

			}

			else{

				loc2[lo] = i;

			}

			

		}

		init(num);

		getdp(num);

		printf("%lld\n", dp[num][num]);

		

		

	}

	

	return 0;

}
