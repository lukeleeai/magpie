#include "stdc++.h"

#define REP(i, n) for(int i = 0;i < n;i++)

#define SORT(v, n) sort(v, v+n);

#define VSORT(v) sort(v.begin(), v.end())

#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート

#define ll long long

#define pb(a) push_back(a)

#define INF 1000000000

#define MOD 1000000007

using namespace std;

typedef pair<int, int> P;

typedef pair<ll, ll> LP;

typedef pair<int, P> PP;

typedef pair<ll, LP> LPP;



typedef vector<unsigned int>vec;

typedef vector<vec> mat;

typedef tuple<ll, ll, ll> T;



int dy[]={0, 0, 1, -1, 0};

int dx[]={1, -1, 0, 0, 0};



int n,q;

vector<char> field(200020);

vector<char> t(200020),d(200020);

int ans1=0,ans2=0;



bool isOk1(int now){

    int tmp=now;

    //cout<<now<<endl;

    REP(i,q){

        char ns=field[tmp];

        //cout<<tmp<<":"<<ns<<":"<<t[i]<<endl;

        if(ns==t[i]){

            if(d[i]=='L'){

                if(tmp-1<0){

                    ans1 = max(ans1,now+1);

                    return true;

                }

                else tmp--;

            }

            else tmp++;

        }

    }

    return false;

}

bool isOk2(int now){

    int tmp=now;

    //cout<<now<<endl;

    REP(i,q){

        char ns=field[tmp];

        //cout<<ns<<":"<<t[i]<<endl;

        if(ns==t[i]){

            if(d[i]=='R'){

                if(tmp+1>=n){

                    //cout<<"R:"<<n<<":"<<now<<endl;

                    ans2 = max(ans2,n-now);

                    return true;

                }

                else tmp++;

            }

            else tmp--;

            //cout<<tmp<<endl;

        }

    }

    return false;

}

int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    cin>>n>>q;



    REP(i,n) cin>>field[i];

    //map<char,int> mp;

    //bool Left=false,Right=false;

    

    REP(i,q){

        cin>>t[i]>>d[i];

    }



    int l = -1;

    int r = n;

    while(r-l>1){

        int m=l + (r-l) / 2;

        //cout<<m<<endl;

        if(isOk1(m)) l=m;

        else r=m;

    }



    l = -1;

    r = n;

    while(r-l>1){

        int m=l + (r-l) / 2;

        //cout<<m<<endl;

        if(isOk2(m)) r=m;

        else l=m;

    }

    //cout<<ans1<<":"<<ans2<<endl;

    cout<<n-(ans1+ans2)<<endl;

}
