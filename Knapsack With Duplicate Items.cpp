class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> dp(capacity + 1, 0);

        for(int i = 0; i < n; i++){
            for(int w = wt[i]; w <= capacity; w++){
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }

        return dp[capacity];
    }
};