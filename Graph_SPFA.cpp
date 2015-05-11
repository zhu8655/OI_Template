struct SPFA {
	int nCnt, mCnt, fir[MAXN], nxt[MAXM], e[MAXM][2], dis[MAXN];
	int q[100*MAXM], vis[MAXN];
	
	void addEdge(int U, int V, int W) {
		e[++mCnt][0] = V; e[mCnt][1] = W; nxt[mCnt] = fir[U]; fir[U] = mCnt;
		e[++mCnt][0] = U; e[mCnt][1] = W; nxt[mCnt] = fir[V]; fir[V] = mCnt;
	}
	int solve(int S, int T) {
		for (int i = 2; i <= nCnt; i++) {vis[i] = 0; dis[i] = INF;}
		int h = 0, t = 1; q[t] = S; dis[S] = 0;
		while (h < t) {
			int U = q[++h]; vis[U] = 0;
			for (int E = fir[U]; E; E = nxt[E]) {
				int V = e[E][0];
				if (dis[V] > dis[U]+e[E][1]) {
					dis[V] = dis[U]+e[E][1];
					if (vis[V] == 0) {
						vis[V] = 1; q[++t] = V;
					}
				}
			}
		}
		return dis[T];
	}
} g;