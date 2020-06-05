/*
    Problem:

    Write a function that reverses a string. The input string is given as an array of characters char[].

    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

    You may assume all the characters consist of printable ascii characters.

    Example 1:

    Input: ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]


    Author: Mackenzie Josie
    Date: June 4, 2020
*/


void reverseString(char* s, int sSize){
    int i = 0, j = sSize - 1, temp;
    
    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}
