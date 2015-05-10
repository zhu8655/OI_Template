struct Dijkstra{
	int hCnt, idx[MAXN][2];
	int nCnt, mCnt, fir[MAXN], nxt[MAXM], e[MAXM][2], dis[MAXN], vis[MAXN];
	
	void swim(int U) {
		int tmp = idx[U][0];
		for (int V = U>>1; V; U = V, V >>= 1) {
			if (dis[idx[V][0]] > dis[tmp]) {
				idx[U][0] = idx[V][0];
				idx[idx[U][0]][1] = U;
			}
			else break;
		}
		idx[U][0] = tmp; idx[idx[U][0]][1] = U;
	}
	void sink(int U) {
		int tmp = idx[U][0];
		for (int V = U<<1; V <= hCnt; U = V, V <<= 1) {
			if (V < hCnt && dis[idx[V][0]] > dis[idx[V+1][0]]) V++;
			if (dis[idx[V][0]] < dis[tmp]) {
				idx[U][0] = idx[V][0];
				idx[idx[U][0]][1] = U;
			}
			else break;
		}
		idx[U][0] = tmp; idx[idx[U][0]][1] = U;
	}
	void push(int P) {idx[++hCnt][0] = P; swim(hCnt);}
	void pop() {idx[1][0] = idx[hCnt][0]; hCnt--; sink(1);}
	inline void addEdge(int U, int V, int W) {
		e[++mCnt][0] = V; e[mCnt][1] = W; nxt[mCnt] = fir[U]; fir[U] = mCnt;
		e[++mCnt][0] = U; e[mCnt][1] = W; nxt[mCnt] = fir[V]; fir[V] = mCnt;
	}
	int solve(int S, int T) {
		for (int i = 1; i <= nCnt; i++) {dis[i] = INF; vis[i] = 0;} dis[S] = 0; vis[S] = 1;
		for (int E = fir[S]; E; E = nxt[E]) if (dis[e[E][0]] > e[E][1]) dis[e[E][0]] = e[E][1];
		for (int i = 1; i <= nCnt; i++) if (i != S) push(i);
		while (hCnt) {
			int U = idx[1][0]; pop(); vis[U] = 1;
			if (vis[T]) return dis[T];
			for (int E = fir[U]; E; E = nxt[E]) {
				int V = e[E][0]; if (vis[V]) continue;
				if (dis[V] > dis[U]+e[E][1]) {
					dis[V] = dis[U]+e[E][1];
					swim(idx[V][1]);
				}
			}
		}
	}
} dij;