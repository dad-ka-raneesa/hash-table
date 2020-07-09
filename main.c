#include "hash_table.h"

int main(void);
int main(void)
{
  Hash_Table_Ptr table = create_hash_table(10);

  printf("\nInserting ...\n");
  insert(74, 10, table);
  insert(51, 20, table);
  insert(26, 30, table);
  insert(90, 40, table);
  insert(65, 50, table);
  insert(23, 60, table);
  insert(23, 1093, table);

  printf("\nHash Table : \n");
  display_hash_table(table);

  printf("\nSearching ...\n");
  display_hash_item(search(23, table));
  printf("\n");
  display_hash_item(search(3, table));
  printf("\n");

  printf("\nDeleting ...\n");
  display_hash_item(delete (23, table));
  printf("\n");
  display_hash_item(delete (3, table));
  printf("\n");

  printf("\nModified hash Table : \n");
  display_hash_table(table);

  return 0;
}
