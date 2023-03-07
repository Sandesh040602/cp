// this is binary search  appproach on lca it costs o(logN * logN)
int lca1(int a, int b){
    if(lvl[a]>lvl[b]){swap(a,b);}
    b = ans_query(b, lvl[b] - lvl[a]); 
    int l = 0, r = lvl[a], ans = lvl[a];
    while(l<=r){
        int mid = l+(r-l)/2;
        int a1 = ans_query(a,mid),a2 = ans_query(b,mid);
        if(a1!=a2){l=mid+1;}
        else{ans = mid; r = mid-1;}
    }
    ans = ans_query(a, ans);
    return ans;
}

// this lca2 take O(logN)
int lca2(int a,int b){
    // cout<<lvl[a]<<":::"<<lvl[b]<<endl;
    if (lvl[a]>lvl[b]){swap(a,b);}
    b = ans_query(b,lvl[b] - lvl[a]);
  
    if(a==b){return a;}
      for(int i=19;i>=0;i--){
        if(pre[a][i]!=pre[b][i]){a = pre[a][i]; b = pre[b][i];}
      }
    return ans_query(a, 1)==-1?1:ans_query(a,1);
}
