#include <stdio.h >
#include <stdlib.h>
#include <string.h>


// @2017.12.14 
int cmpfunc(const void *a, const void *b)
{
  //超神寫法...
  return (*(int *)a - *(int *)b);
}

int values[] = {5, 20, 29, 32, 63};


// -------------------------------重點:資料必須先sort過---------------------------------------------------------------------
// void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
//               (*key:想要尋找的資料, *base:被搜尋陣列的開頭位置, nitems:陣列的元素數量, size:每一個元素大小,)
//               (compar 函數指標:用來判斷2個元素大小關係，若傳給compar 參數1>參數2回傳大於0的值、參數1=參數2回傳0、)
// =>處理完畢後:若找到回傳該指標位址；找不到回傳null              

int main()
{
  int *item;
  int key = 32;
  
  /* using bsearch() to find value 32 in the array */
  item = (int *)bsearch(&key, values, 5, sizeof(int), cmpfunc);
  if (item != NULL)
  {
    printf("Found item = %d", *item);
  }
  else
  {
    printf("Item = %d could not be found", *item);
  }

  system("PAUSE");
  return 0;
}