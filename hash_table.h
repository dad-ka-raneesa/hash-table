#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "hash_list.h"

typedef struct hash_table
{
  int size;
  Hash_List_Ptr *items;
} Hash_Table;

typedef Hash_Table *Hash_Table_Ptr;

Hash_Table_Ptr create_hash_table(int size);

int hash_function(int key, int size);

void insert(int key, int value, Hash_Table_Ptr table);
Hash_Item_Ptr search(int key, Hash_Table_Ptr table);
Hash_Item_Ptr delete (int key, Hash_Table_Ptr table);

void display_hash_table(Hash_Table_Ptr table);

#endif
