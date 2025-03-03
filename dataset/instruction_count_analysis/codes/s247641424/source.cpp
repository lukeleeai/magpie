#include "stdc++.h"

using namespace std;



const int MAX_N = 10010;

typedef unsigned long long ull;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef vector<int> Array;

typedef vector<Array> Graph;

typedef pair<double, double> pdd;

const ull mod = 1000000000 + 7;

#define REP(i,n) for(int i=0;i<(int)n;++i)



const int CODE_MAX = 362880;

const int SIZE = 9;

int visited[CODE_MAX];



int factorial(int n){

    if(n==1) return 1;

    return n*factorial(n-1);

};



struct Board{

    int num[SIZE];

    void print(){

        for(int i=0;i<SIZE;i++) cout << num[i] << " ";

        cout << endl;

    }

};



int encode(Board &b){

    int res = 0;

    int temp_b[SIZE];

    for(int i=0;i<SIZE;i++) temp_b[i] = b.num[i];

    for(int i=0;i<SIZE-1;i++){

        res += factorial(SIZE-1-i)*temp_b[i];

        for(int j=i+1;j<SIZE-1;j++){

            if(temp_b[i]<temp_b[j]) temp_b[j]--;

        }

    }

   return res;

}



Board decode(int encoded){

    Board b;

    int tmp[SIZE];

    for(int i=0;i<SIZE-1;i++){

        int fact = factorial(SIZE-1-i);

        tmp[i] = encoded/fact;

        encoded %= fact;

    }

    tmp[SIZE-1] = 0;

    int tmp2[SIZE];

    bool check[SIZE];

    for(int i=0;i<SIZE;i++){

        tmp2[i] = i;

        check[i] = false;

    }

    for(int i=0;i<SIZE;i++){

        int j=0;

        while(tmp[i]!=tmp2[j] || check[j]) j++;

        b.num[i] = j;

        check[j] = true;

        while(j<SIZE){

            tmp2[j]--;

            j++;

        }

    }



    return b;

}



int get_adjacent(int now, int i){

    // "i" represents the direction of zero movement.0 up, 1 down, 2 left, 3 right

    Board b = decode(now);

    int zero=0;

    while(b.num[zero]!=0) zero++;

    if(i==0){

        if(zero<3) return -1;

        swap(b.num[zero], b.num[zero-3]);

    }

    if(i==1){

        if(zero>5) return -1;

        swap(b.num[zero], b.num[zero+3]);

    }

    if(i==2){

        if(zero%3<1) return -1;

        swap(b.num[zero], b.num[zero-1]);

    }

    if(i==3){

        if(zero%3>1) return -1;

        swap(b.num[zero], b.num[zero+1]);

    }

    return encode(b);

}



int heuristic_func(int enc1, int enc2){

    Board b1 = decode(enc1);

    int zero1 = 0;

    while(b1.num[zero1]!=0) zero1++;

    Board b2 = decode(enc2);

    int zero2 = 0;

    while(b2.num[zero2]!=0) zero2++;

    return abs(zero1/3 - zero2/3) + abs(zero1%3 - zero2%3);

}



int heuristic_func2(int enc1, int enc2){

    Board b1 = decode(enc1);

    Board b2 = decode(enc2);

    int res = 0;

    for(int i=1;i<SIZE;i++){

        int pos1 = 0;

        int pos2 = 0;

        while(b1.num[pos1]!=i) pos1++;

        while(b2.num[pos2]!=i) pos2++;

        res += abs(pos1/3-pos2/3) + abs(pos1%3 - pos2%3);

    }

    return res;

}



int main(){

    Board b;

    for (int i=0;i<SIZE;i++){

        cin >> b.num[i];

    }

    for(int i=0;i<CODE_MAX;i++){

        visited[i] = -1;

    }



    const int start = encode(b);

    const int goal = 46233;

    priority_queue<pii, vector<pii>, greater<pii> > que;

    que.push(make_pair(heuristic_func2(start, goal), start));

    visited[start] = 0;

    int count = 0;

    while(visited[goal]==-1){

        pii x = que.top();

        que.pop();

        int now = x.second;

        for(int i=0;i<4;i++){

            int adj = get_adjacent(now, i);

            if(adj==-1 || visited[adj]!=-1) continue;

            count++;

            visited[adj] = visited[now]+1;

            que.push(make_pair(heuristic_func2(adj, goal) + visited[adj], adj));

        }

    }

    cout << visited[goal] << endl;

    //cout << count << endl;

    return 0;

}