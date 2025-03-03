#include <iostream>

using namespace std;



int main()

{

    int N;

    cin >> N;

    string S[100000];

    int A = 0, W = 0, T = 0, R = 0;

    for (int i = 0; i < N; i++) {

        cin >> S[i];

    }

    for (int i = 0; i < N; i++) {

        if (S[i] == "AC") {

            A ++;

        }

    }

    for (int i = 0; i < N; i++) {

        if (S[i] == "WA") {

            W ++;

        }

    }

    for (int i = 0; i < N; i++) {

        if (S[i] == "TLE") {

            T ++;

        }

    }

    for (int i = 0; i < N; i++) {

        if (S[i] == "RE") {

            R ++;

        }

    }

    cout << "AC x " << A<<endl;

    cout << "WA x " << W<<endl;

    cout << "TLE x " << T<<endl;

    cout << "RE x " << R <<endl;

    return 0;

}