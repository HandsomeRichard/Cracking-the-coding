
#include "HashTable.h"

// 假設有 nums = [2, 7, 11, 15], target = 9，
// 因為 nums[0] + nums[1] = 2 + 7 = 9，
// 回傳 [0, 1]。

//http://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/

int hashCode(char *key)
{

    //Hashcode 可以亂改 table分布
    int index = 0;
    //針對char array可以用strlen算長度!!
    int len = strlen(key);

    for (int i = 0; i < strlen(key); i++)
    {
        printf("%c = %d\n", key[i], (int)key[i]);
        index = index + (int)key[i];

        //index  = ( index +  (int)key[i] ) *10;
        //printf("index = %d\n", index);
    }

    //printf("hashcode = %d\n", index);

    return (index % TABLE_SIZE);
}

void Init_HashTable(struct item inputTable[TABLE_SIZE])
{

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        inputTable[i].name = "empty";
        inputTable[i].drink = "empty";
        inputTable[i].next = NULL;
    }
}

void AddItem(struct item inputTable[], char *name, char *drink)
{
    //以Key name 作為hashcode
    int index = hashCode(name);

    if (inputTable[index].name == "empty")
    {

        inputTable[index].name = name;
        inputTable[index].drink = drink;
    }
    else
    {

        //add another item
        struct item *ptr = &inputTable[index];
        struct item *newitem = (struct item *)malloc(sizeof(struct item));
        newitem->name = name;
        newitem->drink = drink;
        newitem->next = NULL;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newitem;
    }
}

int NumberOfItemsInIndex(struct item inputTable[], int index)
{

    int count = 0;

    if (inputTable[index].name == "empty")
    {

        //這個array index沒有
        return count;
    }
    else
    {

        count++;
        struct item *ptr = &inputTable[index];
        while (ptr->next != NULL)
        {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void printTable(struct item inputTable[])
{

    int number;

    for (int i = 0; i < TABLE_SIZE; i++)
    {

        number = NumberOfItemsInIndex(inputTable, i);
        printf("-----------------\n");
        printf("index = %d\n", i);
        printf("%s\n", inputTable[i].name);
        printf("%s\n", inputTable[i].drink);
        printf("# of numbers = %d\n", number);
        printf("-----------------\n");
    }
}

void printItemIndex(struct item inputTable[], int index)
{

    struct item *ptr = &inputTable[index];

    if (ptr->name == "empty")
    {

        printf("index = %d  is empty\n", index);
    }
    else
    {
        printf("index = %d  contains the following item\n", index);
        while (ptr != NULL)
        {

            printf("---------------\n");
            printf("%s\n", ptr->name);
            printf("%s\n", ptr->drink);
            printf("---------------\n");
            ptr = ptr->next;
        }
    }
}

void FindDrink(struct item inputTable[], char *name)
{

    int index = hashCode(name);
    bool foundName = false;
    char *drink;

    struct item *ptr = &inputTable[index];

    while (ptr != NULL)
    {

        if (ptr->name == name)
        {

            foundName = true;
            drink = ptr->drink;
        }
        ptr = ptr->next;
    }

    if (foundName == true)
    {

        printf("drink = %s\n", drink);
    }
    else
    {

        printf("%s  Was not found  in hashtable\n");
    }
}

void RemoveItem(struct item inputTable[], char *name)
{

    int index = hashCode(name);

    struct item *delptr = &inputTable[index];
    struct item *p1;
    struct item *p2;
    //case 0: bucket is empty

    printf("delptr = %s\n", delptr->name);
    printf("Char* = %s\n", name);

    if (strcmp(delptr->name, "empty") == 0 && strcmp(delptr->drink, "empty") == 0)
    {

        printf("name = %s  was not in hashtable\n", name);
    }

    //case 1: only one item contained in bucket and that item has matching name
    else if (strcmp(delptr->name, name) == 0 && delptr->next == NULL)
    {

        //change to default
        inputTable[index].name = "empty";
        inputTable[index].drink = "empty";
        printf(" %s name was removed form HashTable\n", name);
    }
    //case 2: match is located in the first item in the bucket but there are more items in the buckets
    else if (strcmp(delptr->name, name) == 0)
    {

       //bucket more than one
        p1 = delptr;
        p1 = p1->next;
        inputTable[index] = *p1; 
        free(delptr);

        printf(" %s name was removed form HasTable\n", name);
    }
    else
    {
        //case 3: bucket contains items but first item is not match
        p1 = delptr->next;
        p2 = delptr;
        
        while (p1 != NULL && strcmp(p1->name, name) != 0)
        {

            p2 = p1;
            p1 = p1->next;
        }
        if (p1 == NULL)
        {
            //case 3.1 -not match
            printf(" %s name was NOT in  HashTable\n", name);
        }
        else
        {

            //case 3.2 -match is found
            delptr = p1;
            p1 = p1->next;
            p2->next = p1;
            free(delptr);
        }
    }
}