/*
** my_creategame.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Feb  3 03:11:43 2017 Antonin Rapini
** Last update Sat Feb  4 15:01:45 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"
#include "my_game.h"

t_game		*my_creategame(int ac, char **av)
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  if (ac == 2)
    game->playernbr = 1;
  else if (ac == 3)
    {
      game->enemypid = my_getnbr(av[1]);
      game->playernbr = 2;
    }
  else
    return (NULL);
  if ((game->mymap = my_create_emptymap()) == NULL)
    return (NULL);
  if ((game->enemymap = my_create_emptymap()) == NULL)
    return (NULL);
  if (my_fillmap(game->mymap, av[game->playernbr]))
    return (NULL);
  return (game);
}
