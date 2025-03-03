/*

    Name: *3 or /2 

    Author: FZSZ-LinHua

    Date: 2018 06 16

    Exec time: 2ms

    Memory usage: 256KB

    Score: 300

    Algorithm: Bit operation 

*/

# include "cstdio"



inline int read(){

	int s=0,w=1;

	char ch=getchar();

	while(ch<'0' || ch>'9'){

		if(ch=='-') w=-w;

		ch=getchar();

	}

	while(ch>='0' && ch<='9'){

		s=s*10+ch-'0';

		ch=getchar();

	}

	return s*w;

}



inline int n_lowbit(int x){	//取出含有质因子2的个数 

	int count=0;

	while(x){

		if(x&1){

			return count; 

		}

		count++; 

		x>>=1; 

	}

	return count; 

} 



int

	ans, //记录答案 

	N; 



int main(){

	N=read();

	while(N--){

		ans+=n_lowbit(read()); //更新答案 

	}

	printf("%d",ans); 

	return 0; 

} 