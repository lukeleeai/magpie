#include <iostream>

#include <vector>

#include <map>

#define llint long long

#define inf 1e18



using namespace std;



struct SegTree{

	llint size;

	vector<llint> seg;

	

	SegTree(){}

	SegTree(llint size){

		this->size = size;

		seg.resize(1<<(size+1));

	}

	

	void init()

	{

		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = inf;

	}

	

	void update(llint i, llint val)

	{

		i += (1 << size);

		seg[i] = val;

		while(i > 1){

			i /= 2;

			seg[i] = min(seg[i*2], seg[i*2+1]);

		}

	}



	llint query(llint a, llint b, llint k, llint l, llint r)

	{

		if(b < l || r < a) return inf;

		if(a <= l && r <= b) return seg[k];

		llint lval = query(a, b, k*2, l, (l+r)/2);

		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);

		return min(lval, rval);

	}

	llint query(llint a, llint b)

	{

		return query(a, b, 1, 0, (1<<size)-1);

	}

};



llint n;

llint x[200005], y[200005];

map<llint, vector<llint>> mp;

SegTree seg(18);



int main(void)

{

	cin >> n;

	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

	

	if(n == 1){

		cout << 0 << endl;

		return 0;

	}

	

	llint min_val = inf, min_i, max_val = 0, max_i;

	for(int i = 0; i < n; i++){

		if(min_val > x[i]){

			min_val = x[i];

			min_i = i;

		}

		if(min_val > y[i]){

			min_val = y[i];

			min_i = i;

		}

	}

	for(int i = 0; i < n; i++){

		if(i == min_i) continue;

		if(max_val < x[i]){

			max_val = x[i];

			max_i = i;

		}

		if(max_val < y[i]){

			max_val = y[i];

			max_i = i;

		}

	}

	if(min_val == max(max(x[min_i], y[min_i]), max_val)){

		cout << 0 << endl;

		return 0;

	}

	

	llint bmin = min_val, bmax, rmin, rmax;

	rmax = max(max(x[max_i], y[max_i]), max(x[min_i], y[min_i]));

	rmin = min(max(x[max_i], y[max_i]), max(x[min_i], y[min_i]));

	bmax = min(x[max_i], y[max_i]);

	

	for(int i = 0; i < n; i++){

		if(i == min_i || i == max_i) continue;

		bmax = max(bmax, min(x[i], y[i]));

		rmin = min(rmin, max(x[i], y[i]));

	}

	rmax = max(rmax, max(x[min_i], y[min_i]));

	llint ans = (rmax - rmin) * (bmax - bmin);

	

	bmin = min_val, bmax = max_val;

	rmin = max(x[min_i], y[min_i]), rmax = min(x[max_i], y[max_i]);

	x[min_i] = y[min_i] = rmin, x[max_i] = y[max_i] = rmax;

	

	llint ival = 0;

	for(int i = 0; i < n; i++){

		ival = max(ival, min(x[i], y[i]));

	}

	

	seg.init();

	for(int i = 0; i < n; i++){

		if(max(x[i], y[i]) <= ival) seg.update(i, max(x[i], y[i]));

		else seg.update(i, min(x[i], y[i]));

	}

	for(int i = 0; i < n; i++){

		if(max(x[i], y[i]) > ival){

			mp[max(x[i], y[i])].push_back(i);

		}

	}

	ans = min(ans, (ival - seg.query(0, n-1))*(bmax - bmin));

	

	for(auto it = mp.begin(); it != mp.end(); it++){

		for(int i = 0; i < it->second.size(); i++){

			seg.update(it->second[i], it->first);

		}

		ans = min(ans, (it->first - seg.query(0, n-1))*(bmax - bmin));

	}

	

	cout << ans << endl;

	return 0;

}