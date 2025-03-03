//蛇形填数



#include<stdio.h>



int main(){

	int H,W,N;int num[10001];int ans[100][100];

	scanf("%d%d",&H,&W);

	scanf("%d",&N);

	for(int i=1;i<=N;i++){

		scanf("%d",&num[i]);

	}

	int hs=0,he=H-1,ws=0,we=W-1;

	int nowh=0,noww=0;

	bool flagr=true,flagd=false,flagl=false,flagt=false;

	for(int i=1;i<=N;i++){

		while(num[i]--){

			if(flagr){

				ans[nowh][noww++]=i;

				if(noww>we){

					flagr=false;

					noww=we;

					nowh++;

					hs++;

					flagd=true;

				}

			}

			else if(flagd){

				ans[nowh++][noww]=i;

				if(nowh>he){

					flagd=false;

					nowh=he;

					noww--;

					we--;

					flagl=true;

				}

			}

			else if(flagl){

				ans[nowh][noww--]=i;

				if(noww<ws){

					flagl=false;

					noww=ws;

					nowh--;

					he--;

					flagt=true;

				}

			}

			else if(flagt){

				ans[nowh--][noww]=i;

				if(nowh<hs){

					flagt=false;

					nowh=hs;

					noww++;

					ws++;

					flagr=true;

				}

			}

		}

	}

	for(int i=0;i<H;i++){

		for(int j=0;j<W;j++){

			printf("%d",ans[i][j]);

			if(j!=W-1)

				printf(" ");

			else

				printf("\n"); 

		}

	}

	return 0;

} 