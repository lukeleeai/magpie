#include "stdc++.h"

#define MOD 1000000007LL

using namespace std;



typedef long long ll;

typedef pair<int,int> P;



int dx[4]={1,0,-1,0};

int dy[4]={0,1,0,-1};



struct dice {

	int top;

	int bottom;

	int front;

	int back;

	int left;

	int right;

};



void rotate_front(dice* d) {

	int tmp = d->top;

	d->top = d->back;

	d->back = d->bottom;

	d->bottom = d->front;

	d->front = tmp;

}



void rotate_back(dice* d) {

	int tmp = d->top;

	d->top = d->front;

	d->front = d-> bottom;

	d->bottom = d-> back;

	d->back = tmp;

}



void rotate_right(dice* d) {

	int tmp = d->top;

	d->top = d->left;

	d->left = d->bottom;

	d->bottom = d->right;

	d->right = tmp;

}



void rotate_left(dice* d) {

	int tmp = d->top;

	d->top = d->right;

	d->right = d->bottom;

	d->bottom = d->left;

	d->left = tmp;

}



// t=top, f=front

void decide_all_aspects(dice* d, int t, int f) {

	d->top = t;

	d->front = f;

	d->bottom = 7 - t;

	d->back = 7 - f;

	if (t == 1) {

		if (f == 2)d->right = 3;

		if (f == 3)d->right = 5;

		if (f == 5)d->right = 4;

		if (f == 4)d->right = 2;

	}

	if (t == 2) {

		if (f == 1)d->right = 4;

		if (f == 4)d->right = 6;

		if (f == 6)d->right = 3;

		if (f == 3)d->right = 1;

	}

	if (t == 3) {

		if (f == 1)d->right = 2;

		if (f == 2)d->right = 6;

		if (f == 6)d->right = 5;

		if (f == 5)d->right = 1;

	}

	if (t == 4) {

		if (f == 1)d->right = 5;

		if (f == 5)d->right = 6;

		if (f == 6)d->right = 2;

		if (f == 2)d->right = 1;

	}

	if (t == 5) {

		if (f == 1)d->right = 3;

		if (f == 3)d->right = 6;

		if (f == 6)d->right = 4;

		if (f == 4)d->right = 1;

	}

	if (t == 6) {

		if (f == 2)d->right = 4;

		if (f == 4)d->right = 5;

		if (f == 5)d->right = 3;

		if (f == 3)d->right = 2;

	}

	d->left = 7 - d->right;

}



int n;

int t[101],f[101];

int fie[101][101][51];

int siz[101][101];



void roll(dice* d){

	int z=siz[50][50];

	int nx=50,ny=50;

	while(1){

		int move=-1,mob=-1;

		for(int i=0;i<4;i++){

			int nnx=nx+dx[i],nny=ny+dy[i];

			if(i==0 && z>siz[nny][nnx] && d->right>3){

				if(mob<d->right){

					move=0;

					mob=d->right;

				}

			}

			if(i==1 && z>siz[nny][nnx] && d->back>3){

				if(mob<d->back){

					move=1;

					mob=d->back;

				}

			}

			if(i==2 && z>siz[nny][nnx] && d->left>3){

				if(mob<d->left){

					move=2;

					mob=d->left;

				}

			}

			if(i==3 && z>siz[nny][nnx] && d->front>3){

				if(mob<d->front){

					move=3;

					mob=d->front;

				}

			}

		}

		if(move==-1){

			z=siz[ny][nx];

			fie[ny][nx][z]=d->top;

			siz[ny][nx]++;

			break;

		}

		if(move>=0){

			nx+=dx[move];

			ny+=dy[move];

			z=siz[ny][nx];

			if(move==0)rotate_right(d);

			if(move==1)rotate_back(d);

			if(move==2)rotate_left(d);

			if(move==3)rotate_front(d);

		}

	}

}



int res[7];



int main(void){

	while(1){

		scanf("%d",&n);

		if(n==0)break;

		memset(fie,0,sizeof(fie));

		memset(siz,0,sizeof(siz));

		for(int i=0;i<n;i++){

			scanf("%d%d",&t[i],&f[i]);

			dice d;

			decide_all_aspects(&d,t[i],f[i]);

			roll(&d);

		}

		memset(res,0,sizeof(res));

		for(int i=0;i<=100;i++){

			for(int j=0;j<=100;j++){

				if(siz[i][j]>0)res[fie[i][j][siz[i][j]-1]]++;

			}

		}

		for(int i=1;i<=6;i++){

			printf("%d%c",res[i],i==6?'\n':' ');

		}

	}

	return 0;

}