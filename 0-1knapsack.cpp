class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<int> dp(W + 1, 0);
        int n = val.size();
        
        for(int i = 0; i < n; i++){
            for(int w = W; w >= wt[i]; w--){
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
        
        return dp[W];
    }
};