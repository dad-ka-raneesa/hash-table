#ifndef __HASH_TABLE_h_
#define __HASH_TABLE_h_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int key;
  int value;
} h_item;

typedef h_item *h_item_ptr;

typedef struct
{
  int size;
  h_item_ptr *data;
} h_table;

typedef h_table *h_table_ptr;

h_item_ptr create_h_item(int key, int value);
h_table_ptr create_h_table(int size);
void insert(int key, int value, h_table_ptr hash_table);

#endif