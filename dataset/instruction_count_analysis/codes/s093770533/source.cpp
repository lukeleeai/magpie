//------(▼皿▼#) fxxk vjudge-------

#include <algorithm>

#include <cstdio>



const int Maxv = 200010; 



int num[Maxv], n; 

long long ans; 



int main() {

    scanf("%d", &n); 

    for (int i = 0; i < n; i++) {

        scanf("%d", &num[i]); 

        num[i] -= i + 1; 

    }

    

    std::sort(num, num + n); 

    int tmp = num[(n >> 1)]; 



    for (int i = 0; i < n; i++) 

        ans += abs(num[i] - tmp); 



    printf("%lld\n", ans); 



    return 0; 

}