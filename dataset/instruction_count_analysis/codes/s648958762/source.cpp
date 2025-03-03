//??：4s   空?：256MB

//?意:在一?无?深的二叉?上挂牌子,?定n个操作,表示在深度?di

//的子?点?挂牌子,如果符合到根的路径上只有1个牌子,那?就挂上去

//如果可以挂一定要挂,根?点深度?0

//算法:直接模?挂牌操作,??当前挂牌的情况,??当前允?挂牌上界 

//和最深的位置,如果某个的位置出?了??牌子,通?移?可以将他?

//移?至同一?子?,然后将其向上?点,更新最深点

//?于最浅的点,可以将牌子按照深度,从左挂到右?,可以??如果

//当前最浅深度的一个子?点挂牌,那就将挂牌上界往下移?

//因?只有?外一个子?点可以挂牌子了,如果?外一个子?点的一个

//儿子又有牌子,那就??将上界下移? 

//?个子?点都被挂牌,相当于自己被挂牌子 

//如果根?点被挂上牌子,就直接No,如果在最浅位置上方,那也不能挂

//当然如果上界和最深?不相等,上界?个深度明?是不能挂牌的 

//?于?目的数据,是不可能?下整个??数?的,所以?于明?可行的

//操作直接跳?就可以了(在根没有挂牌子的情况下)但是需要更新一下

//最深的深度 

#include<cstdio>

#include<algorithm>

using namespace std;

int d[1000005];

int main(){

	//freopen("a.in","r",stdin);

	//freopen("a.out","w",stdout);

	int n;

	scanf("%d",&n);

	int top=0,down=0;

	while(n--){

		int x;

		scanf("%d",&x);

		if(d[0]||x<top){printf("No\n");continue;}		

		if(x==top&&top!=down){printf("No\n");continue;}

		if(x>=1000000){printf("Yes\n");down=max(down,x);continue;}

		d[x]++;down=max(down,x);

		while(d[x]>=2){

			d[x-1]++;

			d[x]=0;

			if(x==down)down--;

			x--;

		}

		for(int i=top+1;d[i]==1;i++)

			top=i;

		printf("Yes\n");

	}

	return 0;

} 