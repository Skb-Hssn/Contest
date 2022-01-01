#include<bits/stdc++.h>
using namespace std;
/* 
    0-based indexing
    Tested:
        https://judge.yosupo.jp/problem/lca

*/

// int N, L;
// vector<int> G[500'005];

// int timer = 1;
// vector<int> tin, tout;

// vector<vector<int>> up;

// void dfs(int u, int p)
// {
//     tin[u] = timer++;
//     up[u][0] = p;

//     for(int i = 1; i <= L; i++) {
//         up[u][i] = up[up[u][i-1]][i-1];
//     }

//     for(int to : G[u]) {
//         if(to != p) {
//             dfs(to, u);
//         }
//     }

//     tout[u] = timer++;
// }

// bool is_ancestor(int u, int v)
// {
//     return tin[u] <= tin[v] && tout[u] >= tout[v];
// }

// int lca(int u, int v)
// {
//     if(is_ancestor(u, v)) return u;
//     if(is_ancestor(v, u)) return v;

//     for(int i = L; i >= 0; i--) {
//         if(!is_ancestor(up[u][i], v)) {
//             u = up[u][i];
//         }
//     }

//     return up[u][0];
// }

// void init(int root)
// {
//     tin.resize(N);
//     tout.resize(N);
//     L = ceil(log2(N));
//     up.assign(N, vector<int>(L+1));
//     dfs(root, root);
// }

struct LCA {
    int L = 18;
    vector<vector<int>> G;
    vector<vector<int>> up;
    vector<int> tin, tout;
    vector<int> height;
    int n, root;
    int timer = 1;
    LCA() {}
    LCA(vector<vector<int>>& _G, int _root) {
        G = _G;
        root = _root;
        n = (int)G.size();
        L = ceil(log2(n));
        up.assign(n, vector<int>(L+1));
        tin.assign(n, 0);
        tout.assign(n, 0);
        height.assign(n, 0);
        dfs(root, root);
    }

    void dfs(int u, int p, int h = 0)
    {
        tin[u] = timer++;
        up[u][0] = p;
        height[u] = h;
        for(int i = 1; i <= L; i++) {
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for(int to : G[u]) {
            if(to != p) {
                dfs(to, u, h+1);
            }
        }
        tout[u] = timer++;
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v)
    {
        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;
        for(int i = L; i >= 0; i--) {
            if(!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

    int distance(int u, int v)
    {
        return height[u] + height[v] - 2*height[lca(u, v)];
    }
}lca;
