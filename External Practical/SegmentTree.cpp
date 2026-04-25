#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void build(vector<ll>& segsum,vector<ll>& segmax,vector<ll>& segmin, vector<ll>& arr, int index, int low, int high) {
    if (low == high) {
        segsum[index] = arr[low];
        segmax[index] = arr[low];
        segmin[index] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(segsum,segmax,segmin, arr, 2 * index + 1, low, mid);
    build(segsum,segmax,segmin, arr, 2 * index + 2, mid + 1, high);
    segsum[index] = (segsum[2*index + 1] + segsum[2*index+2]);
    segmax[index] = max(segmax[2 * index + 1], segmax[2 * index + 2]);
    segmin[index] = min(segmin[2 * index + 1], segmin[2 * index + 2]);
}

ll queryMax(vector<ll>& segtree, int index, int low, int high, int l, int r) {
    if (r < low || l > high) {
        return LLONG_MIN; 
    }
    if (l <= low && high <= r) {
        return segtree[index];
    }
    int mid = low + (high - low) / 2;
    ll leftMax = queryMax(segtree, 2 * index + 1, low, mid, l, r);
    ll rightMax = queryMax(segtree, 2 * index + 2, mid + 1, high, l, r);
    return max(leftMax, rightMax);
}

ll queryMin(vector<ll>& segtree, int index, int low, int high, int l, int r) {
    if (r < low || l > high) {
        return LLONG_MAX; 
    }
    if (l <= low && high <= r) {
        return segtree[index];
    }
    int mid = low + (high - low) / 2;
    ll leftMin = queryMin(segtree, 2 * index + 1, low, mid, l, r);
    ll rightMin = queryMin(segtree, 2 * index + 2, mid + 1, high, l, r);
    return min(leftMin, rightMin);
}

ll querySum(vector<ll>& segtree, int index, int low, int high, int l, int r) {
    if (r < low || l > high) {
        return 0; 
    }
    if (l <= low && high <= r) {
        return segtree[index];
    }
    int mid = low + (high - low) / 2;
    ll left = querySum(segtree, 2 * index + 1, low, mid, l, r);
    ll right = querySum(segtree, 2 * index + 2, mid + 1, high, l, r);
    return (left + right);
}


int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> segsum(4 * n);
    vector<ll> segmax(4 * n);
    vector<ll> segmin(4 * n);
    build(segsum,segmax,segmin, arr, 0, 0, n - 1);   
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << querySum(segsum, 0, 0, n - 1, l, r) << endl;
        cout << queryMax(segmax, 0, 0, n - 1, l, r) << endl;
        cout << queryMin(segmin, 0, 0, n - 1, l, r) << endl;
    }
    return 0;
}   