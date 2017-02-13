/*
** my_hostgame.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Feb  3 02:56:12 2017 Antonin Rapini
** Last update Mon Feb 13 16:52:29 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <signal.h>
#include "utils.h"
#include "my_game.h"
#include "my_global.h"
#include "sources.h"

void my_savepid(int sig, siginfo_t *siginfo, void *context)
{
  if (sig == SIGUSR1 && context == NULL)
    {
    }
  my_putstr("enemy connected\n\n");
  g_global = siginfo->si_pid;
}

int			my_hostgame(t_game *game)
{
  struct sigaction	sa;

  my_putstr("waiting for enemy connection...\n\n");
  sa.sa_sigaction = &my_savepid;
  sa.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &sa, NULL);
  while (g_global == 0);
  game->enemypid = g_global;
  g_global = 0;
  game->my_turn = 1;
  kill(game->enemypid, SIGUSR1);
  return (my_gameloop(game));
}
