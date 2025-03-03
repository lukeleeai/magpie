#include <iostream>

using namespace std;



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    

    int N, A, B;

    cin >> N >> A >> B;



    int diff = B - A;



    // CHECK FOR SPECIAL CASE WHEN A IS NEXT TO B

    if(diff == 0 && (A==1 || B==N)) {

        if(A==1) cout << "Borys" << endl;

    }

    else {

        // CHECK PARITY: ALICE WINS IF EVEN

        if(diff%2 == 0) cout << "Alice" << endl;

        else cout << "Borys" << endl;

    }

}