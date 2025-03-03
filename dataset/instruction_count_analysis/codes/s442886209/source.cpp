#include <cstdio>

#include <algorithm>

#include <vector>

#include <cstring>

using namespace std;

char str[1000005];

int main()

{

  scanf("%s",&str);

  int leng=strlen(str);

  int ans=0,i=0;

 for(;;)

    {

      if(str[i]=='J')

	{

	  int a=0,b=0,c=0;

	  while(str[i]=='J' && i<leng)

	    {

	      i++; a++;

	    }

	  while(str[i]=='O' && i<leng)

	    {

	      i++;

	      b++;

	    }



	  while(str[i]=='I' && i<leng)

	    {

	      i++;

	      c++;

	    }

	  if(b<=a && b<=c)

	    {

	      ans=max(ans,b);

	    }

		if(i==leng) break;

	}else{

	    i++;

            if(i==leng) break;

	}



    }



  printf("%d\n",ans);

  return 0;

}