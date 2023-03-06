vector<int> manachers(string s){
    string s1 = ""; s1+="#";
//     dbg(s1.length());
    for(int i=0;i<s.length();i++){  s1+=s[i];  s1+="#";  }
//     dbg(s1)
    vector<int>manc(s1.length(), 1ll);
    int c = 0, r=0;
    for(int i=1;i<s1.length();i++){
        int m_id = c - (i-c); 
        if(i<r){manc[i] = min(r-i, manc[m_id]);}
        while(i+manc[i]<s1.length() && i-manc[i]>=0 &&s1[i+manc[i]]==s1[i - manc[i]]){manc[i]++;}
        if(i+manc[i]>r){ r = i+manc[i]; c = i; }
    }
    return manc;
}

// now how to check whether the l and r are palindrome or not
bool haspm(int l, int r, vector<int>&manc){
    // the index in the manchers string
    int a1 = 2*l +1, a2 = 2*r +1;
    // now calculate the center
    int mid = a1+(a2-a1)/2;
    dbg(mid)
    if(mid%2)return manc[mid]>=(r-l+1);
    if(mid%2==0)return manc[mid]>=(r-l+2);
}
