#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// function to build segment tree
void build(vector<ll>& segtree, vector<ll>& arr, int index, int low, int high) {
    if (low == high) {
        segtree[index] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(segtree, arr, 2 * index + 1, low, mid);
    build(segtree, arr, 2 * index + 2, mid + 1, high);
    segtree[index] = max(segtree[2 * index + 1], segtree[2 * index + 2]);
}

// fnction to find the maximum element in a given range 
ll query(vector<ll>& segtree, int index, int low, int high, int l, int r) {
    if (r < low || l > high) {
        return LLONG_MIN; 
    }
    if (l <= low && high <= r) {
        return segtree[index];
    }
    int mid = low + (high - low) / 2;
    ll leftMax = query(segtree, 2 * index + 1, low, mid, l, r);
    ll rightMax = query(segtree, 2 * index + 2, mid + 1, high, l, r);
    return max(leftMax, rightMax);
}

// update function to update the value at a specific index in the segment tree
void update(vector<ll>& segtree, int index, int low, int high, int pos, ll value) {
    if (low == high) {
        segtree[index] = value;
        return;
    }
    int mid = low + (high - low) / 2;
    if (pos <= mid) {
        update(segtree, 2 * index + 1, low, mid, pos, value);
    } else {
        update(segtree, 2 * index + 2, mid + 1, high, pos, value);
    }
    segtree[index] = max(segtree[2 * index + 1], segtree[2 * index + 2]);
}

// push function with lazy propagation to update the segment tree efficiently
vector<ll> lazy;
void push(vector<ll>& segtree, int index, int low, int high) {
    if (lazy[index] != 0) {
        segtree[index] += lazy[index];
        if (low != high) {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    lazy.resize(4 * n, 0); 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> segtree(4 * n);
    build(segtree, arr, 0, 0, n - 1);   
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(segtree, 0, 0, n - 1, l, r) << endl;
    }
    return 0;
}   