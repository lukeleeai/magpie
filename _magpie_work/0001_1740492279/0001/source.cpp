#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

void problemOne(){
    int a, b;
    while (cin >> a >> b){
        int sum = a + b;
        int intLength = (sum == 0) ? 1 : (int)log10(sum) + 1;
        cout << intLength << endl;
    }
}

int main(){
    problemOne();
}
