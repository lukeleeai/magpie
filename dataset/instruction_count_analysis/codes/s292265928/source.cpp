#include <iostream>



using namespace std;

int main(int argc, char *argv[]) {

	int N = 0;

	int M = 0;

	char contain[1200][1200];

	char check[1200][1200];

	cin>>N>>M;

	for(int i=1;i<=900;i++)

	{

		for(int j=1;j<=900;j++)

		{

			contain[i][j] = 0;

		}

	}

	for(int i=1;i<=N;i++)

	{

		for(int j=1;j<=N;j++)

		{

			cin>>contain[i][j];

		}

	}

	for(int i=1;i<=M;i++)

	{

		for(int j=1;j<=M;j++)

		{

			cin>>check[i][j];

		}

	}

	int end = 0;

	for(int i=0;i<=N;i++)

	{

		for(int j=0;j<=N;j++)

		{

				end = 0;

				for(int x=0;x<=M;x++)

				{

					for(int z=0;z<=M;z++)

					{

						if((contain[x+i][z+j]==check[x][z])&&(contain[x+i][z+j]!=0)&&(check[x][z]!=0))

						{

							end += 1;

						}

					}

				}

				if(end == M*M)

				{

					cout<<"Yes";

					cout<<endl;

					return 0;

				}

			

		}

	}

	cout<<"No";

	cout<<endl;

	return 0;

	

}