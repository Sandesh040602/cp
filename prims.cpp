int prims(vector<vector<pair<int,int>>>&edges, int  n){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    int count = 0;
    vector<int>visited(n, 0ll);
    visited[0]=1;
    pq.push(make_pair(0,0));

    int cost = 0;

    while(count<n && pq.size()){
        while(pq.size() && visited[pq.top().s]){
            pq.pop();
        }
        pair<int,int>p = pq.top();
        cout<<p.f<<"::"<<p.s<<endl;
        visited[p.s] = 1;
        cost+=p.f;
        count++;
        for(int i=0;i<edges[p.s].size();i++){
            if(visited[edges[p.s][i].f]==0){
                pq.push(make_pair(edges[p.s][i].s,edges[p.s][i].f));
            }
        }
    }
    return cost;
}
// complexity((E+V)logE)
