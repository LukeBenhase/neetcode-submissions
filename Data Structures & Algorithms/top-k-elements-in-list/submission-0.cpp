class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> keyValueMap;
        vector <vector<int>> outputList((nums.size()+1), vector<int> (0));
        vector <int> output;

        for (int i : nums){ // 1.
            if (keyValueMap.contains(i)){
                keyValueMap[i] = keyValueMap[i] + 1;
            }
            else{
                keyValueMap[i] = 1;
            }
        }

        for (auto i : keyValueMap){ // 2.
            outputList[i.second].push_back(i.first);
        }

        int i = nums.size();
        while (k > 0 && i >= 0){ // 3. 
            if (outputList[i].empty()){
                i--;
            }
            else {
                output.push_back(outputList[i].back());
                outputList[i].pop_back();
                k--;
            }
        }
        

        return output;
        /*  
        1. store all nums into a map with the key being the number and the 
        value being the number of occurences
        2. loop through the dictionary placing the key number a the postion of the 
        value number in a list
        3. loop through the list backwards looking for elements adding them to the
         ouput until you find k elements. 
        */
    }
};
