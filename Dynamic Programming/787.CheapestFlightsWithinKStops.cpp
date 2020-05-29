/*
	Constrained Dijkstra's DP Question
	Time Complexity: O(EKlogV)
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        set<pair<int,int>>s;
        int dist[n][n+1];
        bool vis[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=n;j++)
            dist[i][j]=INT_MAX;
            vis[i]=0;
        }
        dist[src][0]=0;
        s.insert({0,src});
        while(!s.empty())
        {
            pair<int,int>node=*s.begin();
            s.erase(s.begin());
            int val=node.second;
            bool fl=0;
            for(int j=0;j<=n;j++)
                fl|=(dist[val][j]!=INT_MAX);
            if(!fl)
              break;
            vis[val]=1;
            for(auto it:adj[val])
            {
                if(vis[it.first])
                    continue;
                int weight=it.second;
                for(int j=0;j<=n;j++)
                {
                    if(dist[val][j]==INT_MAX)
                        continue;
                    if(j<=K && dist[it.first][j+1]>dist[val][j]+weight)
                    {
                        dist[it.first][j+1]=dist[val][j]+weight;
                    }
                    s.insert({dist[it.first][j+1],it.first});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=n;i++)
            ans=min(ans,dist[dst][i]);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
// https://leetcode.com/problems/cheapest-flights-within-k-stops
