#include <cstdio>

#include <map>



//#define scanf scanf_s



const int kMaxSquare = 64;



int roulette[4];



typedef struct{

	int type;

	int value;

} BoardState;



BoardState board[kMaxSquare];



int bp(int X, int Y){

	std::map<int, double> bp[kMaxSquare];

	double prob = 1.0f / static_cast<double>(X);



	bp[0][0] = 1.0f;

	for (int n = 0; n < Y; n++){

		for (std::map<int, double>::iterator it = bp[n].begin(); it != bp[n].end(); it++){

			for (int k = 0; k < X; k++){

				int pos = (n + roulette[k] < Y) ? n + roulette[k] : Y;

				if (board[pos].type == 1)

					bp[(pos + board[pos].value < Y) ? pos + board[pos].value : Y][it->first] 

						+= it->second * prob;

				else if (board[pos].type == 2)

					bp[pos][it->first + board[pos].value] += it->second * prob;

				else if (board[pos].type == 3)

					bp[pos][(it->first - board[pos].value > 0) ? it->first - board[pos].value : 0] 

						+= it->second * prob;

				else

					bp[pos][it->first] += it->second * prob;				

			}

		}

	}



	double res = 0.0f;

	for (std::map<int, double>::iterator it = bp[Y].begin(); it != bp[Y].end(); it++)

		res += static_cast<double>(it->first) * it->second;

	return static_cast<int>(res);

}



int main(){

	while (1){

		int X, Y, Z; //X:????????¬?????????????????°, Y: ??????????????°(???: ????????????), Z: ???????????????????????°

		scanf("%d %d %d", &X, &Y, &Z);

		if (X == 0) return 0;

		for (int i = 0; i < X; i++)

			scanf("%d", &roulette[i]);

		for (int i = 0; i < kMaxSquare; i++)

			board[i] = { 0, 0 };

		for (; Z > 0; Z--){

			int N, E, A; //N: ?????????, E: ??????????¨????, A: ??????????????§????????° or ?¢????????????????

			scanf("%d %d %d", &N, &E, &A);

			board[N] = { E, A };

		}

		printf("%d\n", bp(X, Y));

	}

}