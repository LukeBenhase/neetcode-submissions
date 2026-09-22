class MinStack {
    vector<int> data;
    vector<int> smallest;
    int topPlace = 0;
public:
    MinStack() {
        
        //int size = 16;
    }
    
    void push(int val) {
        data.push_back(val);
        if (topPlace == 0 || smallest[topPlace-1] > val){
            // this is the smallest
            smallest.push_back(val);
        }
        else {
            smallest.push_back(smallest[topPlace-1]);
        }
        topPlace++;
       
    }
    
    void pop() {
        data.pop_back();
        smallest.pop_back();
        topPlace--;
    }
    
    int top() {
        if (topPlace == 0){
            cout << "There is to top element" << endl;
            return 0;
        }
        return data[topPlace-1];
    }
    
    int getMin() {
        if (topPlace == 0){
            cout << "There is no smallest element" << endl;
            return 0;
        }
        return smallest[topPlace-1];
    }
};
