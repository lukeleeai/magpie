#include <vector>

#include <list>

#include <map>

#include <set>

#include <deque>

#include <stack>

#include <queue>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <cctype>

#include <string>

#include <cstring>

#include <ctime>

#include <climits>

#include <complex>

using namespace std;



#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)

#define rep(i,n) REP(i,0,n)

#define all(x) (x).begin(),(x).end()

#define mp make_pair

#define pb push_back

#define EPS 1e-8

#define DEB 0



int n,m,z;

int edge[64][64];

int edge2[200][200];

vector<pair<int,int> > v;





vector<vector<int> > calc(vector<vector<int> > a, vector<vector<int> > b){

	vector<vector<int> > ret(a.size());

	int sz = a.size();

	rep(i,sz){

		rep(j,sz){

			int sum = 0;

			rep(k,sz){

				sum |= a[i][k]*b[k][j];

			}

			ret[i].pb(sum);

		}

	}

	return ret;

}



vector<vector<int> > multi(vector<vector<int> >& matrix, int k){

	if( k==1 ) return matrix;



	vector<vector<int> > tmp = multi(matrix,k/2);

	if( k%2 ){

		return calc(matrix,calc(tmp,tmp));

	}else{

		return calc(tmp,tmp);

	}

}



int main(){



	while(scanf(" %d%d%d ",&n,&m,&z),n|m|z){

#if DEB

		printf("n,m,z:%d,%d,%d\n",n,m,z);

#endif

		rep(i,64)rep(j,64)edge[i][j]=0;

		rep(i,200)rep(j,200)edge2[i][j]=0;

		

		v.clear();

		rep(i,m){

			int s,d; scanf("%d%d",&s,&d);

			edge[s][d] = edge[d][s] = 1;

		}

		REP(i,1,n+1)edge[i][i]=1;

		

		REP(i,1,n+1){

			REP(j,1,n+1)if( edge[j][i]==1 ){

				v.pb(mp(i-1,j-1));

			}

		}

#if DEB

		rep(i,v.size()){

			printf("(%d,%d)\n",v[i].first,v[i].second);

		}

#endif

		rep(i,v.size()){

			rep(j,v.size()){

				if( v[i].first!=v[j].first && v[i].first==v[j].second && v[i].second!=v[j].first ){

					edge2[i][j] = 1;

				}

			}

		}

#if DEB

		printf("v_size:%d\n",v.size());

#endif

		

		vector<vector<int> > mat(v.size());

		rep(i,v.size()){

			rep(j,v.size()){

				mat[i].pb(edge2[i][j]);

			}

		}



		

#if DEB



		printf("h:%d  , w:%d\n",mat.size(),mat[0].size());

		rep(i,mat.size()){

			rep(j,mat[i].size()){

				printf("%d ",mat[i][j]);

			}

			puts("");

		}

#endif



		vector<vector<int> > hoge = multi(mat,z);



#if DEB

		printf("z:%d\n",z);

		rep(i,hoge.size()){

			rep(j,hoge[i].size()){

				printf("%d ",hoge[i][j]);

			}

			puts("");

		}

#endif



		bool f = false;

		rep(i,v.size())if( v[i].first==n-1 ){

			if( hoge[0][i]>0 ){

				f = true;

				break;

			}

		}

		puts(f?"yes":"no");

	}

	return 0;

}