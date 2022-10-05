#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//find_by_order = returns pointer to element at that pos
//order_of_key = returns pos of the given element
#define indexed_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define all(x)  (x).begin(),(x).end() 
#define mem1(a)  memset(a,-1,sizeof(a))
#define mem0(a)  memset(a,0,sizeof(a))  
#define int long long
#define ldd long double
#define endl "\n"
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <b; i++)
#define MOD 1000000007
#define boost
#define printv(x, size) for (size_t tk = 0; tk < size; tk++) {cout << x[tk] << " ";} cout<<endl;
/* #define cerr if(false)cerr */
#ifndef ONLINE_JUDGE
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define checkv(x, size) for (size_t tk = 0; tk < size; tk++) {cout << x[tk] << " ";} cout<<endl;
#else
#define debug1(x);
#define debug2(x,y);
#define debug3(x,y,z);
#define checkv(x, size); 
#endif
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.F>>a.S;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.F<<" "<<a.S;return out;}
template<class _T>inline void read(_T &_a)
{
    bool f=0; char _c=getchar(); _a=0;
    while(_c<'0'||_c>'9'){ if(_c=='-') f=1; _c=getchar(); }
    while(_c>='0'&&_c<='9'){ _a=(_a<<3)+(_a<<1)-'0'+_c; _c=getchar(); }
    if(f) _a=-_a;
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = custom_hash{}(p.first);
        auto hash2 = custom_hash{}(p.second);
        return hash1 ^ (hash2>>1);
        //use any non-symmetric functions like 3*a + b or a ^(b>>1) in case of pairs for custom hashing
    }
};
//unordered_map<pi,int,hash_pair> mp;
//unordered_map<int,int,custom_hash> mp;

const long long INF=1e18;
int T=1;



int32_t main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cin>>T;
      while(T--)
   {
        string s;
        cin>>s;
        int  n = s.size();
        int vis[n+1];
        mem0(vis);
        int a[n+1];
        mem1(a);
        function<int(int)> cnt = [&](int i)
        {
            if(i==n)
            {
                return 1LL; 
            }
            int ans    = 0;
            if(s[i]=='-')
            {
                for(int j = 0;j<a[i];j++)
                {
                    if(vis[j]==0)
                    {
                        vis[j] = 1;
                        a[i+1] = j;
                        ans += cnt(i+1);
                        ans %= MOD;
                        a[i+1] = -1;
                        vis[j] = 0;
                    }
                }
            }
            else if(s[i]=='+')
            {
                for(int  j = a[i]+1;j<n+1;j++)
                {
                    if(vis[j]==0)
                    {
                        vis[j]=1;
                        a[i+1] = j;
                        ans += cnt(i+1);
                        ans %= MOD;
                        vis[j]=0;
                        a[i+1] = -1;
                    }
                }
            }
            return ans;
        };
        int ans = 0;
        for(int  i = 0;i<n+1;i++)
        {
            a[0] = i;
            vis[i] = 1;
            ans += cnt(0);
            ans %= MOD;
            vis[i] = 0;
            a[0] = -1;
        }
        cout<<ans<<endl;
        
   }
   
	// you should actually read the stuff at the bottom
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
    * take input with space ---> std::string s;std::getline(std::cin >> std::ws, s);
*/
return 0;
}
