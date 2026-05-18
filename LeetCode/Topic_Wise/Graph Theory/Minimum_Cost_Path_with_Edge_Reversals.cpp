class Solution {
public:
    typedef pair<int , int> P;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<P>> adj;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v , w});
            adj[v].push_back({u , 2 * w});
        }

        priority_queue<P , vector<P> , greater<P>> pq;
        vector<int> res(n , INT_MAX);
        res[0] = 0;

        pq.push({0 , 0});

        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1) return res[n - 1];
            for (auto& p : adj[node]) {
                int adjNode = p.first;
                int dist = p.second;

                if (d + dist < res[adjNode]) {
                    res[adjNode] = d + dist;
                    pq.push({d + dist , adjNode});
                }
            }
        }
        return -1;
    }
};