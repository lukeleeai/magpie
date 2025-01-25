#include<iostream>

#include<algorithm>

#include<cstring>

#include<cstdio>

#include<vector>

#include<map>

using namespace std;

typedef vector<int> PP;

typedef vector<PP> P;

int n,r;



struct block{

	int x1,x2,y,f;

};



block b[20002];

int fie[10002][2];



bool comp(const block &b1,const block &b2){

	return b1.y<b2.y;

}



int main(void){

	while(1){

		scanf("%d%d",&n,&r);

		if(n==0 && r==0)break;

		memset(fie,0,sizeof(fie));

		memset(b,0,sizeof(b));

		for(int i=0;i<n;i++){

			int y1,y2;

			scanf("%d%d%d%d",&b[i*2].x1,&y1,&b[i*2].x2,&y2);

			b[i*2].x2--;

			b[i*2+1].x1=b[i*2].x1;

			b[i*2+1].x2=b[i*2].x2;

			b[i*2].y=y1;

			b[i*2+1].y=y2;

			b[i*2].f=1;

			b[i*2+1].f=-1;

		}

		sort(b,b+n*2,comp);

		int ny=0;

		int now=0,prev=1;

		int res=0,res2=0;

		for(int i=0;i<n*2;i++){

			if(ny!=b[i].y){

				swap(now,prev);

				int cnt=0;

				int cnt2=0,bt=0,cnt3=0;

				for(int j=0;j<=10000;j++){

					if(fie[j][now]>0 && fie[j][prev]==0)cnt3++;

					if(fie[j][now]==0 && fie[j][prev]>0)cnt3++;

					fie[j][now]=fie[j][prev];

					if(fie[j][now]>0){

						cnt++;

						if(bt==0)cnt2++,bt=1;

					}else bt=0;

				}

				res+=cnt*(b[i].y-ny);

				res2+=cnt2*2*(b[i].y-ny)+cnt3;

			}

			ny=b[i].y;

			for(int j=b[i].x1;j<=b[i].x2;j++)fie[j][now]+=b[i].f;

			//printf("%d\n",res2);

			

		}

		printf("%d\n",res);

		if(r==2){

			swap(now,prev);

			int cnt3=0;

			for(int j=0;j<=10000;j++){

				if(fie[j][now]>0 && fie[j][prev]==0)cnt3++;

				if(fie[j][now]==0 && fie[j][prev]>0)cnt3++;

				fie[j][now]=fie[j][prev];

			}

			res2+=cnt3;

			printf("%d\n",res2);

		}

	}

	return 0;

}