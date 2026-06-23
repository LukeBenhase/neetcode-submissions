class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<pair<string, string>> sortedAnagrams;

        for (string str : strs){
            string strSorted = str;
            sort(strSorted.begin(), strSorted.end());
            sortedAnagrams.push_back(pair<string,string> { strSorted , str});
        }

        sort(sortedAnagrams.begin(), sortedAnagrams.end());
        vector<vector<string>> outVector;
        int startOfGroup = 0;
        for (int i = 1; i <= sortedAnagrams.size(); i++){
            if (i < sortedAnagrams.size() && sortedAnagrams[i].first == sortedAnagrams[i-1].first){
                continue;
            }
                
            vector<string> addToOutVector;
            for (int j = startOfGroup ; j < i; j ++){
                addToOutVector.push_back(sortedAnagrams[j].second);   
            }
            outVector.push_back(addToOutVector);
            startOfGroup = i;
        }
        return outVector;


        /*
        sort each string into a sorted string and original string
        
        sort the vector of sorted strings

        loop through the sorted sorted strings compairing the 
         string n+1 if it is the same they are part of the same output group
        */
    }
};