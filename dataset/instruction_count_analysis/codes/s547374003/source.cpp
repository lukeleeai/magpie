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

	int prev[480][40];

	string str[480][40];

	while(cin >> n >> a >> s >> g, n){

		Graph graph(n);

		for(int i=0;i<a;i++){

			int x, y; string lab; cin >> x >> y >> lab;

			graph[x].push_back(make_pair(y,lab));

		}

		memset(prev, -1, sizeof(prev));

		for(int i=0;i<12*n;i++)

			for(int j=0;j<n;j++) str[i][j] = "";

		priority_queue<Node> qu; qu.push(Node(s, "", -2));

		while(!qu.empty()){

			Node nd = qu.top(); qu.pop();

			int pos = nd.pos, size = nd.str.size();

			if(prev[size][pos]!=-1) continue;

			prev[size][pos] = nd.prev;

			str[size][pos] = nd.str;

			for(int i=0;i<graph[pos].size();i++){

				int npos = graph[pos][i].first;

				if(size + graph[pos][i].second.size() >= 12*n) continue;

				string nstr = nd.str + graph[pos][i].second;

				if(str[nstr.size()][npos]==""||nstr<str[nstr.size()][npos]){

					str[nstr.size()][npos] = nstr;

					qu.push(Node(npos, nstr, size*n+pos));

				}

			}

		}

		int minpos = -1;

		string ans = "";

		for(int i=0;i<12*n;i++){

			if(str[i][g]=="") continue;

			if(ans == ""||ans > str[i][g]){

				ans = str[i][g];

				minpos = i;

			}

		}

		bool flag = (minpos != -1);

		bool visit[40];

		memset(visit, false, sizeof(visit));

		int cur = minpos*n+g;

		while(flag&&cur!=-2){

			if(visit[cur%n]) flag = false;

			visit[cur%n] = true;

			cur = prev[cur/n][cur%n];

		}

		cout << (flag ? ans : "NO") << endl;

	}

}