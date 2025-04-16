/*
  42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

  Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 
Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

###########prefix max arrays method (normal approach):#####################################
✅ Step-by-Step Approach(:
1. Initialize Variables
Let n = height.size()
If n <= 2, return 0 (no room to trap water)

2. Create Two Vectors
left_max[n]: stores the max height to the left of each index (including current)
right_max[n]: stores the max height to the right of each index (including current)

3. Fill left_max Array
Set left_max[0] = height[0]
Traverse from i = 1 to n - 1
left_max[i] = max(left_max[i-1], height[i])

4. Fill right_max Array
Set right_max[n-1] = height[n-1]
Traverse from i = n-2 to 0
right_max[i] = max(right_max[i+1], height[i])

5. Calculate Trapped Water
Initialize water = 0
Traverse from i = 0 to n - 1
water += min(left_max[i], right_max[i]) - height[i]

6. Return Result


*/
class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        vector<int> left;
        left.assign(size,0);
        vector<int> right;
        right.assign(size,0);
        int result=0;
        left[0]=height[0];
        for(int i=1;i<size;i++)
        {
            left[i]=max(left[i-1],height[i]);
        }
        right[size-1]=height[size-1];
        for(int i=size-2;i>=0;i--)
        {
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=0;i<size;i++)
        {
            result+=min(left[i],right[i])-height[i];
        }
    return result;    
    }
};

/*
#################OPTIMAL APPROACH############################
✅ Efficient Code (Two-pointer approach)
Time: O(n)
Space: O(1)
✅ Explanation (Step-by-Step):
Start with two pointers: one at the beginning (left), one at the end (right)

Keep track of the highest walls seen from both ends

Water trapped at a position = height of shorter wall − current height
*/
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0, water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : water += (left_max - height[left]);
            ++left;
        } else {
            height[right] >= right_max ? (right_max = height[right]) : water += (right_max - height[right]);
            --right;
        }
    }
    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Total trapped water: " << trap(height) << endl;  // Output: 6
    return 0;
}

