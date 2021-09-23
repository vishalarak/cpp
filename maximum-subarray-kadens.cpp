// ------------------------------------------- Maximum Subarray -------------------------------------------
/* 
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the 
largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6. */

// ---------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;

int maxsubarray(int a[], int size) {
    int max_so_far =  a[0];
    int curr_max = a[0];

    for (int i = 1; i < size; i++) {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxsubarray(a, n);
   cout << "Maximum contiguous sum is " << max_sum;
   return 0;
}

// ---------------------------------------------------------------------------------------------------------

// $ ./maximum-subarray-kadens.exe 
// Maximum contiguous sum is 7