#include <bits/stdc++.h>
using namespace std;

struct pt {
    long long x, y;
};

long long cross(pt a, pt b, pt c) {
    return (b.x - a.x) * (c.y - a.y) -
           (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pt> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i].x >> A[i].y;

    int m;
    cin >> m;

    vector<pt> B(m);
    for (int i = 0; i < m; i++)
        cin >> B[i].x >> B[i].y;

    for (int j = 0; j < m; j++) {
        pt P = B[j];

        // Quick rejection
        if (cross(A[0], A[1], P) >= 0) {
            cout << "NO\n";
            return 0;
        }
        if (cross(A[0], A[n-1], P) <= 0) {
            cout << "NO\n";
            return 0;
        }

        // Binary search sector
        int l = 1, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (cross(A[0], A[mid], P) < 0)
                l = mid;
            else
                r = mid;
        }

        // Final triangle check
        if (cross(A[l], A[l+1], P) >= 0) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}