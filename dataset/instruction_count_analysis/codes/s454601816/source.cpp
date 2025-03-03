#include <iostream>

#include <string>

#include <cstdlib>





using namespace std;



int main()

{

    string Letter;

    string Vowel[] = {"a","e","i","o","u"};

    cin >> Letter;

    if(Letter == Vowel[0] || Letter == Vowel[1] || Letter == Vowel[2] || Letter == Vowel[3] || Letter == Vowel[4]){

        cout << "vowel" << endl;

    }else{

        cout << "consonant" << endl;

    }

    return 0;

}
