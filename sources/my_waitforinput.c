/*
** my_play.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb  4 15:34:21 2017 Antonin Rapini
** Last update Sun Feb 19 19:48:39 2017 Antonin Rapini
*/

#include <signal.h>
#include <stdlib.h>
#include "my_game.h"
#include "my_global.h"
#include "utils.h"
#include "get_next_line.h"
#include "vector2.h"

int check_position(t_vector2 pos, t_game *game)
{
  my_putchar(pos.x + 64);
  my_putchar(pos.y + 48);
  if (game->mymap[pos.y + 1][pos.x + 1 + (1 * (pos.x - 1))] > '0'
      && game->mymap[pos.y + 1][pos.x + 1 + (1 * (pos.x - 1))] <= '5')
    {
      game->mymap[pos.y + 1][pos.x + 1 + (1 * (pos.x - 1))] = 'x';
      my_putstr(": hit\n\n");
      return (SIGUSR2);
    }
  else
    {
      if (game->mymap[pos.y + 1][pos.x + 1 + (1 * (pos.x - 1))] != 'x')
	game->mymap[pos.y + 1][pos.x + 1 + (1 * (pos.x - 1))] = 'o';
      my_putstr(": missed\n\n");
      return (SIGUSR1);
    }
}

void			inputsignal_handler
(int signum, siginfo_t *siginfo, void *context)
{
  static t_vector2	hitpos = {0, 0};
  static int		phase = 0;

  if (context)
    context = NULL;
  if (signum == SIGUSR1)
    {
      if (phase == 0)
	hitpos.x++;
      else if (phase == 1)
	hitpos.y++;
      kill(siginfo->si_pid, SIGUSR1);
    }
  else if (signum == SIGUSR2)
    {
      phase++;
      g_global = phase == 1 ? hitpos.x : hitpos.y;
      if (phase == 2)
	{
	  phase = 0;
	  hitpos.x = 0;
	  hitpos.y = 0;
	}
      kill(siginfo->si_pid, SIGUSR1);
    }
}

void			my_waitforinput(t_game *game)
{
  struct sigaction	sa;
  t_vector2		pos;

  g_global = 0;
  sa.sa_sigaction = &inputsignal_handler;
  sa.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa, NULL);
  my_putstr("waiting for enemy's attack...\n");
  while (g_global == 0);
  pos.x = g_global;
  g_global = 0;
  while (g_global == 0);
  pos.y = g_global;
  kill(game->enemypid, check_position(pos, game));
  game->my_turn = 1;
}
