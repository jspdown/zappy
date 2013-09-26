/*
** ini_line.c for ini in /home/guiho_r/projet/myftp/modules/serveur/lib/libini/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr  8 13:57:56 2013 ronan guiho
** Last update Wed Jun 12 16:14:06 2013 alexis leprovost
*/

#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>

#include "ini.h"

char  *ini_line(const int fd, char *s)
{
  int           n;
  static int    i;
  static int    swtch;
  static char   buffer[C_READ];

  n = -1;
  bzero(s, C_READ);
  if (swtch != 1)
    {
      bzero(buffer, C_READ);
      if (read(fd, buffer, C_READ) == 0 || M_BUFFER == 0)
        return (NULL);
      i = 0;
      swtch = 1;
    }
  if (buffer[i] == '\n')
    i++;
  while (buffer[i] != '\n' && ++n != M_BUFFER && i < C_READ)
    s[n] = buffer[i++];
  if (i == C_READ)
    swtch = 0;
  return (s);
}
