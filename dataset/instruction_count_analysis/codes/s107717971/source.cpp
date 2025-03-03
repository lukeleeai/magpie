#include "stdc++.h"

int h, w, k, x1, yy1, x2, y2, d[4] = {1,-1}, mp[2000005], qu[1000005], b, e, inf=1e9;

int main(){

	scanf("%d%d%d", &h, &w, &k); w++;

	scanf("%d%d%d%d", &x1, &yy1, &x2, &y2); x1--; x2--;

	memset(mp,-1,sizeof(mp));

	for(int i=0; i<h*w; i++) if(getchar() == '.') mp[i] = inf;

	mp[qu[e++] = x1*w+yy1] = 0;

	d[2] = w; d[3] = -w;

	while(b<e) for(int i=0, x=qu[b++]; i<4; i++) for(int nx=x+d[i], u=0; u<k && 0<=nx && mp[nx]>mp[x]; u++, nx+=d[i]) if(mp[nx] == inf) mp[qu[e++] = nx] = mp[x] + 1;

	printf("%d\n", mp[x2*w+y2] == inf ? -1 : mp[x2*w+y2]);

}