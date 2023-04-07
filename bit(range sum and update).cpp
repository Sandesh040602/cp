int n;
int MAXN = 1e5+1;
vector<int>BIT(MAXN);
void BITconst(vector<int>&v){
    for(int i=1;i<=n;i++){
        // we have to add the value at v[i] to each and every
        // index that i lies into
        int j = i, x = v[i];
        for(;j<=n;j+=(j&(-j))){
            BIT[j]+=v[i];
        }
    }
    // to build the binary tree it will cost O(N*64); which comes down to
    // O(N)
}

int sum(int i){
    int cans = 0ll;
    for(;i>0;i-=(i&(-i))){cans+=BIT[i];}
    return cans;
}

void update(int i, int curr, int prev){
    for(;i<n;i+=(i&(-i))){BIT[i]+=(curr-prev);}
}



// Solution
void solve(){
    cin>>n;
    vector<int>v(n+1);
    for(int i=0;i<n;i++){cin>>v[i+1];}
    BITconst(v);
    int q; cin>>q;
    for(int i=0;i<q;i++){
        int type; cin>>type;
        if(type==1){
            int ind, val; cin>>ind>>val;
            update(ind, val, v[ind]);
            v[ind] = val;// now we will also update it for furthur use
        }
        if(type==2){
            int l, r;
            cin>>l>>r;
            cout<<sum(r) - sum(l-1)<<endl;
        }
    }
}
