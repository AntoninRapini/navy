/*
** navy.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Feb  2 02:48:38 2017 Antonin Rapini
** Last update Sat Feb  4 15:12:28 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"
#include "my_game.h"
#include "my_global.h"

int g_global = 0;

int		main(int ac, char **av)
{
  t_game	*game;

  if ((game = my_creategame(ac, av)) == NULL)
    return (84);
  my_printpid();
  if (ac == 2)
    return (my_hostgame(game));
  else if (ac == 3)
    return (my_joingame(game));
}
