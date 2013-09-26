/*
** ini_clear.c for ini_clear in /home/guiho_r/projet/myftp/modules/serveur/lib/libini/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr  8 14:30:15 2013 ronan guiho
** Last update Mon Apr  8 14:34:05 2013 ronan guiho
*/

#include <stdlib.h>

void ini_clear(char *buffer, char *clear)
{
  unsigned int i;
  unsigned int i1;

  i = 0;
  i1 = 0;
  while (buffer[i])
    {
      if (buffer[i] != ' ')
	clear[i1++] = buffer[i];
      ++i;
    }
  clear[i1] = '\0';
}
