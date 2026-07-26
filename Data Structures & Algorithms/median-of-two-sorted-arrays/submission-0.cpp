class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for(int it1: nums1){
            res.push_back(it1);
        }

        for(int it2: nums2){
            res.push_back(it2);
        }

        sort(res.begin(), res.end());

        int n= res.size();
        int l= 0;
        int r= n-1;
        double ans = 0;

        if(n%2==0){
            int mid = l + (r-l)/2;
            ans = (double)(res[mid]+res[mid+1])/2;
        }
        else{
            int mid = l + (r-l)/2;
            ans = res[mid];
        }

        return ans;
    }
};
