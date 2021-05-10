

#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int wt[1000][1000];
int edges;
set<pair<int, int>> dict; int ct = 0;
void ways(vector<int> adj[], int st, int curr) {
    if (dict.size() == 0) return;
    if (st == curr) {
        for (auto x : adj[st]) {
            auto it = dict.find(make_pair(dp[st][x], x));
            dict.erase(it);
            //   cout << wt[st][x] << endl;
            dict.insert(make_pair(wt[st][x], x));
            dp[st][x] = wt[st][x];
        }
        auto it = dict.begin();
        if (it == dict.end()) return;
        curr = it->second;
        int dist = it->first;
        dict.erase(it);
        cout << curr << " " << dist << endl;
        ways(adj, st, curr);
    }
    else {
        for (auto x : adj[curr]) {
            if (dp[st][x] > wt[curr][x] + dp[st][curr]) {
                auto it = dict.find(make_pair(dp[st][x], x));
                dict.insert(make_pair(wt[curr][x] + dp[st][curr], x));
                dict.erase(it);
                dp[st][x] = wt[curr][x] + dp[st][curr];
            }
        }
        auto it = dict.begin();
        if (it == dict.end()) return;
        curr = it->second;
        cout << curr << " " << it->first << endl;
        dict.erase(it);
        ways(adj, st, curr);
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    int i, j, k, n, m, ct = 0, t, ans = 0, source;
    cin >> n >> edges;
    vector<int> adj[n + 1];
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            dp[i][j] = 1e9; wt[i][j] = 1e9;
        }
    }
    for (i = 1; i <= edges; i++) {
        cin >> j >> k >> m;
        adj[j].push_back(k);
        wt[j][k] = m;
    }
    for (i = 1; i <= n; i++) dict.insert(make_pair(1e9, i));
    cin >> source;
    dict.erase(make_pair(1e9, source));
    // for (auto x : adj[source]) dp[source][x] = wt[source][x];
    // dp[source][source] = 0;
    ways(adj, source, source);
    return 0;
}
