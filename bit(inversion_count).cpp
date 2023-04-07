int n;
int MAXN;
vector<int>BIT(10005);

void update(int ind, int val){
    // dbg(ind)
    for(;ind<=10;ind+=(ind&(-ind))){
        BIT[ind]+=val;
    }
}

int sum(int ind){
    int count = 0;
    for(;ind>0;ind-=(ind&(-ind))){count+=BIT[ind];}
    return count;
}

// Solution
void solve(){
    cin>>n; vector<int>v(n+1);

    for(int i=1;i<=n;i++){cin>>v[i];}
    int count = 0ll;
    int ind = max_element(v.begin(), v.end()) - v.begin();
    MAXN = v[ind];
    for(int i=1;i<=n;i++){
        // dbg(count);
        count+=sum(v[ind]) - sum(v[i]);
        update(v[i], 1);
        // dbg(BIT);
    }
    cout<<count<<endl;
}
