#include<cstdio>

#include<cstring>

char s[100005];

int b[100005],w[100005],pb,pw,ac,turn;

int main(){

	scanf("%s",s);

	int len=strlen(s);

	pb=pw=0;

	for (int i=0; i<len; i++){

		if (s[i]=='B') b[++pb]=i;

		else w[++pw]=i;

	}

	if (b[pb]==len-1) turn = 0;

	else turn = 1;

	ac=0;

	while (pw>0&&pb>0){

		if (turn){

			++ac;

			while (pw>0&&w[pw]>b[pb]) --pw;

			if (!pw) break;

			turn ^=1;

		}

		else{

			++ac;

			while (pb>0&&b[pb]>w[pw]) --pb;

			if (!pb) break;

			turn ^=1;

		}

	}

	printf("%d\n",ac);

	return 0;

}