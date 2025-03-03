#include <iostream>



int main(void){

    int n, ans=0;

    std::cin >> n;



    for (int i=0; i<50001; ++i){

        if (i * 108 / 100 == n){

            ans = i;

            break;

        }

    }



    if (ans == 0){

        std::cout << ":(" << std::endl;

    } else {

        std::cout << ans << std::endl;

    }



    return 0;

}