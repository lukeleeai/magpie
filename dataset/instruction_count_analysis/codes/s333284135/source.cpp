#include <stdio.h>

#include <cstring>



double P, E, T;



double fabs(double x){

    if(x < 0) x = -x;

    return x;

}



double dfs(int k, double pro, double L, double R){

    if(k == 0){

        double mid = (L + R) / 2;

        if(fabs(mid - T) <= E) return pro;

        return 0;

    }

    if(T + E < L || T - E > R) return 0;

    double ans = 0;

    double mid = (L + R) / 2;

    if(fabs(R - T) <= E && fabs(T - L) <= E) return pro;

    if(mid >= T){

        ans += dfs(k - 1, pro * (1 - P), L, mid);

        ans += dfs(k - 1, pro * P, mid, R);

    }

    else{

        ans += dfs(k - 1, pro * P, L, mid);

        ans += dfs(k - 1, pro * (1 - P), mid, R);

    }

    return ans;

}

int main(){

    //freopen("input.txt", "r", stdin);

    int K;

    double L, R;

    scanf("%d %lf %lf", &K, &L, &R);

    scanf("%lf %lf %lf", &P, &E, &T);

    double ans = dfs(K, 1.0, L, R);

    printf("%lf\n", ans);

    return 0;

}