#include "bits/stdc++.h"

#include<unordered_map>

#include<unordered_set>

#pragma warning(disable:4996)

using namespace std;

using ld = long double;

template<class T>

using Table = vector<vector<T>>;

const ld eps=1e-9;



//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"



typedef double Weight;



struct Edge {

	int src, dst;

	Weight weight;

	int id;

	Edge(int src_, int dst_, Weight weight_,const int id_) :

		src(src_), dst(dst_), weight(weight_),id(id_) { }

	Edge(int src, int dst, Weight weight) :

		src(src), dst(dst), weight(weight) { }

	Edge() :src(0), dst(0), weight(0) {



	}

};

const Weight INF = 1e18;

const Weight ZERO = 0;

bool operator < (const Edge &e, const Edge &f) {

	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!

	e.src != f.src ? e.src < f.src : e.dst < f.dst;

}

typedef vector<Edge> Edges;

typedef vector<Edges> Graph;

ld getdis(const vector<ld>&f, const vector<ld>&t) {

	ld amin = -1e9;

	ld amax = 1e9;

	int n = 100;

	while (n--) {

		ld amid0 = (amin*2 + amax) /3;

		ld amid1 = (amin + amax * 2) / 3;

		ld len0 = 0;

		ld len1 = 0;

		{

		

			for (int i = 0; i < f.size(); ++i) {

				len0 += (t[i] - amid0*f[i])*(t[i] - amid0*f[i]);

			}

			for (int i = 0; i < f.size(); ++i) {

				len1 += (t[i] - amid1*f[i])*(t[i] - amid1*f[i]);

			}

		}

		if (len0<len1) {

			amax = amid1;

		}

		else {

			amin = amid0;

		}

		if (!n)return len0;

	}

}

struct Dscc {

public:



	//belongs,newedges

	pair<vector<vector<int>>, vector<vector<int>>>get(const vector<vector<int>>&edges) {

		nums.resize(edges.size());

		fill(nums.begin(), nums.end(), -1);

		vector<vector<int>>revedges(edges.size());

		for (int i = 0; i < edges.size(); ++i) {

			for (auto j : edges[i]) {

				revedges[j].push_back(i);

			}

		}

		int num = 0;

		for (int i = 0; i < edges.size(); ++i) {

			dfs(i, num, edges);

		}

		vector<int>big(nums.size());

		for (int i = 0; i < nums.size(); ++i) {

			big[nums[i]] = i;

		}

		reverse(big.begin(), big.end());

		unis.resize(edges.size());

		fill(unis.begin(), unis.end(), -1);

		num = 0;

		for (int i = 0; i < big.size(); ++i) {



			dfs2(big[i], num, revedges);

			num++;

		}

		vector<int>nums;

		for (int i = 0; i < unis.size(); ++i) {

			nums.push_back(unis[i]);

		}

		sort(nums.begin(), nums.end());

		nums.erase(unique(nums.begin(), nums.end()), nums.end());





		map<int, int>mp;

		for (int i = 0; i < nums.size(); ++i) {

			mp[nums[i]] = i;

		}

		for (int i = 0; i < unis.size(); ++i) {

			unis[i] = mp[unis[i]];

		}



		vector<vector<int>>belongs(nums.size());

		for (int i = 0; i < unis.size(); ++i) {

			belongs[unis[i]].push_back(i);

		}

		vector<vector<int>>newedges(nums.size());

		for (int i = 0; i < edges.size(); ++i) {

			for (auto j : edges[i]) {

				if (unis[i] != unis[j]) {

					newedges[unis[i]].push_back(unis[j]);

				}

			}

		}

		return make_pair(belongs, newedges);

	}



	//belongs,newedges

