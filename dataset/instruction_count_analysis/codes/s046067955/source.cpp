#include<cstdio>



typedef long long LL;



inline LL Max(LL i, LL j) {

	return i > j ? i : j;

}



int N,M;

LL A[5005];

int B[5005][205];



int Lm[5005][205], Rm[5005][205];

int stk[5005], top;



void init() {

	

	scanf("%d%d", &N, &M);

	

	for(int i = 2; i <= N; ++i) {

		scanf("%d", &A[i]);

	}

	

	for(int i = 1; i <= N; ++i) {

		for(int j = 1; j <= M; ++j) {

			scanf("%d", &B[i][j]);

		}

	}

}



void pre() {

	

	for(int i = 2; i <= N; ++i) {

		A[i] += A[i - 1];

	}

	

	for(int j = 1; j <= M; ++j) {

		top = 0;

		for(int i = 1; i <= N; ++i) {

			while(top > 0 && B[stk[top]][j] < B[i][j]) {

				Rm[stk[top]][j] = i - 1;

				--top;

			}

			Lm[i][j] = stk[top] + 1;

			stk[++top] = i;

		}

		while(top > 0) {

			Rm[stk[top]][j] = N;

			--top;

		}

	}

}



namespace _120pts {

	

	namespace SegmentTree {

		

		LL mx[1<<18], tg[1<<18];

		

		void P(int id, LL x) {

			mx[id] += x;

			tg[id] += x;

		}

		

		void Combine(int id) {

			mx[id] = Max(mx[id << 1], mx[id << 1 | 1]);

		}

		

		void PushDown(int id) {

			P(id << 1, tg[id]);

			P(id << 1 | 1, tg[id]);

			tg[id] = 0;

		}

		

		void Add(int id, int lb, int rb, int a, int b, LL x) {

			if(a <= lb && rb <= b) {

				P(id, x);

				return ;

			}

			PushDown(id);

			int mid = lb + rb >> 1;

			if(a <= mid) Add(id << 1, lb, mid, a, b, x);

			if(b > mid) Add(id << 1 | 1, mid + 1, rb, a, b, x);

			Combine(id);

		}

		

		LL Qur(int id, int lb, int rb, int a, int b) {

			if(a <= lb && rb <= b) return mx[id];

			PushDown(id);

			int mid = lb + rb >> 1;

			LL Ans = -1ull << 63;

			if(a <= mid) Ans = Max(Ans, Qur(id << 1, lb, mid, a, b));

			if(b > mid) Ans = Max(Ans, Qur(id << 1 | 1, mid + 1, rb, a, b));

			return Ans;

		}

	}

	using SegmentTree :: Add;

	using SegmentTree :: Qur;

	

	int head[100005], nxt[2000005], lb[2000005], rb[2000005], tot;

	LL val[2000005];

	inline void addq(int pos, int l, int r, LL v) {

		nxt[++tot] = head[pos];

		lb[tot] = l;

		rb[tot] = r;

		val[tot] = v;

		head[pos] = tot;

	}

	

	LL Ans = 0;

	

	void solve() {

		

		for(int i = 1; i <= N; ++i) {

			for(int j = 1; j <= M; ++j) {

				addq(i, Lm[i][j], i, B[i][j]);

				addq(Rm[i][j] + 1, Lm[i][j], i, -B[i][j]);

			}

		}

		

		for(int i = 1; i <= N; ++i) {

			Add(1, 1, N, i, i, A[i]);

		}

		

		for(int i = 1; i <= N; ++i) {

			for(int j = head[i]; j; j = nxt[j]) {

				Add(1, 1, N, lb[j], rb[j], val[j]);

			}

			Ans = Max(Ans, Qur(1, 1, N, 1, i) - A[i]);

		}

		

		printf("%lld\n", Ans);

	}

}



int main() {

	

	init();

	pre();

	

//	_100pts :: solve();

	_120pts :: solve();

	

	return 0;

}