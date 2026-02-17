#include <bits/stdc++.h>
using namespace std;
long long sumAndPairs(vector<int>& a) {
    long long ans = 0;
    int n = a.size();

    for(int b = 0; b < 32; b++){
        long long cnt = 0;
        for(int x : a){
            if(x & (1 << b)) cnt++;
        }
        ans += (cnt * (cnt + 1) / 2) * (1LL << b);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << sumAndPairs(a) << endl;
    return 0;
}
