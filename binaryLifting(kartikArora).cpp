int pre[200005][40];

// preprocessing the data
void pro1(vector<vector<int>>&child, int node,int parent){
    pre[node][0] = parent;
    for(int i=1;i<32;i++){
        if(pre[node][i-1]!=-1){
            pre[node][i] = pre[pre[node][i-1]][i-1];
        }
        else{
            pre[node][i] = -1;
        }
    }
    for(int i=0;i<child[node].size();i++){
        pro1(child, child[node][i], node);
    }
}

// finding the answer
int ans_query(int node, int jump_required){
    if(node==-1 || jump_required==0){
        return node;
    }
    for(int i=19;i>=0;i--){
        if(jump_required>=(1<<i)){
            return ans_query(pre[node][i], jump_required-(1<<i));
        }
    }
}


// Solution
void solve(){
    
    int n,q; cin>>n>>q;
    vector<int>parent(n+1);
    vector<vector<int>>childs(n+1);
    for(int i=2;i<=n;i++){
        cin>>parent[i];
        childs[parent[i]].pb(i);
    }
    // now what we would have to do is preprocessing
    memset(pre, -1ll, sizeof(pre));
    pro1(childs, 1, -1);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<ans_query(a,b)<<endl;
    }
    
}
