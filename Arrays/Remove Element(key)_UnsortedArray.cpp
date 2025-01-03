/*
Remove Element(  Topics : two pointers  )


Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/

/*
Approach
To achieve this, we use a two-pointer technique:

One pointer (i) iterates through the array.
Another pointer (j) keeps track of the position where the next valid element (not equal to val) should be placed.
When nums[i] != val, assign nums[j] = nums[i] and increment j.
At the end, j represents the count of elements that are not equal to val.

*/

#include <iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:

	int removeElement(vector<int>& nums, int val) {
		int i=0,j=0;
		for(j=0; j<nums.size(); j++)
		{
			if(nums[j]!=val)
			{
				nums[i++]=nums[j];
			}
		}
		return i;
	}
};

int main() {
	std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
	int val = 2;
	Solution s;
	cout<<"Initial values :"<<endl;
	for (int i = 0; i < nums.size(); ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
	int k = s.removeElement(nums, val);

	std::cout << "The Element to be removed = " << val<< std::endl;
	std::cout << "Modified array: ";
	for (int i = 0; i < k; ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
