

#include<algorithm>

#include<iostream>

#include<vector>



using namespace std;



const int MAXN = 300010;

int cnt[MAXN];

int f[MAXN];

int main(){

    int n;

    cin >> n;

    for(int i=0;i<n;i++){

        int a;

        cin >> a;

        cnt[a]++;

    }



    vector<int> v;

    for(int i=0;i<MAXN;i++){

        if(cnt[i] > 0){

            v.push_back(cnt[i]);

        }

    }



    sort(v.begin(), v.end());



    int p = 0;

    for(int i=1;i<=n;i++){

        while(p<v.size() && v[p]<i){

            p++;

        }



        f[i] = f[i-1] + v.size() - p;

    }



    for(int i=1;i<=n;i++){

        f[i] /= i;

    }



    p = n;

    for(int i=1;i<=n;i++){

        while(p>0 && f[p] < i)

            p--;

        cout << p<<"\n";

    }



}


