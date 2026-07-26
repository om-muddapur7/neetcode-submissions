class KthLargest {
public:
    int k;
    vector<int> arr;

    KthLargest(int k, vector<int>& nums) {
        this->arr = nums;
        this->k = k;
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(arr.begin(), arr.end());
        return arr[arr.size() - k];
    }
};
