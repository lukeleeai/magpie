

#include <cstdio>



#include <algorithm>



#define LL long long



#define maxn 200010



using namespace std;



int a[maxn],n,cnt[maxn],mx;//cnt[]统计相同数值的元素数量



LL ans,out;



int main(){



	int i;



	scanf("%d",&n);



	for(i=1;i<=n;i++)

    {

        scanf("%d",&a[i]);

      cnt[a[i]]++;

      mx=max(mx,a[i]);

    }



	for(i=1;i<=mx;i++)



		if(cnt[i]>=2)ans+=(LL)cnt[i]*(cnt[i]-1)/2;//任选2个



	for(i=1;i<=n;i++)

    {



		if(cnt[a[i]]>=2){



			out=ans-cnt[a[i]]*(cnt[a[i]]-1)/2;//先扣除



			out+=(cnt[a[i]]-1)*(cnt[a[i]]-1-1)/2;//再加回



		}

		else out=ans;



		printf("%lld\n",out);



	}



	return 0;



}
