include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n,m; cin>>n>>m;
    vector<int>adj[n+1];
    int t[n+1];
    while(m--) {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        cin>>t[i];
    }
    for(int i=1; i<=n; i++) {
        set<int> s;
        for(int j: adj[i]) {
            if(t[j]==t[i]) {
                cout << -1;
                return 0;
            } else if(t[j]<t[i]) {
                s.insert(t[j]);
            }
        }
        if(s.size()!=t[i]-1) {
            cout << -1;
            return 0;
        }
    }
    vector<pair<int, int >>p;
    for(int i=0; i<n; i++) {
        p.push_back(make_pair(t[i+1], i+1));
    }
    sort(p.begin(), p.end());
    for(int i=0; i<n; i++) {
        cout << p[i].second << " ";
    }
    return 0;
}
