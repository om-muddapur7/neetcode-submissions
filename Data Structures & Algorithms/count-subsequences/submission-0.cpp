class Solution {
public:

    int f(int i, int j, string s, string t){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(s[i] == t[j]){
            return f(i-1, j-1, s, t) + f(i-1, j, s, t);
        }

        return f(i-1, j, s, t);
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        return f(m-1, n-1, s, t);
    }
};
