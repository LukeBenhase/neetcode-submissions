class Solution {
public:
    int maxArea(vector<int>& heights) {
        int bar1 = 0;
        int bar2 = heights.size()-1;
        int maxAmount = 0;
        int amount = 0;
        while (bar1 != bar2){
            // compute the size
            if (heights[bar1] >= heights[bar2]){
                cout << "1: " << amount << " : " << bar1 << " : " << bar2 << " : " << maxAmount << endl;
                amount = heights[bar2] * (bar2 - bar1);
                bar2--;
            }
            else {
                cout << "2: " << amount << " : " << bar1 << " : " << bar2 << " : " << maxAmount << endl;
                amount = heights[bar1] * (bar2 - bar1);
                bar1++;
            }
            if (maxAmount < amount){
                maxAmount = amount;
            }
            
        }
        return maxAmount;
    }
};
