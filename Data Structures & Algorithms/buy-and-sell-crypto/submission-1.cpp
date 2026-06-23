class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int l = 0;

        for (int r = 1; r < prices.size(); r++){
            if (max < (prices[r] - prices[l]))
                max = prices[r] - prices[l];
            if (prices[r] < prices[l])
                l = r;
            //cout << l << ":" << r << ":" << max << endl;
        }
        return max;
    }
};
