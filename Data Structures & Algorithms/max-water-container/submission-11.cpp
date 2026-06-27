class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int max = 0;

        while (i < j){
            // 1.
            int tempMax = min(heights[i], heights[j]) * (j-i);
            // 2.
            if (max < tempMax) max = tempMax;
            // 3.
            if (heights[i] > heights[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return max;

        /*
        1. calculate the volume from the two outer bars by finding the distance between 
        and the shorter bar. 
        2. then save it as the largest amount if it is the largest amount of water 
        that can be stored. 
        3. then move in the shorter bar and recalculate, if they 
        are same just move in the left side. 
        */
    }
};
