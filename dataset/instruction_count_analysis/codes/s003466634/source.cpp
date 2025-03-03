#include"stdc++.h"

using namespace std;



int main(void){

	int n;

	char s[120];

	map<char,int> m1,m2; 

	while(cin>>n>>s){

		int cnt,mx = 0;

		for(int i=0;i<n;i++){

			m1.clear();

			m2.clear();

			cnt = 0;

			for(int j=0;j<=i;j++){

				m1[s[j]] = 1;

			}

			for(int j=i+1;j<n;j++){

				m2[s[j]] = 1;

			}

			for(int i=0;i<=25;i++){

				if(m1['a'+i]&&m2['a'+i])

					cnt++;

			}

			mx = max(mx,cnt);

		}

		printf("%d\n",mx);

	}

	return 0;

} 