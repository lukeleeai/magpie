#include <cmath>

#include <cstdio>

using std::abs;

int main(void)

{

	int x=0,y=0,nx,ny,dx,dy;

	int t=0,nt,dt,d,N;

	bool winFlag=true;

	scanf("%d",&N);

	while(N--)

	{

		scanf("%d%d%d",&nt,&nx,&ny);

		dx=abs(nx-x);

		dy=abs(ny-y);

		y=ny;

		x=nx;



		dt=nt-t;

		t=nt;



		if(dx+dy>dt ||(dx+dy)%2 !=dt%2)

		{

			winFlag=false;

		}

	

	}

	if(winFlag)

		printf("Yes\n");

	else

		printf("No\n");





}