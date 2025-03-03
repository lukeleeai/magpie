#include "stdc++.h"

using namespace std;





struct Barricada {

    long long S, T, X;

    bool operator<(const Barricada& rhs) const

    {

        return X > rhs.X;

    }

};



bool compare_barr(Barricada lhs, Barricada rhs){

    if (lhs.S - lhs.X < rhs.S - rhs.X) return true;

    return false;

}



Barricada barr[200000];

long long people[200000];

long long people_ans[200000];

long long ans[200000];

map <long long, long long> mapeo;



int main(){

    int n, q, pointer = 0;

    long long s, t, x, d;

    cin >> n >> q;

    for (int i = 0; i < n; ++i) {

        cin >> s >> t >> x;

        barr[i] = {s,t,x};

    }

    sort(barr, barr+n, compare_barr);

    priority_queue<Barricada> que;

    for (int j = 0; j < q; ++j) {

        cin >> people[j];

        people_ans[j] = people[j];

        mapeo[people[j]] = j;

    }

    sort(people, people+q);

    for (int k = 0; k < q; ++k) {

        while (pointer < n) {

            if (people[k] >= barr[pointer].S - barr[pointer].X) {

                que.push({barr[pointer].S, barr[pointer].T, barr[pointer].X});

                //cout << que.top().X << "a "<< k<<"\n";

                pointer++;

                continue;

            }

            break;

        }

        while (que.size()){

            if(people[k] >= que.top().T - que.top().X){

                que.pop();

                continue;

            }

            break;

        }

        if (que.size()) ans[mapeo.find(people[k])->second] = que.top().X;

        else ans[mapeo.find(people[k])->second] = -1;

    }

    for (int l = 0; l < q; ++l) {

        cout << ans[l] << "\n";

    }

    return 0;

}