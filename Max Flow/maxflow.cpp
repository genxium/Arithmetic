#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 1020
#define INF 1000000000
using namespace std;

struct Node{
	int w, id;
};
vector<Node> edge[MAXN];

int g[MAXN][MAXN], n, m, t, ans, sum;
int lab[MAXN], queue[MAXN], gap[MAXN], visit[MAXN], pre[MAXN];
int hash[100010];

int max_flow(int n, int S, int T) {
	int f, r, i, j, k, flow = 0;
	for(i = 0; i < n; lab[i++] = n) // lab[i] indicates the distance from node n to node i
		gap[i] = visit[i] = 0;

	f = i = 0; //f: front
	r = 1; // r: rear
	queue[0] = T;
	visit[T] = 1;
	while (f < r) { // bfs, building the labels lab[]
		for (k = r; f < k; f++){
			lab[queue[f]] = i;
			gap[i]++;
			for(j = 0; j < n; j++)
				if(g[j][queue[f]] && !visit[j]) {
					queue[r++] = j;
					visit[j] = 1;
				}
		}
		i++;
	}

	f = S;

	while (lab[S]<n) {

		if (f == T) {
			int min = INF;
			for (i = f; i != S; i = pre[i]) // find bottle neck flow
				if(g[pre[i]][i] < min)
					min = g[pre[i]][i];

			for (i = f ; i != S; i = pre[i]) {
				g[pre[i]][i] -= min;
				g[i][pre[i]] += min;
			}

			if (min != INF)	flow += min;

			f = S; // reset f to start finding another path
		}

		for (i = 0; i < n; i++) // find the shortest path successor
			if (g[f][i] && lab[i] + 1 == lab[f]) break;

		if(i < n) {
			pre[i] = f;
			f = i;
		} else {
			if (--gap[lab[f]] == 0) break;
			int tmp=n;
			for (i = 0; i < n; i++)
				if (g[f][i] && lab[i] < tmp)
					tmp = lab[i];
			lab[f] = tmp + 1;
			gap[lab[f]]++;
			if (f != S) f = pre[f];
		}
	}// while
	return flow;
}
