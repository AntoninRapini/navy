/*
** my_checkgamestatus.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb  4 15:44:24 2017 Antonin Rapini
** Last update Sun Feb  5 21:10:51 2017 Antonin Rapini
*/

#include "my_game.h"

int	my_checkgamestatus(t_game *game)
{
  int	i;
  int	j;
  int	xnumber;

  xnumber = 0;
  i = 0;
  while (game->mymap[i])
    {
      j = 0;
      while (game->mymap[i][j])
	{
	  if (game->mymap[i][j] == 'x')
	    xnumber++;
	  j++;
	}
      i++;
    }
  if (xnumber == 14)
    return (0);
  xnumber = 0;
  i = 0;
  while (game->enemymap[i])
    {
      j = 0;
      while (game->enemymap[i][j])
	{
	  if (game->enemymap[i][j] == 'x')
	    xnumber++;
	  j++;
	}
      i++;
    }
  if (xnumber == 14)
    return (1);
  return (2);
}
