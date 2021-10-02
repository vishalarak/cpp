
// --------------------------------------------------- Median of Array ---------------------------------------------------
/* 
There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).
The overall run time complexity should be O(log (m+n)).

Sample Input : 
A : [1 4 5]
B : [2 3]

Sample Output : 3           

NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th 
      element. 
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5                                               */


#include <limits.h>                                                                 // for INT_MIN and INT_MAX

float median(int arr1[], int arr2[], int x, int y)
{
  if (x > y)
  {
    return median(arr2, arr1, y, x);
  }
  int low = 0;
  int high = x;
  while(low <= high)
  {
    int partitionX = (low+high)/2;
    int partitionY = (x+y+1)/2 - partitionX;

    int maxLeftX = (partitionX == 0) ? INT_MIN : arr1[partitionX-1];
    int minRightX = (partitionX == x) ? INT_MAX : arr1[partitionX];

    int maxLeftY = (partitionY == 0) ? INT_MIN : arr2[partitionY-1];
    int minRightY = (partitionY == y) ? INT_MAX : arr2[partitionY];

    if ((maxLeftX <= minRightY) && (maxLeftY <= minRightX))
    {
      if ((x + y) % 2 == 0)  {
        return ((max(maxLeftX, maxLeftY)) + min(minRightX, minRightY))/2.0;
      }
      else {
        return max(maxLeftX, maxLeftY);
      }
    }
    
    else if (maxLeftX > minRightY) {
      high = partitionX - 1;
    }

    else {
      low = partitionX + 1;
    }
  }
}

// driver code
int main() {
  int arr1[] = {1,3,5};
  int arr2[] = {2,4,6,8,10};
  int size1 = sizeof(arr1)/sizeof(arr1[0]);
  int size2 = sizeof(arr2)/sizeof(arr2[0]);
  float medianOfTwoArr = median(arr1, arr2, size1, size2);
  cout << "Median of the two arrays is: " << medianOfTwoArr;
  return 0;
}
