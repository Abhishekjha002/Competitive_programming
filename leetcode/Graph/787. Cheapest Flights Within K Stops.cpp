class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<pair<int,int>>> graph(n);
        
        for(vector<int>& arr : flights)
        {
            graph[arr[0]].push_back({arr[1], arr[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,src,K+1});
        
        while(pq.size() != 0)
        {
            vector<int> rvtx = pq.top();
            pq.pop();
            
            if(rvtx[1] == dst)
                return rvtx[0];
            
            if(rvtx[2] == 0)
                continue;
            
            for(pair<int,int>& e : graph[rvtx[1]])
                pq.push({e.second + rvtx[0], e.first, rvtx[2]-1});
        }
        
        return -1;
        
    }
};