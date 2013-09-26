/*
** uuid_access.c for uuid in /home/leprov_a//project/tek2/zappy/dev/server/inc/tools/uuid
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun 28 14:32:55 2013 alexis leprovost
** Last update Sat Jul  6 15:31:36 2013 alexis leprovost
*/

#include <stdlib.h>

#include "uuid.h"
#include "extend.h"

static int	uuid_cmp(void* id1, void* id2)
{
  return (!id1 || !id2 ? 0 : *(size_t*)id1 == *(size_t*)id2);
}

size_t	uuid_get(t_uuid* uuid)
{
  void*		tmp;
  size_t	id;

  if (!uuid || !uuid->__pool__)
    return (0);
  tmp = uuid->__pool__->front(uuid->__pool__);
  id = tmp ? *(size_t*)tmp : 0;
  free(uuid->__pool__->pop_front(uuid->__pool__));
  return (id);
}

t_bool	uuid_set(t_uuid* uuid, size_t id)
{
  size_t*	new;

  if (!uuid || !uuid->__pool__ || id > uuid->__capacity__)
    return (FALSE);
  if (uuid->__pool__->find_if(uuid->__pool__, &id, &uuid_cmp) ||
      !(new = malloc(sizeof(size_t))))
    return (FALSE);
  *new = id;
  uuid->__pool__->push_back(uuid->__pool__, (void*)new);
  return (TRUE);
}

t_bool	uuid_extend(t_uuid* uuid, size_t extend)
{
  size_t	capacity;
  size_t*	id;

  if (!uuid || !uuid->__pool__)
    return (FALSE);
  capacity = uuid->__capacity__;
  uuid->__capacity__ += extend;
  while (++capacity <= uuid->__capacity__)
    {
      if (!(id = malloc(sizeof(size_t))))
	return (FALSE);
      *id = capacity;
      uuid->__pool__->push_back(uuid->__pool__, (void*)id);
    }
  return (TRUE);
}
