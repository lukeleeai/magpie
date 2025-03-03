#include "stdc++.h"

#define N 2020

using namespace std;

char grid[N][N];

vector<int> ln[N],vln[N];

int main(){

	int n,m,i,j,k,l,num,ans=0,pos1,pos2,posa,posb;

	cin>>n>>m;

	for(i=0;i<n;i++)

	{

		for(j=0;j<m;j++)

		{

			cin>>grid[i][j];

			if(grid[i][j]=='#')

			{

				ln[i].push_back(j);

				vln[j].push_back(i);

			}

		}

	}

	for(i=0;i<n;i++)

	{

		for(j=0;j<m;j++)

		{

			if(grid[i][j]=='#')

			{

				continue;

			}

			pos1=upper_bound(ln[i].begin(),ln[i].end(),j)-ln[i].begin();

			pos2=upper_bound(vln[j].begin(),vln[j].end(),i)-vln[j].begin();

			posa=pos1-1;

			posb=pos2-1;

			if(pos1==ln[i].size())

			{

				pos1=m-1;

			}

			else

			{

				pos1=ln[i][pos1]-1;

			}

			if(pos2==vln[j].size())

			{

				pos2=n-1;

			}

			else

			{

				pos2=vln[j][pos2]-1;

			}

			if(posa==-1)

			{

				posa=0;

			}

			else

			{

				posa=ln[i][posa]+1;

			}

			if(posb==-1)

			{

				posb=0;

			}

			else

			{

				posb=vln[j][posb]+1;

			}

			num=pos1-posa+pos2-posb+1;

			ans=max(ans,num);

		}

	} 

	cout<<ans<<endl;

	return 0;

}
