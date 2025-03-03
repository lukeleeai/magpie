#include <iostream>

using namespace std;



int main()

{

    int k, s;

    cin >> k >> s;

    int counter = 0;

    for (int x = 0; x <= k; x++) {

        for (int y = x; y <= k; y++) {

            for (int z = y; z <= k; z++) {

                if (x + y + z == s) {

                    if (x != y && y != z && x != z) {

                        counter += 6;

                    } else if (x == y && y == z) {

                        counter++;

                    } else {

                        counter += 3;

                    }

                }

            }

        }

    }

    cout << counter << endl;

    return 0;

}