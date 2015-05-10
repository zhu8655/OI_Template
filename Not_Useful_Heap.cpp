struct heap{
	int hCnt, a[MAXN], idx[MAXN][2];
	inline void clear() {hCnt = 0;}
	inline void swp(int U, int V) {a[U] = a[V]; idx[U][0] = idx[V][0];}
	void swim(int U) {
		int tmp[] = {a[U], idx[U][0]};
		for (int V = U>>1; V; U = V, V >= 1) {
			if (a[V] > tmp[0]) {
				swp(V, U);
				idx[idx[U][0]][1] = U;
			}
			else break;
		}
		a[U] = tmp[0]; idx[U][0] = tmp[1]; idx[idx[U][0]][1] = U;
	}
	void sink(int U) {
		int tmp[] = {a[U], idx[U][0]};
		for (int V = U<<1; V <= hCnt; U = V, V <<= 1) {
			if (V < hCnt && a[V] > a[V+1]) V++;
			if (a[V] < tmp[0]) {
				swp(V, U);
				idx[idx[U][0]][1] = U;
			}
			else break;
		}
		a[U] = tmp[0]; idx[U][0] = tmp[1]; idx[idx[U][0]][1] = U;
	}
	void push(int X) {a[++hCnt] = X; swim(hCnt);}
	int pop() {int ret = a[1]; swp(1, hCnt--); sink(1); return ret;}
} h;