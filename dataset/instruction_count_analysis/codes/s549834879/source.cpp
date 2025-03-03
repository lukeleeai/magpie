//**************************

//*** writer  :  Alan Hu **

//************************

#include"stdc++.h"



using namespace std;

     

#define CLEAN(a,b) memset(a,b,sizeof(a))

#define mkp make_pair

#define pb push_back

#define rept(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

     

typedef long long ll;

typedef pair<int, int> pii;

typedef vector<int> vi;



int Q[1010000][2],head,tail,D[810][810];

int n,m,K,sx,sy;

char p[810][810];



void Ins(int x,int y,int d)

{

	if (D[x][y]<=d || p[x][y]!='.') return;

	D[x][y]=d;

	tail++;

	Q[tail][0]=x;

	Q[tail][1]=y;	

}



int main()

{

	int x,y;

	cin>>n>>m>>K;

	rept(i,1,n+1)

	{

		scanf("%s",p[i]+1);

		rept(j,1,m+1)

		{

			if (p[i][j]=='S')

			{

				sx=i;

				sy=j;

				p[i][j]='.';

			}

			D[i][j]=1324144;

		}

	}

	Ins(sx,sy,0);

	while (head<tail)

	{

		head++;

		x=Q[head][0];

		y=Q[head][1];

		Ins(x+1,y,D[x][y]+1);

		Ins(x,y+1,D[x][y]+1);

		Ins(x-1,y,D[x][y]+1);

		Ins(x,y-1,D[x][y]+1);

	}

	int res=1e9;

	rept(i,1,n+1)

	{

		rept(j,1,m+1)

		{

			if (D[i][j]<=K)

			{

				res=min(res,1+(min(min(i-1,n-i),min(j-1,m-j))+K-1)/K);

			}

		}

	}

	cout<<res<<endl;

	return 0;

}