/*  Questions: Add to Array Form of Integer
    Source: https://leetcode.com/problems/add-to-array-form-of-integer

    CODE:                                                                         */

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        string str = to_string(k);
        vector<int>arr;
        for(int i = 0;i < str.size();i++){
            arr.push_back(str[i] - '0');
        }
        int p1 = num.size()-1,p2 = arr.size()-1;
        vector<int>ans;
        while(p1 >= 0 && p2 >= 0){
            if(arr[p2] + num[p1] + carry >= 10){
                ans.push_back(num[p1] + arr[p2] + carry - 10);
                carry = 1;
            }    
            else{
                ans.push_back(carry + num[p1] + arr[p2]);
                carry = 0;
            }
            p1--;
            p2--;
        }
        if(p1 >= 0){
            while(p1 >= 0){
                if(carry + num[p1] >= 10){
                    ans.push_back(carry + num[p1] - 10);
                    carry = 1;
                }
                else{
                    ans.push_back(carry + num[p1] );
                    carry = 0;
                }
                p1--;
            }
        }
        if(p2 >= 0){
            while(p2 >= 0){
                if(carry + arr[p2] >= 10){
                    ans.push_back(carry + arr[p2] - 10);
                    carry = 1;
                }
                else{
                    ans.push_back(carry + arr[p2]);
                    carry = 0;
                }
                p2--;
            }
        }
        if(carry == 1){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
