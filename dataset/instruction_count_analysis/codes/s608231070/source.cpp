#include <iostream>



using namespace std;



int main()

{



    string firstType, secondType, chosenType;

    int firstTypeNumber, secondTypeNumber;



    cin >> firstType >> secondType >> firstTypeNumber

    >> secondTypeNumber >> chosenType;



    if (chosenType == firstType){

        firstTypeNumber--;

    }



    else{

        secondTypeNumber--;

    }



    cout << firstTypeNumber << " " << secondTypeNumber;



    return 0;

}
