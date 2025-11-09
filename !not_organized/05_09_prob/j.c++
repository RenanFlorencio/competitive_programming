# include <vector>
# include <iostream>
# include <math.h>
using namespace std;

typedef long long ll;


vector<ll> dist;

void dfs(vector<bool> &visited, vector<vector<ll>> &adj, ll v, ll d) {
    visited[v] = true;
    dist[v] = d;

    for (ll u : adj[v]) {
        if (!visited[u])
            dfs(visited, adj, u, d + 1);
    }
}

int main(){
    ll n;
    ll a, b;
    cin >> n;
    vector<vector<ll>> adj(n); // graph represented as an adjacency list
    vector<bool> visited(n, false);
    dist.resize(n, 0);

    for (ll i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    if (n == 1){
        cout << 0 << endl;
        return 0;
    }

    dfs(visited, adj, a-1, 0);
    ll max_dist_idx = 0;
    ll max_dist = -1;

    for (ll i = 0; i < dist.size(); i++){
        if (dist[i] > max_dist){
            max_dist = dist[i];
            max_dist_idx = i;
        }
    }

    fill(visited.begin(), visited.end(), false);

    dfs(visited, adj, max_dist_idx, 0);

    max_dist_idx = 0;
    max_dist = -1;

    for (ll i = 0; i < dist.size(); i++){
        if (dist[i] > max_dist){
            max_dist = dist[i];
            max_dist_idx = i;
        }
    }

    cout << max_dist << endl;


    return 0;
}
