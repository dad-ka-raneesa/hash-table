#include "hash_table.h"

void display_h_table(h_table_ptr hash_table)
{
  h_item_ptr item;
  for (size_t i = 0; i < hash_table->size; i++)
  {
    item = hash_table->data[i];
    if (item)
    {
      printf("Index is %zu, key is %d, value is %d\n", i, item->key, item->value);
    }
  }
}

int main(void)
{
  h_table_ptr hash_table = create_h_table(50);
  int value1 = 10;
  int value2 = 20;
  insert(74, value1, hash_table);
  insert(51, value2, hash_table);
  display_h_table(hash_table);
  return 0;
}