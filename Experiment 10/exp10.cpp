#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<pair<int,int>> v;

void merge(int l, int m, int r){
    vector<pair<int,int>> tmp;
    int i = l, j = m + 1;
    int cnt = 0;

    while(i <= m && j <= r){
        if(v[j].first < v[i].first){
            cnt++;
            tmp.push_back(v[j++]);
        } else {
            ans[v[i].second] += cnt;
            tmp.push_back(v[i++]);
        }
    }

    while(i <= m){
        ans[v[i].second] += cnt;
        tmp.push_back(v[i++]);
    }

    while(j <= r){
        tmp.push_back(v[j++]);
    }

    for(int i = l; i <= r; i++){
        v[i] = tmp[i - l];
    }
}

void mergeSort(int l, int r){
    if(l >= r) return;
    int m = (l + r) / 2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    ans.assign(n, 0);
    v.clear();

    for(int i = 0; i < n; i++){
        v.push_back({nums[i], i});
    }

    mergeSort(0, n - 1);
    return ans;
}

int main(){
    vector<int> nums = {5,2,6,1};

    vector<int> res = countSmaller(nums);

    for(int x : res) cout << x << " ";
}