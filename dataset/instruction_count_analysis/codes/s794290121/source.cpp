#include "stdc++.h"

# define ll      long long 

# define in      freopen("input.txt", "r", stdin);

# define out     freopen("output.txt", "w", stdout);

# define all(vc) vc.begin(),vc.end()

# define str     string 

# define pb      push_back

# define speed   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

# define time    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"

using namespace std;

ll a,b,c,d,e,f,mn=1e9,mx,cnt,bnt,sum; str s,cal,kcal;

set <ll> st; map <char, int> mp; vector <ll> vc1;

void botsolve(){

	int right1=s.size()-1,left1=0;

	for (int i = 0; i <(int) s.size(); ++i){

		if(s[right1]=='Z' && sum==0){

			cnt+=(s.size()-1)-right1;

			sum++;

		}

		if(s[left1]=='A' && mx==0){

			cnt+=left1;

			mx++;

		}

		right1--;

		left1++;

	}

	cout<<s.size()-cnt;

}

int main(){

	speed;

	//in out

    cin>>s;

    botsolve();



	time;

	return 0;

}