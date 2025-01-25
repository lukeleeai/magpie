#include<cstdio>

#include<vector>



using namespace std;



int main(void){

	while(1){

		vector<vector<int> > kek[31];

		

		int n;

		scanf("%d",&n);

		if(n==0){break;}

		

		for(int i=1;i<=n;i++){

			vector<int> hn;

			hn.push_back(i);

			kek[i].push_back(hn);

			

			for(int j=i-1;j>0;j--){

				

				for(int k=0;k<kek[i-j].size();k++){

					int flg=0;

					

					for(int p=0;p<kek[i-j][k].size();p++){

						if(kek[i-j][k][p]>j){

							flg=1;

							break;

						}

					}

					

					if(flg==1){

						continue;

					}

					

					vector<int> u;

					u.push_back(j);

					

					for(int p=0;p<kek[i-j][k].size();p++){

						u.push_back(kek[i-j][k][p]);

					}

					kek[i].push_back(u);

				}

			}

		}

		

		for(int j=0;j<kek[n].size();j++){

			printf("%d",kek[n][j][0]);

			for(int k=1;k<kek[n][j].size();k++){

				printf(" %d",kek[n][j][k]);

			}

			puts("");

		}

	}

}