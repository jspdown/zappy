/*
** uuid_init.c for uuid in /home/leprov_a//project/tek2/zappy/dev/server/inc/tools/uuid
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun 28 14:15:43 2013 alexis leprovost
** Last update Tue Jul  2 09:54:06 2013 alexis leprovost
*/

#include <stdlib.h>

#include "uuid.h"

static void	uuid_init_method(t_uuid* uuid)
{
  uuid->get = &uuid_get;
  uuid->set = &uuid_set;
  uuid->extend = &uuid_extend;
  uuid->create = &uuid_create;
  uuid->is_create = &uuid_is_create;
  uuid->capacity = &uuid_capacity;
  uuid->size = &uuid_size;
}

static void	uuid_init_attr(t_uuid* uuid)
{
  uuid->__capacity__ = 0;
  uuid->__pool__ = NULL;
}

t_uuid*	new_uuid()
{
  t_uuid*	new;

  if ((new = malloc(sizeof(t_uuid))) == NULL)
    return (NULL);
  uuid_init_attr(new);
  uuid_init_method(new);
  return (new);
}

void	delete_uuid(t_uuid** uuid)
{
  if (*uuid)
    {
      if ((*uuid)->__pool__)
	delete_list(&(*uuid)->__pool__, &free);
      free(*uuid);
      *uuid = NULL;
    }
}
