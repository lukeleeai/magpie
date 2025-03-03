#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <climits>

#include <cmath>

#include <ctime>

#include <cassert>

#include <iostream>

#include <fstream>

#include <sstream>

#include <iomanip>

#include <complex>

#include <string>

#include <vector>

#include <list>

#include <deque>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <bitset>

#include <iterator>

#include <functional>

#include <utility>

#include <algorithm>

#include <numeric>

#include <typeinfo>



using namespace std;



#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl

#define repi(i,a,b) for(int i=int(a);i<int(b);i++)

#define rep(i,n) repi(i,0,n)

#define iter(c) __typeof((c).begin())

#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)

#define allof(c) (c).begin(),(c).end()

#define mp make_pair



typedef unsigned int uint;

typedef long long ll;

typedef unsigned long long ull;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<double> vd;

typedef vector<vd> vvd;

typedef vector<string> vs;

typedef pair<int,int> pii;



struct SegTree{

	vi data;

	int size;

	SegTree(int _size){

		for(int i=1;;i*=2)

			if(i>=_size){

				size=i;

				break;

			}

		data.assign(size*2,0);

	}

	void add(int i,int x){

		for(int j=size+i;j;j/=2)

			data[j]+=x;

	}

	int sum(int a,int b,int i,int l,int r){

		if(r<=a || b<=l) return 0;

		if(a<=l && r<=b) return data[i];

		int m=(a+b)/2,res=0;

		if(a<m) res+=sum(a,b,i*2+0,l,m);

		if(m<b) res+=sum(a,b,i*2+1,m,r);

		return res;

	}

	int ith(int i){

		int j=1;

		while(j<size){

			if(data[j*2+0]>i)

				j=j*2+0;

			else{

				i-=data[j*2+0];

				j=j*2+1;

			}

		}

		return j-size;

	}

};



int main()

{

	//for(int q,l;cin>>q>>l,q|l;){

	//	SegTree st(q);

	//	vi girls;

	//	map<int,int> m;

	//	rep(i,q){

	//		int qu,x; cin>>qu>>x;

	//		if(qu==0){

	//			st.add(girls.size(),1);

	//			m[x]=girls.size();

	//			girls.push_back(x);

	//			if(st.data[1]>l){

	//				int j=st.ith(0);

	//				st.add(j,-1);

	//			}

	//		}

	//		if(qu==1){

	//			int j=st.ith(x-1);

	//			st.add(j,-1);

	//		}

	//		if(qu==2){

	//			int j=st.ith(x-1);

	//			cout<<girls[j]<<endl;

	//		}

	//		if(qu==3){

	//			int j=m[x];

	//			st.add(j,-1);

	//		}

	//	}

	//	puts("end");

	//}

	

	vi girls(400000);

	for(int q,l;scanf("%d%d",&q,&l),q|l;){

		SegTree st(q);

		int gsize=0;

		map<int,int> m;

		rep(i,q){

			int qu,x; scanf("%d%d",&qu,&x);

			switch(qu){

			case 0:{

				st.add(gsize,1);

				m[x]=gsize;

				girls[gsize++]=x;

				if(st.data[1]>l){

					int j=st.ith(0);

					st.add(j,-1);

				}

			}break;

			case 1:{

				int j=st.ith(x-1);

				st.add(j,-1);

			}break;

			case 2:{

				int j=st.ith(x-1);

				printf("%d\n",girls[j]);

			}break;

			case 3:{

				int j=m[x];

				st.add(j,-1);

			}break;

			}

		}

		puts("end");

	}

	

	return 0;

}