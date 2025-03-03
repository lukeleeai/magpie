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



int n,m,z,h;

int edge[64][64];

int edge2[200][200];

vector<pair<int,int> > v;





/*

  vector<int> a, vector<int> b

  03:08 sec	2000 KB



  const vector<int>& a, const vector<int>& b

  03:06 sec	1700 KB

  */



vector<int> calc(const vector<int>& a, const vector<int>& b){

	vector<int> ret;

	rep(i,h){

		rep(j,h){

			int sum = 0;

			rep(k,h){

				sum |= a[i*h+k]*b[k*h+j];

			}

			ret.pb(sum);

		}

	}

	return ret;

}



vector<int> multi(vector<int>& matrix, int k){

	if( k==1 ) return matrix;



	vector<int> tmp = multi(matrix,k/2);

	if( k%2 ){

		return calc(matrix,calc(tmp,tmp));

	}else{

		return calc(tmp,tmp);

	}

}



int main(){



	while(scanf(" %d%d%d ",&n,&m,&z),n|m|z){

		rep(i,64)rep(j,64)edge[i][j]=0;

		rep(i,200)rep(j,200)edge2[i][j]=0;

		

		v.clear();

		rep(i,m){

			int s,d; scanf("%d%d",&s,&d);

			edge[s][d] = edge[d][s] = 1;

		}

		

		//REP(i,1,n+1)edge[i][i]=1;

		edge[1][1] = 1;

		

		REP(i,1,n+1){

			REP(j,1,n+1)if( edge[j][i]==1 ){

				v.pb(mp(i-1,j-1));

			}

		}



		rep(i,v.size()){

			rep(j,v.size()){

				if( v[i].first!=v[j].first && v[i].first==v[j].second && v[i].second!=v[j].first ){

					edge2[i][j] = 1;

				}

			}

		}

		h = v.size();

		vector<int> mat;

		rep(i,v.size()){

			rep(j,v.size()){

				mat.pb(edge2[i][j]);

			}

		}



#if DEB

		rep(i,v.size()){

			printf("(%d,%d)\n",v[i].first, v[i].second);

		}

		rep(i,v.size()){

			rep(j,v.size()){

				printf("%d ",mat[i*h+j]);

			}

			puts("");

		}

#endif



		

		vector<int> hoge = multi(mat,z);



#if DEB

		printf("z:%d\n",z);

		rep(i,v.size()){

			rep(j,v.size()){

				printf("%d ",hoge[h*i+j]);

			}

			puts("");

		}

#endif

		bool f = false;

		rep(i,v.size())if( v[i].first==n-1 ){

			if( hoge[i]>0 ){

				f = true;

				break;

			}

		}

		puts(f?"yes":"no");

	}

	return 0;

}