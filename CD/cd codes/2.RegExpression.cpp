#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter C++ code: (Type 'exit' to stop)" << endl;
    while (true)
    {
        string line;
        cout << "> ";
        getline(cin, line);
        if (line == "exit")
            break;
        regex declarationRegex("int\\s+\\w+\\s*;int\\s+\\w+\\s*\\(.\\)\\s;");
        if (regex_match(line, declarationRegex) && line.find("return") == string::npos &&
            line.find("using namespace") == string::npos)
        {
            cout << "It is a declarative Statement" << endl;
        }
        else
        {
            cout << "It is not a declarative Statement" << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define double long double
#define MOD 1000000007
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define endl "\n"
#define pb push_back
#define dplay(x) cout<<x<<endl;
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.first << " " << x.second << endl
#define fo(i, a, b) for (int i = a; i < b; i++)
#define fov(i, a, b) for (int i = a; i >= b; i--)
#define MOD2 998244353
#define sort(a) sort(a.begin(),a.end())
#define revsort(a) sort(a.rbegin(),a.rend())
// Maths Functions
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
int lcm(int a, int b){return (a/gcd(a,b)*b);}
// string str;
//         str = bitset<32>(3).to_string();     // converts int to binary string;
//         cout<<str;
#define set_bits(x) __builtin_popcount(x) // count no of 1 in binary representation

using namespace __gnu_pbds;
using namespace std;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

 inline int power(int po1, int po2)
{
    int po3 = 1;
    while (po2)
    {
        if (po2 & 1) po3 *= po1;
        po1 *= po1;
        po2 >>= 1;
    }
    return po3;
}
int power2(int a, int b, int m) {
    if(b==0) {
        return 1;
    }
    if(b%2 == 0) {
         int t = power2(a, (b/2), m);
        return (1ll*t*t)%m;
    }
    else {
         int t = power2(a, (b-1)/2, m);
        t = (1ll*t*t)%m;
        return (1ll*a*t)%m;
    }
}
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cerr.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int binaryToDecimal(int n)
{
    int num = n;int dec_value = 0;int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}
int decToBinary(int n)
{
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
    return n;
}
unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
    x = x % p; // Update x if it is more than or  // equal to p
    while (y > 0)
    {        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
         // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;    // Fill factorial array so that we// can find all factorial of r, n// and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
int  bs_sqrt(int  x) {
  int left = 0, right = 2000000123;
  while (right > left) {
      int mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}
const int N = 2e5 + 5, inf = INT64_MAX, mod = 1e9 + 7;
 
vector<int> parent(N);
vector<int> sz(N);

int findset(int u){
    if(parent[u] == u) return u;
    parent[u] = findset(parent[u]);
    return parent[u];
}
 
void unionset(int u, int v){
    int x = findset(u), y = findset(v);
    if(x == y) return;
    if(sz[x] >= sz[y]){
        parent[y] = x;
        sz[x] += sz[y];
    }
    else{
        parent[x] = y;
        sz[y] += sz[x];
    }
}
   
vector<int> primeFactors(int n) {
 vector<int> pf;
    if(n%2 == 0) pf.push_back(2);
    while (n % 2 == 0) {
        n = n/2;
    }
    for (int i = 3; i <= sqrtl(n); i = i + 2) {
        if(n%i == 0) pf.push_back(i);
        while (n % i == 0) {
            n = n/i;
        }
    }
 
    if (n > 2) pf.push_back(n);
 
    return pf ;
}
vector<int> printDivisors(int n) {
    vector<int>div;
    for (int i=1; i<=sqrtl(n); i++) {
        if (n%i == 0) {
            if (n == i*i)
                div.push_back(i);
  
            else {
                div.push_back(i);
                div.push_back((n/i));
            }
        }
    }

    return div;
}

vector<int> Sieve(int n) {
    vector<int> prime(n+1, 1);
    prime[0] = 0;
    prime[1] = 0;
 
    for(int p = 2; p * p <= n; p++)
     {
        if(prime[p] == 1) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }
 
    vector<int> prm;
 
    for (int p = 2; p <= n; p++)
        if (prime[p])
            prm.push_back(p);
 
    return prm;
}
int allFloor(int a, int b) {
    int val = a / b;
    while (val * b > a)
        val--;
    return val;
}
  int t,n,tc,sizey;
void Dipankar()
{
   
   string s;
   cin>>s;
   int sizey=s.size();
   
 cin>>n;
 vector<int>a(n);
 for(int i=0;i<n;i++)
 {
     cin>>a[i];
 }
  
 
 
 
   
       
}
int32_t main() {
    // your code goes here Dipankar ka code
    fast
     clock_t z = clock();
     t=1;
    cin>>t;
    for( tc=1;tc<=t;tc++)
    {
        Dipankar();
       
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}


