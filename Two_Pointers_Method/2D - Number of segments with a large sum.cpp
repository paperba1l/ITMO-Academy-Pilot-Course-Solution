/**
 *  @author:      paperba1l
 *  @year:        2022
**/
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define vi vector<int>
#define pii pair<int, int>
#define all(vec) vec.begin(), vec.end()
#define ischar(ch) (ch >= 'a' && ch <= 'z')
#define isChar(ch) (ch >= 'A' && ch <= 'Z')
#define fill(vec, x) memset(vec, x, sizeof(vec))
#define boostio                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
// Input macros
#define si(n) scanf("%d", &n)
#define sc(n) scanf("%c", &n)
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)

typedef long long int ll;
typedef unsigned long long ull;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979;
inline int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

const ll mod = 1e9 + 7;
const ll maxn = 5000;

int main()
{
    boostio;
    int tcs = 1;

    //cin>>tcs;
    while (tcs--){
        ll n, m;
        cin>>n>>m;
  
        vector<ll> a = vector<ll>(n);
        ll sm = 0;
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        
        
        ll ans = 0;
        sm = 0;
        ll r = 0, l = 0;
        while(r < n) {
            sm += a[r];
            
            while(sm-a[l] >= m) {
                sm -= a[l];
                l++;
            }
            
            if(sm >= m)
                ans += (l+1);
            r++;
        }
    
        cout<<ans<<endl;
    }

    return 0;
}

//int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month
