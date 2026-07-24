class Solution {
public:
    int trap(vector<int>& height) {
        int output = 0;
        vector<int> heightLeft;
        vector<int> heightRight;

        int highestLeft = 0;
        int highestRight = 0;

        for (int i = 0; i < height.size(); i ++){
            // loop though adding the heighest left to the list
            if (height[i] > highestLeft){
                highestLeft = height[i]; 
            }
            // add item to the left height vector
            heightLeft.push_back(highestLeft);
        }
        // do the same for the right
        for (int i = height.size()-1; i >= 0; i --){
            // loop though adding the heighest left to the list
            if (height[i] > highestRight){
                highestRight = height[i]; 
            }
            // add item to the left height vector
            heightRight.push_back(highestRight);
        }
        for (int i = 0 ; i < height.size(); i ++){
            if (min(heightLeft[i], heightRight[height.size()-1-i]) > height[i]){
                // if above is true there is water above. calculate how much
                output += min(heightLeft[i], heightRight[height.size()-1-i]) - height[i];
            }
        }

        return output;
        /* brute force
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
*/
    }
};
