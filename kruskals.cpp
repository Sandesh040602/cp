int parent[200005], size[200005];
#define pipi pair<int,pair<int,int>>
void make_set(int v) {
    for(int i=0;i<v;i++){
        parent[i] = i;
        size[i] = 1;
    }
    
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

int kruskals(vector<pipi>&edges, int n){
    int count = 0, ind = 0;
    int cost = 0ll;
    while(count<n-1){
        int a = edges[ind].s.f;
        int b = edges[ind].s.s;
        cout<<a<<":"<<b<<":"<<cost<<":"<<count<<endl;
        cout<<find_set(a)<<"::"<<find_set(b)<<endl;
        if(find_set(a)!=find_set(b)){
            cost+=edges[ind].f;
            count++;
            union_sets(find_set(a), find_set(b));
        }
        ind++;
    }
    return cost;
}
