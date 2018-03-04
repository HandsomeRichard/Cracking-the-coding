#ifndef HASHTABLE_H__
#define HASHTABLE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define  TABLE_SIZE 4

struct item{
    char *name;
    char *drink;
    struct item* next;
};




int hashCode(char* key);
void Init_HashTable(struct item*);
void Show_HashTable(struct item*);
void AddItem(struct item* ,char* name , char* drink);
//計算出有多個elements在這array或是稱buckets，array index內部
int NumberOfItemsInIndex(struct item* ,int index);

void printTable(struct item*);
void printItemIndex( struct item*, int index);

//用Name 找 drink
void FindDrink(  struct item* , char* name);
void RemoveItem(  struct item* , char* name);




#endif 