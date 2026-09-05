class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int min = 100;

        for (int price : prices){
            if (price < min){
                min = price;
            }
            // calculate if this profit is bigger than max profit
            int profit = price - min;
            if (profit > maxProfit)
                maxProfit = profit;
        }

        return maxProfit;
    }
};
