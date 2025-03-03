#include <iostream>

#include <queue>

using namespace std;

int w, h, n;

char map[1024][1024];

int d[1024][1024];

const int direction[4][2] = {

	{ -1, 0 },

	{ 1, 0 },

	{ 0, -1 },

	{ 0, 1 },

};



int factory[16][2];

typedef pair<int, int> P;



int bfs(const int& sx, const int& sy, const int& gx, const int& gy)

{

	//memset(d, -1, sizeof(d));

	for (int i = 0; i < h; ++i)

	{

		for (int j = 0; j < w; ++j)

		{

			d[j][i] = -1;

		}

	}

	queue<P> que;

	que.push(P(sx, sy));

	d[sx][sy] = 0;

	while (que.size())

	{

		const P p = que.front(); que.pop();

		// 如果是?点就?束

		if (p.first == gx && p.second == gy)

		{

			break;

		}



		// 四方向漫游

		for (int i = 0; i < 4; ++i)

		{

			int nx = p.first + direction[i][0];

			int ny = p.second + direction[i][1];

			// 是否可以移?，并且?点没有???

			if (0 <= nx && nx < w && 0 <= ny && ny < h && map[nx][ny] != 'X' && d[nx][ny] == -1)

			{

				que.push(P(nx, ny));

				d[nx][ny] = d[p.first][p.second] + 1;

			}

		}

	}



	return d[gx][gy];

}



///////////////////////////SubMain//////////////////////////////////

int main(int argc, char *argv[])

{



	cin >> h >> w >> n;

	for (int i = 0; i < h; ++i)

	{

		for (int j = 0; j < w; ++j)

		{

			cin >> map[j][i];

		}

	}



	for (int i = 0; i < h; ++i)

	{

		for (int j = 0; j < w; ++j)

		{

			if (map[j][i] == 'S')

			{

				factory[0][0] = j;

				factory[0][1] = i;

				map[j][i] = '.';

			}

			else if (isdigit(map[j][i]))

			{

				int index = map[j][i] - '0';

				factory[index][0] = j;

				factory[index][1] = i;

			}

		}

	}



	int step = 0;

	for (int i = 0; i < n; ++i)

	{

		

		step += bfs(factory[i][0], factory[i][1], factory[i + 1][0], factory[i + 1][1]);

	}



	cout << step << endl;



	return 0;

}