	pair<vector<vector<int>>, vector<vector<Edge>>>get(const vector<vector<Edge>>&edges) {

		const int old_node_size = edges.size();

		nums.resize(old_node_size);

		fill(nums.begin(), nums.end(), -1);

		vector<vector<Edge>>revedges(old_node_size);

		for (const auto& e : edges) {

			for (const auto& j : e) {

				revedges[j.dst].push_back(Edge(j.dst, j.src, j.weight));

			}

		}

		int num = 0;

		for (int i = 0; i < old_node_size; ++i) {

			dfs(i, num, edges);

		}

		vector<int>big(old_node_size);

		for (int i = 0; i < old_node_size; ++i) {

			big[nums[i]] = i;

		}

		reverse(big.begin(), big.end());



		unis.resize(old_node_size);

		fill(unis.begin(), unis.end(), -1);



		num = 0;

		for (int i = 0; i < old_node_size; ++i) {

			dfs2(big[i], num, revedges);

			num++;

		}

		vector<int>nums;

		for (int i = 0; i < old_node_size; ++i) {

			nums.push_back(unis[i]);

		}



		sort(nums.begin(), nums.end());

		nums.erase(unique(nums.begin(), nums.end()), nums.end());

		const int new_node_size = nums.size();



		map<int, int>mp;

		for (int i = 0; i < new_node_size; ++i) {

			mp[nums[i]] = i;

		}

		for (int i = 0; i < old_node_size; ++i) {

			unis[i] = mp[unis[i]];

		}



		vector<vector<int>>belongs(new_node_size);

		for (int i = 0; i < old_node_size; ++i) {

			belongs[unis[i]].push_back(i);

		}

		vector<vector<Edge>>newedges(new_node_size);

		for (const auto& e : edges) {

			for (const auto& j : e) {

				if (unis[j.src] != unis[j.dst]) {

					newedges[unis[j.src]].push_back(Edge(unis[j.src], unis[j.dst], j.weight));

				}

			}

		}

		return make_pair(belongs, newedges);

	}

private:

	vector<int>nums;

	vector<int>unis;



	void dfs(const int id, int &num, const vector<vector<int>>&edges) {

		if (nums[id] != -1)return;

		else {

			nums[id] = -2;

			for (auto i : edges[id]) {

				dfs(i, num, edges);

			}

		}

		nums[id] = num++;

		return;

	}

	void dfs2(const int id, const int &num, const vector<vector<int>>&edges) {

		if (unis[id] != -1)return;

		else {

			unis[id] = -2;

			for (auto i : edges[id])

				dfs2(i, num, edges);

		}

		unis[id] = num;

		return;

	}

	void dfs(const int id, int &num, const vector<vector<Edge>>&edges) {

		if (nums[id] != -1)return;

		else {

			nums[id] = -2;

			for (auto i : edges[id]) {

				dfs(i.dst, num, edges);

			}

		}

		nums[id] = num++;

		return;

	}

	void dfs2(const int id, const int &num, const vector<vector<Edge>>&edges) {

		if (unis[id] != -1)return;

		else {

			unis[id] = -2;

			for (auto i : edges[id]) {

				dfs2(i.dst, num, edges);

			}

		}

		unis[id] = num;

		return;

	}



}dscc;



namespace getcycle {

	pair<int,vector<Edge>> dfs(const Graph&g,vector<int>&used,const int now,const int id) {

		if (used[now]==-1) {

			used[now] = id;

			for (auto e : g[now]) {

				if (used[e.dst] ==id) {

					return make_pair(e.dst, vector<Edge>(1, e));

				}else if (used[e.dst]!=-1) {

					continue;

				}

				else {

					assert(used[e.dst] == -1);

					auto p(dfs(g, used, e.dst,id));

					if (p.first == -1) {

						return p;

					}

					else if (p.first == -2) {

						continue;

					}

					else {

						p.second.push_back(e);

						if (p.first == now) {

							return make_pair(-1, p.second);

						}

						else {

							return p;

						}

					}

				}

			}

			return make_pair(-2, vector<Edge>(0));

		}

		else {

			assert(false);

			return make_pair(0,vector<Edge>(0));

		}

	}

	vector<Edge>get_cycle(const Graph&g,const int start) {

		vector<int>used(g.size(),-1);

		

		int id = 0;

		for (int i = 0; i < g.size(); ++i) {

			if (used[i]==-1) {

				

				vector<Edge>cycles = dfs(g, used, i,id).second;

				id++;

				if (!cycles.empty()) {



					reverse(cycles.begin(), cycles.end());

					return cycles;

				}

			}

		}

		return vector<Edge>(0);

	}

}



