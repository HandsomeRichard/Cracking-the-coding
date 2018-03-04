#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

int binarySearch(int *array, int arraySize, int target);

int binarySearch_withCondtionFindTarget_backward(int *array, int arraySize, int target);

int main(void)
{
    //binarySearch必須先sort過由小至大 時間複雜度為O(log2^n)
    int arr[10] = {3, 8, 45, 53, 65, 100, 112, 160, 180, 200};
    //找出200該數在第幾個index
    cout << "no condtion case:" << binarySearch(arr, ARRAY_SIZE(arr), 200) << endl;

    // 數列裡有重複的數字，而且條件變更成：
    // 衍生不同條件: 回傳「第一個」出現的位置
    // ex :
    // 回傳第一個 >=target 的位置
    // 回傳第一個 >target 的位置
    // 回傳最後一個 <=target 的位置
    // 回傳最後一個 <target 的位置
    //以:傳回最後一個 < target 的數
    int arr2[15] = {1, 2, 2, 2, 2, 2, 3, 3,4,4,4,4,17,18,19};
    cout << "with condition case:" << binarySearch_withCondtionFindTarget_backward(arr2, ARRAY_SIZE(arr2), 4);

    system("PAUSE");
    return 0;
}
int binarySearch_withCondtionFindTarget_backward(int *array, int arraySize, int target)
{
    //先將[L,R]壓縮區間剩餘二個，剩下的用線性搜索法找出答案
    //{1, 2, 2, 2, 2, 2, 3, 3}
    //傳回最後一個 < target 的數
    //若須改條件,則改時間複雜度為線性的條件即可!
    int R = arraySize - 1;
    int L = 0;

    //找不出!
    if (array[0] >= target)
        return -1;
    //結束條件在二個數以下時候
    while ((R - L + 1) > 2)
    {
        int M = (R + L) / 2;

        if (array[M] >= target)
        {
            R = M - 1;
        }
        else if (array[M] < target)
        {
            L = M;
        }
    }

    for (int i = R; i >= L; i--)
    {
        if (array[i] < target)
        {
            return i;
        }
    }
}

int binarySearch(int *inputArr, int arraySize, int target)
{

    //C語言的array lenhth = sizeof(array)/ sizeof(array[0]);

    // find Left & right bound
    /* 問題回答連結: https://stackoverflow.com/questions/4162923/calculate-length-of-array-in-c-by-using-function  */
    // 最常犯的錯，因為inputArr指到aray第一個值的位置!故 int R = 1;
    // 解決方式 1.將array size先求出在function使用參數帶入；  2.定義marco函數ARRAY_SIZE

    int R = arraySize - 1;
    int L = 0;

    while (L <= R) //代表 L>R 停止迴圈
    {

        int M = (R + L) / 2;

        if (inputArr[M] == target)
        {
            return M;
            break;
        }
        else if (inputArr[M] > target)
        {
            R = M - 1;
        }
        else if (inputArr[M] < target)
        {
            L = M + 1;
        }
    }

    return -1;
}