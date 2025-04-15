
/**********************************
Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

*********************/

#include <iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int left=0, right=x/2;
        if (x==0 || x==1) return x; 
        while(left<=right){
            long mid=left+(right-left)/2;
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid < x){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right;
    }
};

int main()
{
    Solution s;
    std::cout<<"Squar root of 4 "<<s.mySqrt(4)<<endl;
    std::cout<<"Squar root of 8 "<<s.mySqrt(8)<<endl;
    std::cout<<"Squar root of 2 "<<s.mySqrt(2)<<endl;

    return 0;
}
