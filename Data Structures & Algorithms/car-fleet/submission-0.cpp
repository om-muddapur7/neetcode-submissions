class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n= position.size();
        vector<pair<int, int>> cars;

        for(int i=0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        vector<double>stack;
        for(auto it: cars){
            stack.push_back((double)(target - it.first)/it.second);
            if(stack.size()>=2 && stack.back()<=stack[stack.size()-2]){
                stack.pop_back();
            }
        }

        return stack.size();

    }
};
