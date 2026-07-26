class Solution {
public:
    bool isPalindrome(string s) {

        if(s=="") return true;

        int st=0;
        int end = s.size()-1;

        while(st<=end){
            if(isalnum(s[st]) && isalnum(s[end])){
                if(tolower(s[st])==tolower(s[end])){
                    st++;
                    end--;
                }
                else{
                    return false;
                }
            }
            else if(isalnum(s[st]) && !isalnum(s[end])){
                end--;
            }
            else if(!isalnum(s[st]) && isalnum(s[end])){
                st++;
            }
            else{
                st++;
                end--;
            }
        }
        return true;
    }
};
