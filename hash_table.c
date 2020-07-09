#include "hash_table.h"

Hash_Table_Ptr create_hash_table(int size)
{
  Hash_Table_Ptr hash_table = malloc(sizeof(Hash_Table));
  hash_table->size = size;
  hash_table->items = malloc(sizeof(Hash_List_Ptr) * size);
  return hash_table;
}

int hash_function(int key, int size)
{
  return key % size;
}

void insert(int key, int value, Hash_Table_Ptr table)
{
  int array_index = hash_function(key, table->size);
  if (table->items[array_index] == NULL)
  {
    table->items[array_index] = create_hash_list();
  }
  add_to_hash_list(key, value, table->items[array_index]);
}

Hash_Item_Ptr search(int key, Hash_Table_Ptr table)
{
  int array_index = hash_function(key, table->size);
  Hash_Item_Ptr searching_item = get_hash_item_of(table->items[array_index], key);
  return searching_item;
}

Hash_Item_Ptr delete (int key, Hash_Table_Ptr table)
{
  int array_index = hash_function(key, table->size);
  Hash_Item_Ptr item_deleted = remove_from_hash_list(table->items[array_index], key);
  return item_deleted;
}

void display_hash_table(Hash_Table_Ptr table)
{
  for (int i = 0; i < table->size; i++)
  {
    printf("Index = %2d , ", i);
    display_hash_list(table->items[i]);
  }
}
