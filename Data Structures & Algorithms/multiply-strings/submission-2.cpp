class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1 == "0" || num2 == "0") return "0";

        long long n1 = 0;
        for(int i=0; i<num1.size(); i++){
            int dig = num1[i] - '0';
            n1 = n1*10 + dig;
        }

        long long n2 = 0;
        for(int i=0; i<num2.size(); i++){
            int dig = num2[i] - '0';
            n2 = n2*10 + dig;
        }

        n1 = n1 * n2;
        string res;

        while(n1 != 0){
            int dig = n1 % 10;
            res.push_back(dig + '0');
            n1 /= 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
