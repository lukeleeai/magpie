#include "bits/stdc++.h"

#include<unordered_map>

#include<unordered_set>

#pragma warning(disable:4996)

using namespace std;

using ld = double;

const ld eps = 1e-9;



// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

typedef ld Weight;



const Weight INF = 1e18;

const Weight ZERO = 0;

struct Edge {

	int src, dst;

	Weight weight;

	int id;

	Edge(int src_, int dst_, Weight weight_, const int id_) :

		src(src_), dst(dst_), weight(weight_), id(id_) { }

	Edge(int src, int dst, Weight weight) :

		src(src), dst(dst), weight(weight) { }

	Edge() :src(0), dst(0), weight(0) {

	}

};

typedef vector<Edge> Edges;

typedef vector<Edges> Graph;

namespace getcycle {

	vector<Edge>get_cycle(const Graph&g, const int start) {

		vector<Edge>prev_es(g.size());

		for (auto es : g) {

			for (auto e : es) {

				prev_es[e.dst] = e;

			}

		}

		for (int i = 0; i < int(g.size()); ++i) {

			if (i == start)continue;

			int now = i;

			vector<Edge>cycles;

			vector<int>comes(g.size(), -1);

			comes[now] = 0;

			int num = 1;

			while (1) {

				cycles.emplace_back(prev_es[now]);

				now = prev_es[now].src;

				if (comes[now] != -1) {

					cycles = vector < Edge>(cycles.begin() + comes[now], cycles.end());

					reverse(cycles.begin(), cycles.end());

					return cycles;

				}

				else if (now == start) {

					break;

				}

				comes[now] = num++;

			}

		}

		return vector<Edge>(0);

	}

}



//aoj2309???varify??????????????£??????????????§????????????????????????

pair<Weight, Graph> chu_liu(const Graph&g, const int start, const int e_size) {



	vector<Edge>cycle_edges;

	Weight total_len = 0;

	{

		Graph tree(g.size());

		{

			Graph revg(g.size());





			for (auto es : g) {

				for (auto e : es) {

					revg[e.dst].emplace_back(e.dst, e.src, e.weight, e.id);

				}

			}

			for (int node = 0; node < int(g.size()); ++node) {

				if (node == start)continue;

				else {

					Weight amin = INF;

					Edge min_edge;

					for (auto reve : revg[node]) {

						if (amin > reve.weight) {

							amin = reve.weight;

							min_edge = Edge(reve.dst, reve.src, reve.weight, reve.id);

						}

					}

					if (amin < INF) {

						total_len += min_edge.weight;

						tree[min_edge.src].emplace_back(min_edge);

					}

				}

			}

		}

		cycle_edges = getcycle::get_cycle(tree, start);

		if (cycle_edges.empty()) {

			return make_pair(total_len, tree);

		}

	}

	vector<bool>node_is_cycle(g.size());



	/*????´???°???Edge?????°????????§??????*/

	vector<int>edge_is_cycle(e_size);



	vector<Weight>prev_lens(g.size(), ZERO);



	for (auto ce : cycle_edges) {

		node_is_cycle[ce.src] = true;

		prev_lens[ce.dst] = ce.weight;

	}

	Graph newg(g.size());

	const int compress = cycle_edges[0].src;

	/*????´???°???Edge?????°????????§??????*/

	vector<Edge>memo(e_size);

	for (int s = 0; s < int(g.size()); ++s) {

		bool src_is_cycle = node_is_cycle[s];

		for (auto e : g[s]) {

			memo[e.id] = e;

			bool dst_is_cycle = node_is_cycle[e.dst];

			if (src_is_cycle&&dst_is_cycle) {

				continue;

			}

			else if (src_is_cycle) {

				e.src = compress;

			}

			else if (dst_is_cycle) {

				e.weight -= prev_lens[e.dst];

				e.dst = compress;

			}

			newg[e.src].push_back(e);

		}

	}

	auto p = chu_liu(newg, start, e_size);

	Graph compress_tree(p.second);

	Graph ans_tree(g.size());

	for (auto es : compress_tree) {

		for (auto e : es) {

			const Edge prev_edge(memo[e.id]);

			if (node_is_cycle[prev_edge.dst]) {

				for (auto cycle_edge : cycle_edges) {

					if (cycle_edge.dst != prev_edge.dst) {

						ans_tree[cycle_edge.src].emplace_back(cycle_edge);

					}

				}

			}

			ans_tree[prev_edge.src].emplace_back(prev_edge);

		}

	}

	Weight cycle_len = 0;

	for (auto e : cycle_edges) {

		cycle_len += e.weight;

	}

	return make_pair(p.first + cycle_len, ans_tree);

}



ld getlen(const vector<ld>&a, const vector<ld>&b,const ld n) {



	ld sum = 0;

	for (int k = 0; k < a.size(); ++k) {

		sum += pow(a[k]*n - b[k], 2);

	}

	return sum;

}



ld getdis(const vector<ld>&a, const vector<ld>&b) {

	ld amin = -1e8;

	ld amax = 1e8;

	int num = 100;

	while (num--) {

		ld amid1 = (amin * 2 + amax) / 3;

		ld amid2 = (amin + amax * 2) / 3;

		ld ans1 = getlen(a, b, amid1);

		ld ans2 = getlen(a, b, amid2);

		if (ans1 < ans2) {

			amax = amid2;

		}

		else {

			amin = amid1;

		}

	}

	return getlen(a, b, amin);

}



int main() {

	int N, M; cin >> N >> M;

	vector<vector<ld>>vecs(M);

	for (int i = 0; i < M; ++i) {

		for (int j = 0; j < N; ++j) {

			ld v; cin >> v;

			vecs[i].emplace_back(v);

		}

	}

	Graph g(M);

	int aid = 0;

	for (int i = 0; i < M; ++i) {

		for (int j = 0; j < M; ++j) {

			if (i == j)continue;

			else {

				ld len = getdis(vecs[i], vecs[j]);

				g[i].push_back(Edge(i, j, len,aid++));

			}

		}

	}

	ld ans = 1e18;

	for (int i = 0; i < M; ++i) {

		vector<ld>v(N);

		auto p = chu_liu(g, i, M*(M - 1));

		ld plus = getlen(v, vecs[i],0);

		ans = min(ans, p.first+plus);

	}

	cout <<setprecision(12)<<fixed<< ans << endl;

	return 0;

}