class Solution {
public:
    int findMin(vector<int> &nums) {
        int m, l = 0;
        int r = nums.size()-1;
        while (l != r){
            // check left or right bigger
            m = (r-l)/2+l; // this can't overflow
            if (nums[m] > nums[r]){ // the smallest is between them move left up. only works because the numbers are always ascending 
                l = m+1;
            }
            else{
                r = m;
            }
        }
        return nums[l];
    }
};
/*
s r
l r
/ / throw out middle

b s
l r 
/ / throw out not middle

*/