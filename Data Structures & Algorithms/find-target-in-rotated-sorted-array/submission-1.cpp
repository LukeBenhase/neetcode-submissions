class Solution {
public:
    int search(vector<int>& nums, int target) {
        int m, l = 0;
        int r = nums.size()-1;
        while( l != r){
            m = (r-l)/2+l; // no overflow ever
            if(nums[m] > nums[r]){
                // you know that the numbers larger than m and smaller than r are within
                if ( nums[m] == target){
                    return m;
                }
                else if (nums[m] > target && target > nums[r]){// wrong side of list
                    r = m;
                }
                else{
                    l = m+1;
                }
            }
            else{
                // you know that numbers are in sorted order between m and r
                if ( nums[m] == target){
                    return m;
                }
                else if (nums[m] < target && target <= nums[r]){
                    l = m+1;
                }
                else{
                    r = m;
                }
            }
        }
        if (nums[l] == target)
            return l;
        return -1;
    }
};
