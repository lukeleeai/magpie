

#include <iostream>

#include <queue>

#include <cfloat>



using namespace std;



class State

{

public:

	double _time; //©©Á½Ô

	int _speed; //¬x

	int _town; //»Ýn

	int _utern; //OñÌ¬it^[Ö~j

	State(double time,int speed,int town,int utern)

		:_time(time),_speed(speed),_town(town),_utern(utern){}

	bool operator<(const State& tmp) const

	{

		return _time > tmp._time;

	}

};



class Edge

{

public:

	int _d; //£

	int _c; //§À¬x

	Edge(){}

	Edge(int d,int c):_d(d),_c(c){}

};



int main()

{

	for(;;)

	{

		//Init

		int n,m,s,g;

		cin >> n >> m;

		if(n==0 && m==0) break;



		cin	>> s >> g;

		--s;

		--g;



		Edge *Graph[30][30];

		for(int i=0;i<30;i++)

		{

			for(int j=0;j<30;j++)

			{

				Graph[i][j] = NULL;

			}

		}



		for(int i=0;i<m;i++)

		{

			int x,y,d,c;

			cin >> x >> y >> d >> c;

			--x;

			--y;

			Graph[x][y] = new Edge(d,c);

			Graph[y][x] = new Edge(d,c);

		}



		bool Visited[30][30][30]; //»Ýn@t^[Ö~@¬x

		double Cost[30][30][30];

		for(int i=0;i<30;i++)

		{

			for(int j=0;j<30;j++)

			{

				for(int k=0;k<30;k++)

				{

					Visited[i][j][k] = false;

					Cost[i][j][k] = DBL_MAX;

				}

			}	

		}



		priority_queue<State> PQ;

		PQ.push(State(0.0,0,s,s));

		Cost[s][s][0] = 0;



		double min_time = -1;



		//Dijkstra

		while(!PQ.empty())

		{

			State tmp = PQ.top();

			PQ.pop();

			if(Visited[tmp._town][tmp._utern][tmp._speed] == true) continue;

			//cout << "time " << tmp._time << " town "<< tmp._town+1 << " speed " << tmp._speed << endl;

			if(tmp._town == g && tmp._speed == 1)

			{

				min_time = tmp._time;

				break;

			}

			Visited[tmp._town][tmp._utern][tmp._speed] = true;



			for(int i=0;i<n;i++)

			{

				if(tmp._utern == i) continue;

				if(Graph[tmp._town][i] != NULL)

				{

					for(int j=-1;j<=1;j++)

					{

						int tmp_speed = tmp._speed + j;

						if(Visited[i][tmp._town][tmp_speed] == true) continue;

						if(tmp_speed <= 0) continue;

						if(tmp_speed > Graph[tmp._town][i]->_c) continue;

						double tmp_time = Graph[tmp._town][i]->_d / static_cast<double>(tmp_speed);

						tmp_time += tmp._time;

						if(Cost[i][tmp._town][tmp_speed] < tmp_time) continue;

						Cost[i][tmp._town][tmp_speed] = tmp_time;

						PQ.push(State(tmp_time,tmp_speed,i,tmp._town));

					}

				}

			}

		}



		//Output

		if(min_time == -1)

		{

			cout << "unreachable" << endl;

		}else

		{

			cout << min_time << endl;

		}



		//Free

		for(int i=0;i<30;i++)

		{

			for(int j=0;j<30;j++)

			{

				if(Graph[i][j] != NULL) delete Graph[i][j];

			}

		}

	}

	return 0;

}