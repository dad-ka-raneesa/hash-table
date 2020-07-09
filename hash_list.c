#include "hash_table.h"

Hash_Item_Ptr create_hash_item(int key, int value)
{
  Hash_Item_Ptr hash_item = malloc(sizeof(Hash_Item));
  hash_item->key = key;
  hash_item->value = value;
  hash_item->next = NULL;
  return hash_item;
}

Hash_List_Ptr create_hash_list()
{
  Hash_List_Ptr hash_list = malloc(sizeof(Hash_List));
  hash_list->head = NULL;
  hash_list->last = NULL;
  hash_list->count = 0;
  return hash_list;
}

Hash_Item_Ptr get_hash_item_of(Hash_List_Ptr list, int key)
{
  if (list == NULL)
  {
    return NULL;
  }
  Hash_Item_Ptr p_walk = list->head;
  Hash_Item_Ptr matching_node = NULL;
  int is_found = 0;
  while (p_walk != NULL && !is_found)
  {
    if (p_walk->key == key)
    {
      matching_node = p_walk;
      is_found = 1;
    }
    p_walk = p_walk->next;
  }
  return matching_node;
}

void add_to_hash_list(int key, int value, Hash_List_Ptr hash_list)
{
  Hash_Item_Ptr matching_node = get_hash_item_of(hash_list, key);
  if (matching_node)
  {
    matching_node->value = value;
    return;
  }
  Hash_Item_Ptr hash_item = create_hash_item(key, value);
  Hash_Item_Ptr *ptr_to_set = &hash_list->head;
  if (hash_list->head != NULL)
  {
    ptr_to_set = &hash_list->last->next;
  }
  (*ptr_to_set) = hash_item;
  hash_item->previous = hash_list->last;
  hash_list->last = hash_item;
  hash_list->count++;
}

Hash_Item_Ptr remove_from_hash_list(Hash_List_Ptr list, int key)
{
  Hash_Item_Ptr item_to_delete = get_hash_item_of(list, key);
  if (item_to_delete != NULL)
  {
    Hash_Item_Ptr *ptr_to_set = &list->head;
    Hash_Item_Ptr previous_item = item_to_delete->previous;
    if (previous_item)
    {
      ptr_to_set = &previous_item->next;
    }
    (*ptr_to_set) = item_to_delete->next;
    if (item_to_delete->next)
      item_to_delete->next->previous = item_to_delete->previous;
  }
  return item_to_delete;
}

void display_hash_item(Hash_Item_Ptr item)
{
  if (item)
  {
    printf("%2d=%2d ", item->key, item->value);
  }
  else
  {
    printf("--=-- ");
  }
}

void display_hash_list(Hash_List_Ptr hash_list)
{
  if (hash_list != NULL)
  {
    Hash_Item_Ptr p_walk = hash_list->head;
    while (p_walk)
    {
      display_hash_item(p_walk);
      p_walk = p_walk->next;
    }
  }
  printf("\n");
}
