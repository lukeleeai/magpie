#include <iostream>



using namespace std;

int main(int argc, char *argv[]) {

	int board[1200][1200];

	int W = 0;

	int H = 0;

	int N = 0;

	int X = 0;

	int Y = 0;

	int choice = 0;

	cin>>W>>H>>N;

	for(int i=0;i<=1000;i++)

	{

		for(int j=0;j<=1000;j++)

		{

			board[i][j] = 0;

			

		}

	}

	for(int i=1;i<=H;i++)

	{

		for(int j=1;j<=W;j++)

		{

			board[i][j] = 1;

			

		}

	}

	for(int repeat = 1;repeat<=N;repeat++)

	{

		cin>>X>>Y>>choice;

		if(choice == 1)

		{

			for(int i=1;i<=H;i++)

			{

				for(int j=1;j<=X;j++)

				{

					board[i][j] += 1;

					

				}

			}

		}

		if(choice == 2)

		{

			for(int i=1;i<=H;i++)

			{

				for(int j=W;j>X;j--)

				{

					board[i][j] += 1;

					

				}

			}

		}

		if(choice == 3)

		{

			for(int i=1;i<=Y;i++)

			{

				for(int j=1;j<=W;j++)

				{

					board[i][j] += 1;

					

				}

			}

		}

		if(choice == 4)

		{

			for(int i=H;i>Y;i--)

			{

				for(int j=1;j<=W;j++)

				{

					board[i][j] += 1;

					

				}

			}

		}

	}

	

	

	

	

	int amount = 0;

	

	for(int i=1;i<=H;i++)

	{

		for(int j=1;j<=W;j++)

		{

			if(board[i][j] == 1)

			{

				amount += 1;

			}

			

		}

	}

	cout<<amount;

	

}