#include <bits/stdc++.h>

// Macros
#define f first // But I never use pair
#define s second // Same as above
#define pb push_back
#define endl '\n' 
#define int long long
#define ll long long
// Namespace
using namespace std;

// DEBUG FUNCTIONS (very advance)
template<typename T>long long SIZE(T (&t)){return t.size();}
template<typename T, size_t N>long long SIZE(T (&t)[N]){return N;}
string to_string(char t){return "'" + string({t}) + "'";}
string to_string(bool t){return t ? "true" : "false";}
string to_string(const string &t, long long x1=0, long long x2=1e9){string ret = "";for(long long i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ret += t[i];}return '"' + ret + '"';}
string to_string(const char* t){string ret(t);return to_string(ret);}
template<size_t N>string to_string(const bitset<N> &t, long long x1=0, long long x2=1e9){string ret = "";for(long long i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ret += t[i] + '0';}return to_string(ret);}
template<typename T, typename... Coords>string to_string(const T (&t), long long x1=0, long long x2=1e9, Coords... C);
template<typename T, typename S>string to_string(const pair<T, S> &t){return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";}
template<typename T, typename... Coords>string to_string(const T (&t), long long x1, long long x2, Coords... C){string ret = "[";x1 = min(x1, SIZE(t));auto e = begin(t);advance(e,x1);for(long long i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ret += to_string(*e, C...) + (i != _i ? ", " : "");e = next(e);}return ret + "]";}
template<long long Index, typename... Ts>struct print_tuple{string operator() (const tuple<Ts...>& t) {string ret = print_tuple<Index - 1, Ts...>{}(t);ret += (Index ? ", " : "");return ret + to_string(get<Index>(t));}};
template<typename... Ts>struct print_tuple<0, Ts...> {string operator() (const tuple<Ts...>& t) {return to_string(get<0>(t));}};
template<typename... Ts>string to_string(const tuple<Ts...>& t) {const auto Size = tuple_size<tuple<Ts...>>::value;return print_tuple<Size - 1, Ts...>{}(t);}
void dbgr(){;}
template<typename Heads, typename... Tails>void dbgr(Heads H, Tails... T){cout << to_string(H) << " | ";dbgr(T...);}
void dbgs(){;}
template<typename Heads, typename... Tails>void dbgs(Heads H, Tails... T){cout << H << " ";dbgs(T...);}

// DEBUG
#ifndef ONLINE_JUDGE
#define dbgv(...) cerr << to_string(__VA_ARGS__) << endl;
#define dbg(...) cerr << "" << #__VA_ARGS__ << " = "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cerr << endl;
#define dbgm(...) cerr << "" << #__VA_ARGS__ << " = "; dbgr(__VA_ARGS__);
#else
#define dbgv(...)
#define dbg(...)
#define dbgr(...)
#define dbgm(...)
#endif

// Constants (uncomment for use)
// const int MOD = 1e9+7; 
// const int MX = 2e5+5; 
// const ll INF = 1e18; 
// const lld PI = acos((lld)-1);
bool isprime(int n){if(n==1){return false;}for(int i=2;i<=sqrt(n);i++){if(n%i==0){return false;}}return true;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
// Functions
bool helper(int cx, int cy, vector<vector<int>>&grid, vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    vis[cx][cy] = 1;
    q.push(make_pair(cx, cy));
    int ans = 1;
    while(q.empty()==0){

        pair<int,int>curr = q.front(); q.pop();
        dbg(curr);
        int x[] = {0, 0, -1, 1};
        int y[] = {1, -1, 0, 0};
        for(int i=0;i<4;i++){
            
            int ncx = curr.first + x[i], ncy = curr.second + y[i];
            cout<<ncx<<"__"<<ncy<<endl;
            if(ncx>=grid.size() || ncy>=grid.size() || ncx<0 || ncy<0){
                ans &= 0;
            }
            else if(vis[ncx][ncy]){continue;}
            else if(grid[ncx][ncy]){
                q.push(make_pair(ncx, ncy));
                vis[ncx][ncy]  = 1;
            }
        }
    }
    return ans;
}

// Solution
void solve(){
    int n; cin>>n;
    vector<vector<int>>grid(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int count = 0;
    vector<vector<int>>visited(n, vector<int>(n, 0));
    for( int i=0; i<n ;i++){
        for(int j=0;j<n;j++){
            
            if(visited[i][j]==0 && grid[i][j]==1){
                dbg(i); dbg(j);
                count+=helper(i, j, grid, visited);
                dbg(count);
                dbg(visited);
            }
            
        }
    }

    cout<<count<<endl;

}

// Main
int32_t main(){
    // Fast IO


    // Complete Solution
    int T;cin>>T;while(T--)
    solve();
    return 0;
}
