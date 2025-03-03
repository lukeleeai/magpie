#include <cstdio>



using namespace std; 



int sum_of_digit[100001];



int main() {

    int N;

    scanf("%d", &N);



    int prefix_sum = 0;

    int cur_sum = 0;

    for (int i = 0; i < N; i++) {

        int cur_digit_sum = 0;

        int cur_number = i;

        while (cur_number > 0) {

            cur_digit_sum += cur_number % 10;

            cur_number /= 10;

        }

        sum_of_digit[i] = cur_digit_sum;

    }

    

    int min = (1 << 31) - 1;

    int round = (N >> 1) + 1;

    for (int i = 1; i <= round; i++) {

        int pair = N - i;

        if (pair >= i) {

            int temp = sum_of_digit[i] + sum_of_digit[pair];

            if (temp < min) {

                min = temp;   

            }

        } else {

            break;

        }

    }

    printf("%d\n", min);

    return 0;

}