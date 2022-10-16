
// the below link is only for segment tree can be used but without lazy propogation
// link https://github.com/striver79/Competitive_Codes-/blob/master/STsum_update.cpp

// with lazyprop
class node{
	public:
	int val = 0, laz = 0;	
};
class SGTree {
	
public:
	vector<node> seg;
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high,vector<int>&arr) {
		if (low == high) {
			seg[ind].val = arr[low];
			seg[ind].laz = 0;
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind].val = seg[2 * ind + 1].val +  seg[2 * ind + 2].val;
		seg[ind].laz = 0;
		return;
	}

	node query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		node a;
		a.laz = 0;
		a.val = 0;
		// check for the pending laz and propogates downwards
		if(seg[ind].laz!=0){
			seg[ind].val+=(high-low+1)*seg[ind].laz;
			if(low!=high){
				seg[2*ind +1].laz+= seg[ind].laz;
				seg[2*ind +2].laz+= seg[ind].laz;
			}
			seg[ind].laz = 0;
		}
		// no overlap
		if (r < low || high < l){return a;}
		// complete overlap
		// [l low high r]
		if (low >= l && high <= r){return seg[ind];}
		int mid = (low + high) >> 1;
		node left = query(2 * ind + 1, low, mid, l, r);
		node right = query(2 * ind + 2, mid + 1, high, l, r);
		a.val = left.val + right.val;
		return a;
	}
	void update(int ind, int low, int high, int l, int r, int val) {
		cout<<low<<" "<<ind<<" "<<high<<endl;
		// check for the pending laz and propogates downwards
		if(seg[ind].laz!=0){
			seg[ind].val+=(high-low+1)*seg[ind].laz;
			if(low!=high){
				seg[2*ind +1].laz+= seg[ind].laz;
				seg[2*ind +2].laz+= seg[ind].laz;
			}
			seg[ind].laz = 0;
		}
		// no overlap
		
		if (r < low || high < l){ return;}
		// complete overlap
		// [l low high r]
		if (low >= l && high <= r){
			seg[ind].val = (high-low+1)*val;
			if(low!=high){
				seg[2*ind +1].laz+= val;
				seg[2*ind +2].laz+= val;
			}
			return;
		}
	// partial ppoverlaps
	
		int mid = (low + high) >> 1;
		update(2 * ind + 1, low, mid, l, r,val);
		// cout<<r<<"**"<<l<<"**"<<low<<"**"<<high<<endl;
		update(2 * ind + 2, mid + 1, high, l, r,val);
		seg[ind].val = seg[2*ind +1].val + seg[2*ind +2].val;
		return;
	}
};
