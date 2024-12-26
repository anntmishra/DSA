//217. Contains Duplicate

/* Given an integer array nums, 
return true if any value appears at least twice in the array,
 and return false if every element is distinct */


/*
nums is our array 

set in c++,removes the duplicate elements present in an array

nums->set
set->unique element 

nums==set
return false
else return true
*/


#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution{
    public:
    bool cd(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int x = nums.size();
        int y = s.size();
        if (x == y) {
            return false;
        } else {
            return true;
        }
    }

    };

    int main() {
        Solution solution;
        vector<int> nums = {1, 2, 3, 1};
        bool result = solution.cd(nums);
        cout << (result ? "true" : "false") << endl;
        return 0;
    }
