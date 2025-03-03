#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <map>



using namespace std;



struct Dice{

private:

	static const int _roll[4][6], _turn[2][6];

public:

	vector<int> value;

	// 1-6 : top, near, right, left, far, bottom 



	Dice(){

		value.resize(6);

		for (int i = 0; i < 6; ++i) value[i] = i;

	}



	void roll(int dir){ // N, E, W, S

		vector<int> nxt(6);

		for (int i = 0; i < 6; ++i){

			nxt[i] = value[_roll[dir][i]];

		}

		value = nxt;

	}



	void turn(int dir){ // L, R

		vector<int> nxt(6);

		for (int i = 0; i < 6; ++i){

			nxt[i] = value[_turn[dir][i]];

		}

		value = nxt;

	}



	int &operator[](int i){

		return value[i];

	}

};



const int Dice::_roll[4][6] = {

	{ 1, 5, 2, 3, 0, 4 }, // North

	{ 3, 1, 0, 5, 4, 2 }, // East

	{ 2, 1, 5, 0, 4, 3 }, // West

	{ 4, 0, 2, 3, 5, 1 }, // South

};



const int Dice::_turn[2][6] = {

	{ 0, 3, 1, 4, 2, 5 }, // Left

	{ 0, 2, 4, 1, 3, 5 }, // Right

};



typedef pair<int, int> P;



int main(){	

	int n;



	int rdir[] = { 0, 3, 1, 2, 0 };

	int dx[] = { 0, 1, -1, 0};

	int dy[] = { 1, 0, 0, -1};

	while (cin >> n, n){

		P field[300][300];



		while (n--){

			int t, f;

			cin >> t >> f;

			Dice d;

			for (int i = 0; i < 6; ++i) d[i] = i + 1;

			if (d[2] == t || d[3] == t) d.turn(0);

			while (d[0] != t) d.roll(0);

			while (d[1] != f) d.turn(0);



			P pos = {150, 150};

			while (1){

				P dir = {-1, -1};

				for (int i = 1; i <= 4; ++i){

					int nx = pos.first + dx[rdir[i]], ny = pos.second + dy[rdir[i]];

					if(d[i] >= 4 && field[pos.second][pos.first].first > field[ny][nx].first) dir = max(dir, make_pair(d[i], rdir[i]));

				}

				if (dir.second < 0) break;

				d.roll(dir.second);

				pos.first += dx[dir.second];

				pos.second += dy[dir.second];

			}

			++field[pos.second][pos.first].first;

			field[pos.second][pos.first].second = d[0];

		}

		int cnt[7] = {};

		for (auto &pp : field)for (auto &p : pp){

			++cnt[p.second];

		}

		for (int i = 0; i < 6; i++) cout << (i ? " " : "") << cnt[i + 1];

		cout << endl;

	}



	return 0;

}