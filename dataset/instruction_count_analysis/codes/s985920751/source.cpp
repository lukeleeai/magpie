#include<iostream>

#include<string>

using namespace std;



int n = 10;

int S[10];

int idx = 0;

int bit_array[1024][10];



int F[100][10];

int P[100][11];



void rec(int i) {

    if (i == n) {

        for (int j = 0; j < n; j++) bit_array[idx][j] = S[j];

        idx++;

        return;

    }



    rec(i + 1);

    S[i] = 1;

    rec(i + 1);

    S[i] = 0;



    return;

}



void makeCombination() {

    for (int i = 0; i < n; i++) {

        S[i] = 0;

    }

    rec(0);

    return;

}



int main() {

    makeCombination();



    int N, profit, open_num, max_prof = -1000000000;

    cin >> N;



    for (int i = 0; i < N; i++) {

        for (int j = 0; j < 10; j++) {

            cin >> F[i][j];

        }

    }



    for (int i = 0; i < N; i++) {

        for (int j = 0; j < 11; j++) {

            cin >> P[i][j];

        }

    }



    for (int i = 1; i < 1024; i++) {

        profit = 0;

        for (int j = 0; j < N; j++) {

            open_num = 0;

            for (int k = 0; k < n; k++) {

                if (bit_array[i][k] == 1 && F[j][k] == 1) open_num++;

            }

            profit += P[j][open_num];

        }

        max_prof = max(max_prof, profit);

    }



    cout << max_prof << endl;



    return 0;

}