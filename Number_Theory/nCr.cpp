/*Daksh Dixit*/
#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 1000000007;
// const int mod = 998244353;
#define inf 1000000000000000005
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define ff first
#define ss second
#define yes cout << "YES" <<endl
#define no cout << "NO" <<endl
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()
#define rsz(arr,n) arr.clear();arr.resize(n)
#define print(x) cout<<x<<"\n"
#define fr(i,a,b) for(int i = a; i < b; i++)
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define has_bits(bit_mask, x) ((bit_mask) & (1ULL << (x)))
#define turn_on_bit(bit_mask, x) (bit_mask |= (1ULL << (x)))
#define turn_off_bit(bit_mask, x) (bit_mask &= (~( 1ULL << (x))))
#define smallest_on_bit(bit_mask) (__builtin_ctzll(int)((bit_mask) & (~(bit_mask))))
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //greater<int> for descending set, also less_equal<int> which is ascending multiset 
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
//DEBUG
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" = "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(ordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
int MSB(int n){return 63-__builtin_clzll(n);}
int getIthbit(int n, int i){return ( n & ( 1 << i) ) == 0 ? 0 : 1;}
void setIthBit(int &n, int i){ n = n | (1 << i);}
void clearIthBit(int &n, int i){ n = n & ( ~(1 << i));}
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int pwr(int a, int b,int m=mod) {a %= m; int res = 1; while (b > 0) {if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a){int arr[3];extendgcd(a, mod, arr); if(arr[2]!=1){return -1;}arr[0] =(arr[0]%mod + mod)%mod ;return arr[0];} //Modulo Inverse Exist only if gcd(a,m)=1;
int inv(int i,int m=mod) {if (i == 1) return 1; return (m - ((m / i) * inv(m % i)) % m) % m;}
int mminvprime(int a,int m=mod){int ans = pwr(a, m - 2); ans = (ans%m+m)%m; return ans;} //If a,m are Coprime
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
bool revsort(int a, int b) {return a > b;}
void google(int t) {cout << "Case #" << t << ": ";}
int mod_add(int a, int b,int m=mod) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b,int m=mod) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b,int m=mod) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b,int m=mod) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b)) + m) % m;}  //only for prime m
int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
int ceil_rem(int a, int b) {return a%b==0 ? b : a%b;}
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

// Common Facts:- 
// 1. nCk = (n-1)C(k-1) + (n-1)C(k);
// 2. No of ways to reach down in a matrix from n*m size = (n-1+m-1)C(n-1)

const int N = 2e6+5;
vi fact(N);
vi invFact(N);
void computeFact(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<N;i++){
        fact[i] = mod_mul(fact[i-1],i);
    }
    invFact[N-1] = mminvprime(fact[N-1]);
    for(int i=N-2;i>=0;i--){
        invFact[i] = mod_mul(i+1,invFact[i+1]);
    }
}

int nCr(int n, int r){
    if(n==r || n-r==n){
        return 1;
    }
    if(r>n){
        return 0ll;
    }
    int res = mod_mul(fact[n],invFact[n-r]);
    res = mod_mul(res,invFact[r]);
    return res;
}
int nCrIterative(int n, int r){
    if(n==r || n-r==n) return 1;
    if(r>n) return 0ll;
    if(r > n - r){
        r = n - r;
    }
    int ans = 1;
    for(int i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}



int nPr(int n, int r){
    int res = mod_mul(fact[n],invFact[n-r]);
    return res;
}

void solve(){
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
signed main(){
    fast;
    auto start1 = high_resolution_clock::now();
    // #ifndef ONLINE_JUDGE
    // freopen("shell.in", "r", stdin);
    // freopen("shell.out", "w", stdout);
    // #endif
    int t=1;
    cin>>t;
    computeFact();
    for(int i=1;i<=t;i++){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
