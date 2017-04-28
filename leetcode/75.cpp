/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.
*/

#define RED 0
#define WHITE 1
#define BLUE 2

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int countRed = 0;
    int countWhite = 0;
    int countBlue = 0;
    for (int num : nums) {
      switch (num) {
        case RED:
          ++countRed;
          break;
        case WHITE:
          ++countWhite;
          break;
        case BLUE:
          ++countBlue;
          break;
        default: {}
      }
    }
    for (int i = 0; i < countRed; ++i)
      nums[i] = RED;
    for (int i = countRed; i < countRed+countWhite; ++i)
      nums[i] = WHITE;
    for (int i = countRed+countWhite; i < countRed+countWhite+countBlue; ++i)
      nums[i] = BLUE;
  }
};