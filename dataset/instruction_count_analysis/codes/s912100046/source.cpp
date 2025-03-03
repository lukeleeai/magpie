

#include <unistd.h>



int main(int argc,char **argv){

	char s[4];

	read(0,s,3U);

	if(s[0]=='7'||s[1]=='7'||s[2]=='7') write(1,"Yes\n",4U);

	else write(1,"No\n",3U);

	return 0;

}
