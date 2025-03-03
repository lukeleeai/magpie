#include <stdio.h>

#define MAX_N 101



double t[MAX_N], v[MAX_N];



double max(double a, double b)

{

    return a > b? a: b;

}



double min(double a, double b)

{

    return a < b? a: b;

}



int main(void)

{

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)

        scanf("%lf", &t[i]);

    for (int i = 0; i < n; i++)

        scanf("%lf", &v[i]);

    double cur = 0.;

    double ans = 0.;

    for (int i = 0; i < n; i++) {

        double inc, kep, dec;

        double lim = 1.E8;

        double tmp = 0.;

        for (int j = i + 1; j <= n; j++) {

            lim = min(lim, v[j] + tmp);

            tmp += t[j];

        }

        inc = min(v[i] - cur, (lim + t[i] - cur) * .5);

        inc = min(inc, t[i]);

        dec = max(0., cur + inc - lim);

        kep = t[i] - inc - dec;

        ans += .5 * (cur * 2. + inc) * inc;

        ans += (cur + inc) * kep;

        ans += .5 * ((cur + inc) * 2. - dec) * dec;

        cur += inc;

        cur -= dec;

    }

    printf("%f\n", ans);

    return 0;

}