#include "stdc++.h"



using namespace std;

typedef long long ll;

ll a[200005];

ll b[200005];

ll tmpA[200005];

ll cnt=0;

void merge_sort(int l, int r, ll *A) {

	if (l >= r)

    {

        if(b[l]>=0)

            cnt++;

        return ;

    }

	int mid = (l + r) >> 1;

	merge_sort(l, mid, A);

	merge_sort(mid + 1, r, A);

	ll pl = l, pr = mid + 1, tmpp = 0;

	while(pl <= mid && pr <= r) {

		if (A[pl] <= A[pr]) tmpA[tmpp++] = A[pl++],cnt +=r - pr + 1;

		else tmpA[tmpp++] = A[pr++];

	}

	while(pl <= mid) tmpA[tmpp++] = A[pl++];

	while(pr <= r) tmpA[tmpp++] = A[pr++];

	for (int i = 0; i < tmpp; i++) A[i + l] = tmpA[i];

}



int main()

{

    int N;

    ll K;

    scanf("%d%lld",&N,&K);

    ll sum=0;

    for(int i=0;i<N;i++)

    {

        scanf("%lld",&a[i]);

        a[i]-=K;

        sum+=a[i];

        b[i]=sum;

    }

    merge_sort(0,N-1,b);

    printf("%lld",cnt);



}


