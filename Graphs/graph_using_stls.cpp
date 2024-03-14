#include <bits/stdc++.h>

using namespace std;

class Graph {
    private:
        vector<vector<int>> adj;
        void dfs_util(int src, vector<int> &ans, int vis[]) {
            ans.push_back(src);
            vis[src] = 1;
            for (int i : adj[src]) {
                if (!vis[i]) this->dfs_util(i, ans, vis);
            }
        }
    public:
        Graph(int n) {
            this->adj = vector<vector<int>>(n, vector<int>());
        }
        void insert_edge(int from, int to) {
            this->adj[from].push_back(to);
        }
        vector<int> breadth_first_search(int src) {
            queue<int> q;
            int vis[this->adj.size()] = {};
            q.push(src);
            vis[src] = 1;
            vector<int> ans;
            while (!q.empty()) {
                int n = q.front();
                q.pop();
                ans.push_back(n);
                for (int i : adj[n]) {
                    if (!vis[i]) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
            return ans;
        }
        vector<int> depth_first_search(int src) {
            vector<int> ans;
            int vis[this->adj.size()];
            this->dfs_util(src, ans, vis);
            return ans;
        }
};

int main() {

    return 0;
}