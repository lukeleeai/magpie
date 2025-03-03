#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef vector<ll> vll;

typedef pair<int, int> P;

const int INF = 0x3f3f3f3f;

const int MAXN = 200000;



/*

int N, M;



struct Edge {

    int to;

    int weight;

    int next;

};



vector<Edge> edges(MAXN);

vector<int> head(MAXN, -1);

vector<int> matchingx(MAXN, -1);

vector<int> matchingy(MAXN, -1);

vector<bool> check(MAXN);

vector<int> dis(MAXN);

vector<bool> vis(MAXN, false);



int cnt = 1;



void addEdge(int from, int to, int weight) {

    edges[cnt].to = to;

    edges[cnt].weight = weight;

    edges[cnt].next = head[from];

    head[from] = cnt++;

}



bool dfs(int u) {

    for (int i = head[u]; i != -1; i = edges[i].next) {

        int v = edges[i].to;

        if (!check[v]) {

            check[v] = true;

            if (matchingy[v] == -1 || dfs(matchingy[v])) {

                matchingy[v] = u;

                matchingx[u] = v;

                return true;

            }

        }

    }

    return false;

}



int hungarian() {

    int ans = 0;

    fill(matchingx.begin(), matchingx.end(), -1);

    fill(matchingy.begin(), matchingy.end(), -1);

    for (int u = 1; u <= N; ++u) {

//        if (matchingx[u] == -1) {

        {

            fill(check.begin(), check.end(), false);

            if (dfs(u)) {

                ++ans;

            }

        }

    }

    return ans;

}



void dijkstra(int s) {

    priority_queue<P, vector<P>, greater<>> que;

    fill(dis.begin(), dis.end(), INF);

    dis[s] = 0;

    que.push(P(0, s));

    while (!que.empty()) {

        P p = que.top();

        que.pop();

        int u = p.second;

        if (vis[u]) continue;

        vis[u] = true;

        for (int i = head[u]; i != -1; i = edges[i].next) {

            int v = edges[i].to;

            if (dis[v] > dis[u] + edges[i].weight && !vis[v]) {

                dis[v] = dis[u] + edges[i].weight;

                que.push(P(dis[v], v));

            }

        }

    }

}



struct TreeNode {

    int val;

    TreeNode* left = nullptr;

    TreeNode* right = nullptr;

    TreeNode(int val_) : val(val_) {}

};

 */



int main() {

    ll A, B, Q;

    cin >> A >> B >> Q;

    vll numsA(A);

    vll numsB(B);

    for (int i = 0; i < A; ++i) {

        cin >> numsA[i];

    }

    numsA.push_back(-100000000000LL);

    numsA.push_back(100000000000LL);

    for (int i = 0; i < B; ++i) {

        cin >> numsB[i];

    }

    numsB.push_back(-100000000000LL);

    numsB.push_back(100000000000LL);

    sort(numsA.begin(), numsA.end());

    sort(numsB.begin(), numsB.end());

    ll x;

    for (int i = 0; i < Q; ++i) {

        cin >> x;

        auto uba = upper_bound(numsA.begin(), numsA.end(), x);

        auto ubb = upper_bound(numsB.begin(), numsB.end(), x);

        auto lba = uba - 1;

        auto lbb = ubb - 1;

        vll tmpA = {*lba, *uba};

        vll tmpB = {*lbb, *ubb};



        ll ans = 0;



        ans = tmpA[1] - tmpB[0] + min(tmpA[1] - x, x - tmpB[0]);

        ans = min(ans, tmpB[1] - tmpA[0] + min(tmpB[1] - x, x - tmpA[0]));

        ans = min(ans, x - min(tmpA[0], tmpB[0]));

        ans = min(ans, max(tmpA[1], tmpB[1]) - x);



        cout << ans << endl;

    }

    return 0;

}