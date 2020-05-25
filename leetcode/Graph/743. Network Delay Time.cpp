class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
     
        vector<vector<pair<int,int>>> graph(N+1);
        
        for(vector<int> arr : times)
        {
            graph[arr[0]].push_back({arr[1],arr[2]});
        }
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,K});
        
        vector<int> dis(N+1,-1);
        
        while(pq.size() != 0)
        {
            pair<int,int> rvtx = pq.top();
            pq.pop();
            
            if(dis[rvtx.second] != -1)
                continue;
            
            dis[rvtx.second] = rvtx.first;
            
            for(pair<int,int>& e : graph[rvtx.second])
            {
                if(dis[e.first] == -1)
                {
                    pq.push({rvtx.first + e.second, e.first});
                }
            }
        }
        
        int ans = 0;
        
        for(int i=1;i<=N;i++)
        {
            if(dis[i] == -1)
                return -1;
            else
                ans = max(ans,dis[i]);
        }
        
        return ans;
        
    }
};