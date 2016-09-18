#include<bits/stdc++.h>
using namespace std;

int function solve (vector<int> a , int n, int w, int *cnt) {
    if(w - a[n-1] == 0) {
        ++(*cnt);
        return true;
    }
    if(w - a[n-1] < 0 ) {
        return false;
    }
    int new_cnt = *cnt + 1;
    return solve(a, n-1 , w - a[n-1], new_cnt) || solve(a, n-1, w, cnt);
}

int main() {
    int t;
    int n,w;
    while(t--) {
        scanf("%d%d",&n,&w);
        vector<int> a(n,0);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
    int cnt = 0;
    int ans = solve(&a, n , w, &cnt);
    if(ans) {
        printf("%d", cnt);
    }
    }
}
