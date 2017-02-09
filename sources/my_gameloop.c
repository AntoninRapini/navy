/*
** my_gameloop.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb  4 14:16:04 2017 Antonin Rapini
** Last update Thu Feb  9 12:12:30 2017 Antonin Rapini
*/

#include "my_game.h"
#include "my_global.h"
#include "sources.h"
#include "utils.h"

int	my_gameloop(t_game *game)
{
  int	gamestatus;
  int	round;

  round = 0;
  my_showgame(game);
  while ((gamestatus = my_checkgamestatus(game)) == 2)
    {
      if (game->my_turn)
	my_play(game);
      else
	my_waitforinput(game);
      round++;
      if (round == 2)
	{
	  my_showgame(game);
	  round = 0;
	}
    }
  if (round != 0)
    my_showgame(game);
  if (gamestatus == 1)
    my_putstr("\nI won\n");
  else
    my_putstr("\nEnemy won\n");
  return (gamestatus);
}
