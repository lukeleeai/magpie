#include <iostream>

#include <string>

#include <vector>

#include <queue>

#include <string.h>



using namespace std;



typedef vector< vector< pair<int, string> > > Graph;



class Node{

public:

	int pos; string str; int prev;

	Node(int pos, string str, int prev) : pos(pos), str(str), prev(prev) {}

	bool operator < (const Node &nd) const { return str > nd.str; }

};



int main(){

	int n, a, s, g;

	bool con[40][40];

	bool reach[40];

	bool visit[240][40];

	string str[240][40];

	while(cin >> n >> a >> s >> g, n){

		Graph graph(n);

		memset(con, false, sizeof(con));

		memset(reach, false, sizeof(reach));

		for(int i=0;i<a;i++){

			int x, y; string lab; cin >> x >> y >> lab;

			graph[x].push_back(make_pair(y,lab));

			con[y][x] = true;

		}

		queue<int> quG; quG.push(g);

		while(!quG.empty()){

			int cur = quG.front(); quG.pop();

			if(reach[cur]) continue;

			reach[cur] = true;

			for(int i=0;i<n;i++)

				if(!reach[i]&&con[cur][i]) quG.push(i);

		}

		memset(visit, false, sizeof(visit));

		for(int i=0;i<6*n;i++)

			for(int j=0;j<n;j++) str[i][j] = "";

		priority_queue<Node> qu; qu.push(Node(s, "", -2));

		while(!qu.empty()){

			Node nd = qu.top(); qu.pop();

			int pos = nd.pos, size = nd.str.size();

			if(visit[size][pos]) continue;

			visit[size][pos] = true;

			for(int i=0;i<graph[pos].size();i++){

				int npos = graph[pos][i].first;

				if(size + graph[pos][i].second.size() >= 6*n) continue;

				string nstr = nd.str + graph[pos][i].second;

				if(str[nstr.size()][npos]==""||str[nstr.size()][npos]>nstr){

					str[nstr.size()][npos] = nstr;

					qu.push(Node(npos, nstr, size*n+pos));

				}

			}

		}

		string ans = "";

		for(int i=0;i<6*(n-1);i++){

			if(str[i][g] == "") continue;

			if(ans == ""||ans > str[i][g]) ans = str[i][g];

		}

		if(ans != ""){

			for(int i=0;i<n;i++){

				if(!reach[i]) continue;

				for(int j=6*(n-1);j<6*n;j++){

					if(str[j][i]=="") continue;

					if(str[j][i]<ans) ans = "";

				}

			}

		}

		cout << (ans!="" ? ans : "NO") << endl;

	}

}