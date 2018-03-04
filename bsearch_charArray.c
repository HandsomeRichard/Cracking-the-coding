#include <stdio.h >
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define ROW 8

int findDataNumber(char input[ROW][SIZE]);
void print2d_charArray(char input[ROW][SIZE]);

int compar(const void *a, const void *b)
{
    return (strcmp((char *)a, (char *)b));
}

// -------------------------------重點:資料必須先sort過---------------------------------------------------------------------
// void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
//               (*key:想要尋找的資料, *base:被搜尋陣列的開頭位置, nitems:陣列的元素數量, size:每一個元素大小,)
//               (compar 函數指標:用來判斷2個元素大小關係，若傳給compar 參數1>參數2回傳大於0的值、參數1=參數2回傳0、)
// =>處理完畢後:若找到回傳該指標位址；找不到回傳null

int main()
{

    //可有0~49(共50筆)筆資料 每一筆都可以塞0~9(共10個)個Char
    char data[ROW][SIZE];
    //init_2d char array
    memset(data, 0, sizeof(data[0][0]) * ROW * SIZE);
    // for (int i = 0; i < 10; i++)
    // {
    //     strcpy(data[i], "Richard");
    // }
    strcpy(data[0], "Richard");
    strcpy(data[1], "ED");
    strcpy(data[2], "Patrick");
    strcpy(data[3], "Danny");
    strcpy(data[4], "Creepy");
    //假設我不知道,我的data裡面到底有多少筆資料 = 上面範例為5筆塞資料!
     //已知或是不知道Array的bound的方法:
    //https://stackoverflow.com/questions/3911400/how-to-pass-2d-array-matrix-in-a-function-in-c
    int number = findDataNumber(data);
    print2d_charArray(data);

    printf("--Sorted Below--");
    //先將資料sort
    //void qsort(void* base, size_t n, size_t size, int (*cmp)(const void*, const void*))
    qsort(data[0] ,number ,SIZE , compar);
    print2d_charArray(data);

    //搜尋Patrick這個資料
    char key[80] = "Patrick";
    char *findResult = (char*)bsearch(key,data[0],number,SIZE,compar);

    if(findResult == NULL){

        printf("Not find\n");

    }else{

        printf("%s\n",findResult);
    }
    // You only free() pointers returned by malloc()/calloc()/realloc(),
    // passing any pointer that was not returned by one of these functions is undefined behavior.
    // free(data);//更本不需要Free
    system("PAUSE");
    return 0;
}

int findDataNumber(char input[ROW][SIZE])
{
    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        if (strlen(input[i]) > 0)
        {
            count++;
        }
    }

    return count;
}

void print2d_charArray(char input[ROW][SIZE])
{
    for (int i = 0; i < ROW; i++)
    {
        printf("input[%d]= %s\n", i, input[i]);
    }
}
