#include<bits/stdc++.h>
using namespace std;
int main() {
int t, k, m;

scanf("%d", &t);
while(t--) {
    scanf("%d%d", &k, &m);

    vector<vector<int> > a(m, vector<int> (2,0));
    vector<vector<int> > dp(m + 1, vector<int> (k,0));

    for(int i = 0; i < m ; ++i ){
        scanf("%d%d", &a[i][0],&a[i][1]);
    }
    for(int i = 0; i <= m ; ++i) {
        for(int j = 0; j <= k; ++j) {
            if(i == 0 || j == 0){
            	dp[i][j] = 0;
            }
            else if(a[i-1][0] <= j){
            	dp[i][j] = max(dp[i-1][j - a[i-1][0]] + a[i-1][1] , dp[i-1][j]);
            }
            else {
            	dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("Hey stupid robber, you can get %d.\n", dp[m][k]);
 }

return 0;
}
