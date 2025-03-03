#include <iostream>

#include <string>

#include <map>

using namespace std;

int max(int a, int b) {

    if (a > b) return a;

    return b;

}

typedef long long ll;

map<string, int> m1, m2;

int main() {

    int N, M;

    cin >> N;

    string str;

    for (int i = 0; i < N; ++i) {

        cin >> str;

        m1[str] += 1;

    }

    cin >> M;

    for (int i = 0; i < M; ++i) {

        cin >> str;

        m2[str] += 1;

    }

    int res = 0;



    for (auto it = m1.begin(); it != m1.end(); ++it) {

        str = (*it).first;

        if (m1[str] > m2[str]) {

            res = max((m1[str] - m2[str]), res);

        }

    }



    cout << res;

    return 0;

}