/*
** uuid_create.c for uuid in /home/leprov_a//project/tek2/zappy/dev/server/inc/tools/uuid
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun 28 15:32:44 2013 alexis leprovost
** Last update Thu Jul  4 15:24:32 2013 alexis leprovost
*/

#include <stdlib.h>

#include "uuid.h"
#include "extend.h"
#include "list.h"

t_bool	uuid_create(t_uuid* uuid, size_t capacity)
{
  size_t*	id;

  if (!uuid || !(uuid->__pool__ = new_list()) || (int)capacity <= 0)
    return (FALSE);
  uuid->__capacity__ = capacity;
  while (capacity)
    {
      if (!(id = malloc(sizeof(size_t))))
	return (FALSE);
      *id = capacity--;
      uuid->__pool__->push_front(uuid->__pool__, (void*)id);
    }
  return (TRUE);
}
