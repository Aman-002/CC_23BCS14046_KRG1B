#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll = long long;
    int nthMagicalNumber(int n, int a, int b) {
        ll mod = 1e9+7;
        ll g = __gcd(a,b);
        ll lcm = (1LL*a*b)/g;
        ll l = min(a,b);
        ll r = (1LL*l*n);
        while(l <= r){
            ll m = l + (r-l)/2;
            ll ac = m/a;
            ll bc = m/b;
            ll lc = m/lcm;
            ll cnt =  ac + bc - lc;
            if(cnt<n){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return l%mod;
    }
};