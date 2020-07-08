#include "hash_table.h"

h_item_ptr create_h_item(int key, int value)
{
  h_item_ptr new_h_item = malloc(sizeof(h_item));
  new_h_item->key = key;
  new_h_item->value = value;
  return new_h_item;
}

h_table_ptr create_h_table(int size)
{
  h_table_ptr new_h_table = malloc(sizeof(h_table));
  new_h_table->size = size;
  new_h_table->data = malloc(sizeof(h_item_ptr) * size);
  return new_h_table;
}

int hash_function(key, size)
{
  return key % size;
}

void insert(int key, int value, h_table_ptr hash_table)
{
  h_item_ptr hash_item = create_h_item(key, value);
  int index = hash_function(key, hash_table->size);

  while (hash_table->data[index] != NULL)
  {
    index++;
    index %= hash_table->size;
  }

  hash_table->data[index] = hash_item;
}

h_item_ptr search(int key, h_table_ptr hash_table)
{
  int index = hash_function(key, hash_table->size);
  h_item_ptr result = NULL;
  h_item_ptr current_item = hash_table->data[index];
  int is_found = 0;
  while (current_item != NULL && !is_found)
  {
    if (current_item->key == key)
    {
      result = current_item;
      is_found = 1;
    }
    index++;
    index %= hash_table->size;
    current_item = hash_table->data[index];
  }
  return result;
}

h_item_ptr delete (int key, h_table_ptr hash_table)
{
  int index = hash_function(key, hash_table->size);
  h_item_ptr result = NULL;
  int is_found = 0;
  while (hash_table->data[index] != NULL && !is_found)
  {
    if (hash_table->data[index]->key == key)
    {
      is_found = 1;
      result = hash_table->data[index];
      hash_table->data[index] = NULL;
    }
    index++;
    index %= hash_table->size;
  }
  return result;
}
