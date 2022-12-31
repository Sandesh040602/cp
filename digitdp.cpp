
int dp[101][181][2];

int helper(int n,int x,int tight,string&nums){
    // n represents the index which we want to fill
    if(n==(nums.length())){
        if(x){return 0;}
        return 1;
    }
    if(x<0){return 0;}
    if(dp[n][x][tight]!=-1){return dp[n][x][tight];}
    int ub = tight? (nums[n]-'0'):9;
    int curr = 0ll;
    for(int i=0;i<=ub;i++){
        curr+=helper(n+1,x-i,tight = (tight==1?(i==ub):tight),nums);
    }
    return dp[n][x][tight] = curr;
}

// Solution
void solve(){
    memset(dp, -1,sizeof dp);
    int l,r,x;
    cin>>l>>r>>x;
    string s2 =  to_string(r);
    string s1 =  to_string(l-1);
    int ans2 = helper(0,x,1,s2);
    int ans1 = helper(0,x,1,s1);
    cout<<ans2 - ans1<<endl;

}
