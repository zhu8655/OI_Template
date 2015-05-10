int root, tail, f[MAXN], s[MAXN][2], key[MAXN];
int sz[MAXN], num[MAXN];
void newnode(int &U, int F, int X) {
	U = ++tail;
	f[U] = F; s[U][0] = s[U][1] = 0; key[U] = X;
	sz[U] = num[U] = 1;
}
void pu(int U) {
	sz[U] = num[U] + (s[U][0] ? sz[s[U][0]] : 0) + (s[U][1] ? sz[s[U][1]] : 0);
}
void link(int U, int S, int V) {
	f[V] = U; if (U) s[U][S] = V;
}
void rot(int U) {
	int F = f[U], S = s[F][0] == U;
	link(f[F], s[f[F]][1] == F, U);	link(F, !S, s[U][S]); link(U, S, F); pu(F);
}
void splay(int U, int TAR) {
	while (f[U] != TAR && f[f[U]] != TAR) {
		((s[f[f[U]]][0] == f[U]) == (s[f[U]][0] == U)) ? rot(f[U]) : rot(U); rot(U);
	}
	if (f[U] != TAR) rot(U);
	pu(U); if (!TAR) root = U;
}
int find(int X) {
	int U = root;
	while (U && key[U] != X) U = s[U][key[U]<X];
	if (U) splay(U, 0); return U;
}
int findKth(int K) {
	if (sz[root]<K) return 0;
	int U = root;
	while (K) {
		if (sz[s[U][0]] < K && sz[s[U][0]] + num[U] >= K) break;
		if (sz[s[U][0]] < K) {
			K -= sz[s[U][0]] + num[U];
			U = s[U][1];
		}
		else U = s[U][0];
	}
	if (U) splay(U, 0); return U;
}
void ins(int X) {
	if (!root) {
		newnode(root, 0, X); return;
	}
	int U = root;
	while (s[U][key[U] < X]) {
		if (key[U] == X) {
			num[U]++; splay(U, 0); return;
		}
		U = s[U][key[U] < X];
	}
	if (key[U] == X) {
		num[U]++; splay(U, 0); return;
	}
	newnode(s[U][key[U] < X], U, X); splay(s[U][key[U] < X], 0);
}
int prev() {
	int U = s[root][0];
	if (!U) return 0;
	while (s[U][1]) U = s[U][1];
	return U;
}
int succ() {
	int U = s[root][1];
	if (!U) return 0;
	while (s[U][0]) U = s[U][0];
	return U;
}
void del(int L, int R) {
	if (!find(L)) ins(L); int U = prev();
	if (!find(R)) ins(R); int V = succ();
	if (!U && !V) { root = 0; return; }
	if (!U) { s[root][0] = 0; pu(root); return; }
	if (!V) { splay(U, 0); s[root][1] = 0; pu(root); return; }
	splay(U, V); s[U][1] = 0; pu(U); pu(V);
}