#include <iostream>

#include <vector>

using namespace std;

const int N = 100000 + 10;

int n,m;

int a[N];

int main() {

    scanf("%d%d",&n,&m);

    if(n==1) {

        printf("1\n1\n1\n"); return 0;

    }

    vector<int> odd,even;

    for(int i=1;i<=m;i++) {

        scanf("%d",&a[i]);

        if(a[i]&1) odd.push_back(a[i]);

        else even.push_back(a[i]);

    }

    if(m==1) {

        printf("%d\n", a[1]);

        printf("2\n");

        printf("%d %d\n", a[1]-1,1);

        return 0;

    }

    vector<int> res;

    if(n%2 == 0) {

        if(odd.size() > 2) {

            return !printf("Impossible\n");

        }

        vector<int> v;

        if(odd.size() == 2) {

            v.push_back(odd[0]);

            for(auto x: even) v.push_back(x);

            v.push_back(odd[1]);

        } else {

            for(auto x: even) v.push_back(x);

        }

        for(auto x: v) printf("%d ", x); printf("\n");

        for(int i=0;i<v.size();i++) {

            if(i==0) {

            if(v[i]>1) res.push_back(v[i]-1);//printf("%d ", v[i]-1);

            }else if(i==(int)v.size()-1) res.push_back(v[i]+1);

            else res.push_back(v[i]);

        }

    } else {

        if(odd.size() > 1) {

            return !printf("Impossible\n");

        }

        vector<int> v;



        v.push_back(odd[0]);

        for(auto x: even) v.push_back(x);

        for(auto x: v) printf("%d ", x); printf("\n");

        for(int i=0;i<v.size();i++) {

            if(i==0) {

                if(v[i]>1) res.push_back(v[i]-1);

            }

            else if(i==(int)v.size()-1) res.push_back(v[i]+1);

            else res.push_back(v[i]);

        }

    }

    printf("%d\n", res.size());

    for(auto x: res) {

        printf("%d ", x);

    }



}
