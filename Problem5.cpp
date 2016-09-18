#include<bits/stdc++.h>
using namespace std;

// int solve (vector<int> &a , int n, int w, int *cnt, int *ans) { //printf("*");
//     if(w - a[n-1] == 0 && *ans > *cnt ) {
//     	*ans = *cnt;
//         ++(*cnt);
//         return true;
//     }
//     if(w - a[n-1] < 0 ) {
//         return false;
//     }
//     int new_cnt = *cnt + 1;
//     return solve(a, n-1 , w - a[n-1], &new_cnt ,ans) || solve(a, n-1, w, cnt, ans);
// }

int main() {
    int t;
    int n,W;
    unsigned int max_val = 42949999;
    scanf("%d", &t);
    while(t--) {
	    scanf("%d%d",&n,&W);
	    vector<int> a(n,0);
	    vector<vector<unsigned int> > dp(n + 1, vector<unsigned int> (W+1,0));
	    for(int i = 0; i < n; ++i) {
	        scanf("%d", &a[i]);
	    }
		for(int i = 1; i <= n; ++i) {
			for(int w = 0; w <= W; ++w) {
				if(w >= a[i-1] && (dp[i-1][w-a[i-1]] || w - a[i-1] == 0)) {
					dp[i][w] = min(dp[i][w-a[i-1]] + 1, dp[i-1][w] ? dp[i-1][w] : max_val );
				//	printf("(i:%d w:%d a:%d dp:%d) ",i , w, a[i-1], dp[i][w]);
				} else {
					dp[i][w] = dp[i-1][w];
				}
			}
			//printf("%d ", a[i-1]);
		//	printf("\n");
		}
		if(dp[n][W]) {
			printf("%d\n", dp[n][W]);
		} else {
			printf("impossible\n");
		}
    }
    return 0;
}
