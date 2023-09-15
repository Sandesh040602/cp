int parent[200005], size[200005];
// make sure to submit it under the c++14
// else change the name of the size array
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
////////////////////////////////// DSU ENDS HERE
//////////////////////////////topo sort starts here
    9void toposort_dfs(vector<int>&cans, int node, vector<vector<int>>&edges, vector<int>&vis){
        if(vis[node]){return;}
        vis[node] = 1;
        for(int i=0;i<edges[node].size();i++){
            if(!vis[edges[node][i]]){
                toposort_dfs(cans, edges[node][i], edges, vis);
            }
        }
        cans.push_back(node);
        return;
    }


