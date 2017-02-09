/*
** my_checkgamestatus.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb  4 15:44:24 2017 Antonin Rapini
** Last update Thu Feb  9 11:21:47 2017 Antonin Rapini
*/

#include "my_game.h"

int	my_checkgamestatus(t_game *game)
{
  int	i;
  int	j;
  int	xnumber;

  xnumber = 0;
  i = 0;
  while (game->mymap[i++])
    {
      j = 0;
      while (game->mymap[i - 1][j++])
	if (game->mymap[i - 1][j - 1] == 'x')
	  xnumber++;
    }
  if (xnumber == 14)
    return (0);
  xnumber = 0;
  i = 0;
  while (game->enemymap[i++])
    {
      j = 0;
      while (game->enemymap[i - 1][j++])
	if (game->enemymap[i - 1][j - 1] == 'x')
	  xnumber++;
    }
  return (xnumber == 14 ? 1 : 2);
}
