#include <cstring>

#include <iostream>

using namespace std;

long long Cou[202000];

long long Num[202000];

long long Cal[202000];

long long book[202000];

void cal() {

    Cal[1] = 0;

    Cal[2] = 1;

    for (long long i = 3; i <= 202000; i++) {

        Cal[i] = Cal[i - 1] + i - 1;

    }

    return;

}

int main() {

    long long N;

    cal();

    while (cin >> N) {

        memset(Cou, 0, sizeof(Cou));

        memset(book, 0, sizeof(book));

        for (long long i = 1; i <= N; i++) {

            cin >> Num[i];

            Cou[Num[i]]++;

        }

        long long tempAns = 0;

        for (long long i = 1; i <= N; i++) {

            if (book[Num[i]] == 0) {

                tempAns += Cal[Cou[Num[i]]];

                book[Num[i]]++;

            }

        }

        // cout << "#" << tempAns << endl;

        for (long long i = 1; i <= N; i++) {

            cout << tempAns - Cal[Cou[Num[i]]] + Cal[Cou[Num[i]] - 1] << endl;

        }

    }

    return 0;

}