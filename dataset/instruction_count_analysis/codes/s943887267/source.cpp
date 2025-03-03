#include<cstdio>

#include<algorithm>

using namespace std;



int a[100009],b[100009],c[100009],fa[100009],va[100009]={0},cva[100009]={0},cvb[100009]={0},xore=0;

bool is[100009]={0},vis=0;



int gf(int u){

	if(fa[u]==u){return u;}

	va[fa[u]]+=va[u];va[u]=0;

	return fa[u]=gf(fa[u]);

}



int main(){

	int n,res=0,tot,apos,bpos;

	scanf("%d",&n);

	for(int i=1;i<=n;i=-(~i)){scanf("%d",&a[i]);c[i]=a[i];xore^=a[i];}	

	sort(c+1,c+1+n);tot=unique(c+1,c+1+n)-c-1;

	for(int i=1;i<=tot;i=-(~i)){fa[i]=i;}fa[tot+1]=tot+1;

	for(int i=1;i<=n;i=-(~i)){

		scanf("%d",&b[i]);

		if(a[i]==b[i]){continue;}

		apos=lower_bound(c+1,c+1+tot,a[i])-c;

		bpos=lower_bound(c+1,c+1+tot,b[i])-c;

		if(c[bpos]!=b[i]){

			if(vis||b[i]!=xore){printf("-1\n");return 0;}

			else{vis=true;res--;bpos=tot+1;}//本质 xore 不参与离散化，也不参与并查集统计

		}

		cva[apos]++;cvb[bpos]++;

//		fprintf(stdout,"%d[%d:%d %d[%d:%d %d %d\n",a[i],c[apos],apos,b[i],c[bpos],bpos,tot,xore);

		if(gf(apos)!=gf(bpos)){va[fa[apos]]+=va[fa[bpos]];va[fa[bpos]]=0;fa[fa[bpos]]=fa[apos];}//注意顺序

		va[fa[bpos]]++;

	}

	for(int i=1;i<=tot;i=-(~i)){

		gf(i);

		if(c[i]==xore){vis=true;res--;cvb[i]--;}

		//不能直接用vis判断

		if(cva[i]<cvb[i]){printf("-1\n");return 0;}

	}

	for(int i=1;i<=tot;i=-(~i)){

		if(va[i]){res+=va[i]+1;}//fprintf(stdout,"%d:%d\n",c[i],va[i]+1);}

	}

	printf("%d\n",((res<0)?0:res));

	return 0;

}