#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

#include<map>

#include<queue>

#define Max 9

int gg[Max]={1,2,3,4,5,6,7,8,0}, s[Max];



int ff[4][2] = {0,-1,1,0,0,1,-1,0};

int sum;

struct node

{

	int a[Max];

	int step;

};

map<int ,int >m;





int bfs()

{

	node tt;

	memcpy(tt.a,s,sizeof(s));

	tt.step = 0;

	queue<node > q;

	q.push(tt);

	while(!q.empty())

	{

		node star = q.front();

		q.pop();

		int i;

		for(i = 0;i<9;i++)

			if(star.a[i]==0)

				break;

		int y = i/3;

		int x = i%3;

		for(i = 0;i<4;i++)

		{

			int tx = x + ff[i][0];

			int ty = y + ff[i][1];

			if(tx >= 0&&ty>=0&&ty<3&&tx<3)

			{

				node end;

				memcpy(end.a,star.a,sizeof(star.a));

				int k = ty*3+tx;

				swap(end.a[k],end.a[y*3+x]);

				int sum1 = 0;

				for(int j = 0;j<9;j++)

					sum1 = sum1*10+end.a[j];

				if(!m[sum1])

				{

					m[sum1] = sum++;

					end.step = star.step+1;

					if(memcmp(end.a,gg,sizeof(gg))==0)

						return end.step;

					q.push(end);

				}

			}

		}

	}

}

int main()

{

	int i,j;



	while(~scanf("%d",&s[0]))

	{

		m.clear();

		int k = s[0];

		sum = 1;

		for(i = 1;i<9;i++)

		{

			scanf("%d",&s[i]);

			k = k*10+s[i];

		}

		m[k] = sum++;

		if(memcmp(s,gg,sizeof(gg))==0)

			printf("0\n");

		else printf("%d\n",bfs());

		

	}	

	return 0;

} 
