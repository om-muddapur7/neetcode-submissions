class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> vec;
        int fleet = 0;

        for(int i=0; i<speed.size(); i++){
            double time = (double)(target - position[i]) / speed[i];
            vec.push_back({position[i], time});
        }

        sort(vec.begin(), vec.end());

        double curTime = 0;

        for(int j=vec.size()-1; j>=0; j--){
            if(vec[j].second > curTime) {
                fleet++;
                curTime = vec[j].second;
            }
        }

        return fleet;
    }
};
