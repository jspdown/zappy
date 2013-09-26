/*
** uuid_util.c for uuid in /home/leprov_a//project/tek2/zappy/dev/server/inc/tools/uuid
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun 28 15:30:33 2013 alexis leprovost
** Last update Tue Jul  2 09:53:44 2013 alexis leprovost
*/

#include <stdlib.h>

#include "uuid.h"
#include "extend.h"

t_bool	uuid_is_create(t_uuid* uuid)
{
  return (!uuid || !uuid->__pool__ ? FALSE : TRUE);
}

size_t	uuid_capacity(t_uuid* uuid)
{
  return (uuid ? uuid->__capacity__ : 0);
}

size_t	uuid_size(t_uuid* uuid)
{
  return (uuid && uuid->__pool__ ? uuid->__pool__->size(uuid->__pool__) : 0);
}
