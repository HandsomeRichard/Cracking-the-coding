#include "HashTable.h"

int main(void)
{

    struct item HashTable[TABLE_SIZE];

    Init_HashTable(HashTable);

    AddItem(HashTable, "richard", "cola");
    AddItem(HashTable, "Sony", "popo");
    AddItem(HashTable, "Ed", "water");
    AddItem(HashTable, "Patrick1", "water");
    AddItem(HashTable, "Patrick2", "soda");
    AddItem(HashTable, "Patrick3", "POPO");

    printTable(HashTable);

    printItemIndex(HashTable, 1);

    //FindDrink(HashTable,"richard");
    //printItemIndex(HashTable,7);
    //char ptr[6] ="start";
    // hashCode(ptr);

    //RemoveItem(HashTable,"Ed");

    char s[30];
    while (s != "exit")
    {

        scanf("%s", &s);
        if (s != "exit")
        {
            printf("%s\n", s);
            RemoveItem(HashTable, s);
        }else if(  s =="showall"){
            
             printTable(HashTable);
        }

        printf("New\n");
        printItemIndex(HashTable, 1);
    }

    printf("OK");

    system("PAUSE");
    return 0;
}