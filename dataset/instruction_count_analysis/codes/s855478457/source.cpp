#include "stdc++.h" 

 

#define INF (1<<31)//INT_MAX/2

#define MOD 1000000007

 

using ll  = long long;

using ull = unsigned long long;

 

int main(int argc, char *argv[])

{

    std::string a, b;

    std::cin >> a >> b;



    bool flag = false;

    int num = std::stoi(a+b);

    for (int i = 1; i < 1000000; i++) {

        if (i*i == num) {

            flag = true;

        } else {

            ;

        }

    }



    if (flag) {

        std::cout << "Yes" << std::endl;

    } else {

        std::cout << "No"  << std::endl;

    }

    return 0;

}