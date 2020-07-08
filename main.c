#include "hash_table.h"

void display_h_item(h_item_ptr item);
void display_h_item(h_item_ptr item)
{
  if (item)
    printf("Key is %d, Value is %d\n", item->key, item->value);
  else
    printf("Key is --, Value is --\n");
}

void display_h_table(h_table_ptr hash_table)
{
  h_item_ptr item;
  for (int i = 0; i < hash_table->size; i++)
  {
    item = hash_table->data[i];
    printf("Index is %2d, ", i);
    display_h_item(item);
  }
}

int main(void)
{
  h_table_ptr hash_table = create_h_table(50);
  printf("Inserting...... \n");
  insert(74, 10, hash_table);
  insert(51, 20, hash_table);
  insert(26, 30, hash_table);
  insert(90, 40, hash_table);
  insert(65, 50, hash_table);
  insert(23, 60, hash_table);
  printf("\nHash table : \n");
  display_h_table(hash_table);
  printf("\nSearch : \n");
  display_h_item(search(23, hash_table));
  display_h_item(search(3, hash_table));
  return 0;
}