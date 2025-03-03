#include <iostream>

#include <string>



using namespace std;



int main()

{

    int arr_size, AC_count = 0, WA_count = 0, TLE_count = 0, RE_count = 0;

    string array[100000], in;

    cin >> arr_size;

    for (int i = 0; i < arr_size; i++)

        cin >> array[i];

    for (int i = 0; i < arr_size; i++)

    {

        if (array[i] == "AC")

            AC_count++;

        else if (array[i] == "WA")

            WA_count++;

        else if (array[i] == "TLE")

            TLE_count++;

        else if (array[i] == "RE")

            RE_count++;

    }

    cout << "AC x " << AC_count << endl << "WA x " << WA_count << endl << "TLE x " << TLE_count << endl << "RE x " << RE_count << endl;

}


