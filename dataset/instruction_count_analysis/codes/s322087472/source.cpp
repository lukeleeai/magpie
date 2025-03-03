#include<cstdio>

int main()

{

	int sx,sy,tx,ty;

	while(~scanf("%d%d%d%d",&sx,&sy,&tx,&ty))

	{

		int path1,path2,k,p;

		if(sy<ty)

		{

			path1=ty-sy;

			k=path1;

			while(k--)

			{

				printf("U");

			}

		}

		else if(sy>ty)

		{

			path1=sy-ty;

			k=path1;

			while(k--)

			{

				printf("D");

			}

		}

		if(sx<tx)

		{

			path2=tx-sx;

			p=path2;

			while(p--)

			{

				printf("R");

			}

		}

		else if(sx>tx)

		{

			path2=sx-tx;

			p=path2;

			while(p--)

			{

				printf("L");

			}

		}

		if(sy<ty)

		{

			k=path1;

			while(k--)

			{

				printf("D");

			}

		}

		else if(sy>ty)

		{

			k=path1;

			while(k--)

			{

				printf("U");

			}

		}

		if(sx<tx)

		{

			p=path2;

			while(p--)

			{

				printf("L");

			}

		}

		else if(sx>tx)

		{

			p=path2;

			while(p--)

			{

				printf("R");

			}

		}

		if(sx<tx)

		{

			printf("L");

			path2++;

		}		

		else if(sx>tx)

		{

			printf("R");

			path2++;

		}		

		if(sy<ty)

		{

			path1++;

			k=path1;

			while(k--)

			{

				printf("U");

			}

		}

		else if(sy>ty)

		{

			path1++;

			k=path1;

			while(k--)

			{

				printf("D");

			}

		}

		if(sx<tx)

		{

			p=path2;

			while(p--)

			{

				printf("R");

			}

		}

		else if(sx>tx)

		{

			p=path2;

			while(p--)

			{

				printf("L");

			}

		}

		if(sy<ty)

			printf("D");

		else if(sy>ty)

			printf("U");

		if(sx<tx)

			printf("R");

		else if(sx>tx)

			printf("L");

		if(sy<ty)

		{

			k=path1;

			while(k--)

			{

				printf("D");

			}

		}

		else if(sy>ty)

		{

			k=path1;

			while(k--)

			{

				printf("U");

			}

		}

		if(sx<tx)

		{

			p=path2;

			while(p--)

			{

				printf("L");

			}

		}

		else if(sx>tx)

		{

			p=path2;

			while(p--)

			{

				printf("R");

			}

		}

		if(sy<ty)

			printf("U");

		else if(sy>ty)

			printf("D");

	}

	return 0;

 } 