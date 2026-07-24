class Solution {
public:
    int trap(vector<int>& height) {
        int output = 0;
        for (int i = 1; i < height.size(); i ++){
            // look left and right to see if you are in a container. 
            int highestLeft = 0;
            int highestRight = 0;
            for (int j = i; j >= 0; j--){
                if (height[j] > highestLeft){
                    highestLeft = height[j]; 
                }
            }
            for (int j = i; j < height.size(); j++){
                if (height[j] > highestRight){
                    highestRight = height[j]; 
                }
            }
            // find the lowest of the heightest and if it is larger 
            //  than height of self there is water above
            if (min(highestLeft, highestRight) > height[i]){
                // add the amount of water above
                output += min(highestLeft, highestRight) - height[i];
            }
        }
        return output;
    }
};
