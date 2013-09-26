/*
** main.c for main in /home/guiho_r/depot/zappy/server/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 21:00:12 2013 ronan guiho
** Last update Wed Jul 10 18:03:00 2013 alexis leprovost
*/

#include <stdlib.h>
#include <time.h>

#include "core.h"
#include "ressource.h"
#include "level.h"
#include "cell.h"
#include "protocol.h"

const char* g_ressource_string[MAX_RESSOURCE_TYPE] = {
  "nourriture",
  "linemate",
  "deraumere",
  "sibur",
  "mendiane",
  "phiras",
  "thystame"
};

const int g_ressource_int[MAX_RESSOURCE_TYPE] = {
  FOOD,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  LINEMATE
};

const t_proto g_proto[] =
{
  {"avance", 6},
  {"droite", 6},
  {"gauche", 6},
  {"voir", 4},
  {"inventaire", 10},
  {"prend", 5},
  {"pose", 4},
  {"expulse", 7},
  {"broadcast", 9},
  {"incantation", 11},
  {"fork", 4},
  {"connect_nbr", 11},
  {"msz", 3},
  {"bct", 3},
  {"mct", 3},
  {"tna", 3},
  {"ppo", 3},
  {"plv", 3},
  {"pin", 3},
  {"sgt", 3},
  {"sst", 3}
};

const t_cell	g_level[MAX_LEVEL - 1] = {
  {{0, 0, 0, 0, 0, 0, 0}, 0},
  {{0, 1, 0, 0, 0, 0, 0}, 1},
  {{0, 1, 1, 1, 0, 0, 0}, 2},
  {{0, 2, 0, 1, 0, 2, 0}, 2},
  {{0, 1, 1, 2, 0, 1, 0}, 4},
  {{0, 1, 2, 1, 3, 0, 0}, 4},
  {{0, 1, 2, 3, 0, 1, 0}, 6},
  {{0, 2, 2, 2, 2, 2, 1}, 6}
};

int main(int ac, char **av)
{
  (void)ac;
  srand(time(NULL));
  return (core_run(av));
}
