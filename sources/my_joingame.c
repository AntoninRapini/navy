/*
** my_joingame.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb  4 05:43:27 2017 Antonin Rapini
** Last update Thu Feb  9 11:26:43 2017 Antonin Rapini
*/

#include <signal.h>
#include <stdlib.h>
#include "utils.h"
#include "sources.h"
#include "my_game.h"
#include "my_global.h"

void my_getanswer(int sig)
{
  if (sig == SIGUSR1)
    g_global = 1;
}

int			my_joingame(t_game *game)
{
  struct sigaction	sa;

  sa.sa_handler = &my_getanswer;
  sigaction(SIGUSR1, &sa, NULL);
  kill(game->enemypid, SIGUSR1);
  while (g_global == 0);
  g_global = 0;
  game->my_turn = 0;
  my_putstr("successfully connected\n\n");
  return (my_gameloop(game));
}