pair<Weight,Graph> chu_liu(const Graph&g, const int start) {

	Graph revg(g.size());



	/*????´???°???Edge?????°????????§??????*/

	//vector<Edge>memo(g.size()*g.size());

	for (auto es : g) {

		for (auto e : es) {

			//memo[e.id] = e;

			revg[e.dst].emplace_back(e.dst, e.src, e.weight);

		}

	}

	Graph tree(g.size());

	ld total_len = 0;

	for (int node = 0; node < g.size(); ++node) {

		if (node == start)continue;

		else {

			Weight amin = INF;

			Edge min_edge;

			for (auto reve : revg[node]) {

				if (amin > reve.weight) {

					amin = reve.weight;

					min_edge = Edge(reve.dst,reve.src, reve.weight);

				}

			}

			if (amin < INF) {

				total_len += min_edge.weight;

				tree[min_edge.src].emplace_back(min_edge);

			}

		}

	}

	Weight cycle_len = 0;

	vector<Edge>cycle_edges(getcycle::get_cycle(tree, start));

	for (auto e : cycle_edges) {

		cycle_len += e.weight;

	}

	if (cycle_edges.empty()) {

		return make_pair(total_len,g);

	}

	else {

		vector<bool>node_is_cycle(g.size());



		/*????´???°???Edge?????°????????§??????*/

		vector<int>edge_is_cycle(g.size()*g.size());



		vector<pair<int,Weight>>prevs(g.size(), make_pair(-1,ZERO));

		

		for (auto ce : cycle_edges) {

			node_is_cycle[ce.src] = true;

			node_is_cycle[ce.dst] = true;

			prevs[ce.dst] = make_pair(ce.src, ce.weight);

		}

		Graph newg(g.size());

		const int compress = cycle_edges[0].src;

		int ne_size = 0;

		for (int s = 0; s < g.size();++s){

			bool src_is_cycle = node_is_cycle[s];

			for (auto e : g[s]) {

				bool dst_is_cycle = node_is_cycle[e.dst];

				if (src_is_cycle&&dst_is_cycle) {

				}

				else if (src_is_cycle) {

					newg[compress].push_back(Edge(compress, e.dst, e.weight, e.id));

					ne_size++;

				}

				else if (dst_is_cycle) {

					newg[s].push_back(Edge(s, compress, e.weight-prevs[e.dst].second, e.id));

					ne_size++;

				}

				else {

					newg[s].push_back(Edge(s, e.dst, e.weight, e.id));

					ne_size++;

				}

			}

		}

		auto p=chu_liu(newg, start);

		Graph compress_tree(g.size());

		Graph ans_tree(g.size());

		for (auto es : compress_tree) {

			for (auto e : es) {

				Edge prev_edge(e);

				ans_tree[prev_edge.src].emplace_back(prev_edge);

			}

		}

		ld fin_len = p.first + cycle_len;

		return make_pair(fin_len, ans_tree);

	}

}



int main() {

	int N, M; cin >> N >> M;

	vector<vector<ld>>vecs(M,vector<ld>(N));

	vector<vector<ld>>edges(M, vector<ld > (M));

	for (int i = 0; i < M; ++i) {

		for (int j = 0; j < N; ++j) {

			cin >> vecs[i][j];

		}

	}

	const int start = 0;

	const int node = 1;

	Graph g(M+1);

	int id = 0;

	for (int i = 0; i < M; ++i) {

		ld inidis = 0;

		for (int j = 0; j < N; ++j) {

			inidis += vecs[i][j] * vecs[i][j];

		}

		g[start].emplace_back(start, node + i, inidis,id++);

		for (int j = 0; j < M; ++j) {

			if (i != j) {

				ld dis = getdis(vecs[i], vecs[j]);

				g[node + i].emplace_back(node + i, node + j, dis, id++);

			}

		}

	}

	auto p=chu_liu(g, start);

	cout <<fixed<<setprecision(22)<< p.first << endl;

	return 0;

}