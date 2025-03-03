#include<cstdio>

using namespace std;



int main(){

  int r,c,q,a[50000],b[50000],o[50000];

  int nr,nc;

  bool row[50000],col[50000];

  long long int ans;



  while(1){

    scanf("%d %d %d",&r,&c,&q);

    if(!r && !c && !q)break;



    for(int i=0;i<r;i++)row[i] = false;

    for(int i=0;i<c;i++)col[i] = false;



    ans = nr = nc = 0;

    for(int i=0;i<q;i++)scanf("%d %d %d",&a[i],&b[i],&o[i]);



    for(int i=q-1;i>=0;i--){

      if(a[i]){

	if(!col[b[i]]){

	  if(o[i])ans += r-nr;

	  col[b[i]] = true;

	  nc++;

	}

      }else{

	if(!row[b[i]]){

	  if(o[i])ans += c-nc;

	  row[b[i]] = true;

	  nr++;

	}

      }

    }

 

    printf("%lld\n",ans);

  }

}