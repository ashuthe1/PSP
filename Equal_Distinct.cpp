// Ashutosh Gautam :)
#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k; || Make less_equal for multiset

#define FastandFurious ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long int
#define deb(x) cout << #x << "=" << x << "\n";
#define deb2(x,y) cout << #x << "=" << x << "," << #y << "=" << y << "\n";
const int N = 2e5+1;
const int mod = 1e9+7;
#define INF 1e18+9

// For laziness XD
vector<int>g[N],level(N);
vector<bool> is_prime(N+1, true),vis(N,false);
bool powerof2 (int x);
int totalDigits(int n);
long long power(long long a, long long b, long long m);
void primeseive();
void dfs(int vertex);
void bfs(int source);

//-------------------#Maincode starts!----------------//

void MainCode()
{
    int n,c = 0,op = 0,xorr = 0;
    cin >> n;

    vector<int>v(n);
    map<int,int>m;
    set<int>s;
    for(auto &x : v) 
    {
        cin >> x; 
        m[x]++;
        s.insert(x);
    }
    
    for(auto it = m.begin(); it != m.end(); it++)
    {
        int freq = it->second;
        if(freq == 1) c++;
        else op++;
    }
    bool ok = 1;

    if(n&1)
    {
        if(n-s.size() == 0) ok = 0;
    }
    if(ok)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    // if( ((op+c)%2) && (c%2))
    // {
    //     cout << "NO\n";
    //     return;
    // }
    // cout << "YES\n";
}

//------------------#Maincode ends!---------------//
signed main()
{
    FastandFurious
    int TestCaseS = 1;
    cin >> TestCaseS; 

    // primeseive();
    for(int TestCase = 1; TestCase <= TestCaseS ; TestCase++)
    {
        // cout << "Case #" << TestCase << ": "; // Google!
        MainCode();
    }
    return 0;
}

// Functions :

bool powerof2 (int x){ 
    // It will also consider 1 as a power of 2
return x&& (!(x&(x-1)));
}
int totalDigits(int n)
{
    if(n == 0) return 1; 
    return floor(log10(n))+1; 
}
long long power(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void primeseive()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (long long)i * i <= N) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}
void dfs(int vertex)
{
    /* Take action on vertwx after
     entering the vertex
    */
    vis[vertex] = true;
    
    for(int child : g[vertex])
    {
        /* Take action on child before
        entering the child node */

        if(vis[child]) continue;

        dfs(child);

        /* Take action on child after
        exiting the child node */   
    }
    /* Take action on vertex
    before exiting the vertex */
}
void bfs(int source)
{
    queue < int > q;
    q.push(source);
    vis[source] = 1;

    while (!q.empty())
    {
        int curr_v = q.front();
        q.pop();

        for(int child : g[curr_v]){

            if(!vis[curr_v]){

                q.push(child);
                vis[child] = 1;
                level[child] = level[curr_v]+1;

            }
        }
    } 
}