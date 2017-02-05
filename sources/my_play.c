/*
** my_play.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb  4 15:34:21 2017 Antonin Rapini
** Last update Sun Feb  5 21:17:24 2017 Antonin Rapini
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "vector2.h"
#include "my_game.h"
#include "my_global.h"
#include "utils.h"
#include "get_next_line.h"

void	get_answer(int sig)
{
  if (sig == SIGUSR1)
    g_global = 1;
  else if (sig == SIGUSR2)
    g_global = 2;
}

void	get_feedback(t_vector2 pos, t_game *game, char *buffer)
{
  struct sigaction	sa;

  g_global = 0;
  sa.sa_handler = &get_answer;
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa , NULL);
  while (g_global == 0){}
  my_putstr(buffer);
  if (g_global == 1)
    {
      my_putstr(": missed\n\n");
      game->enemymap[pos.y + 1][pos.x + 1 + (1 * (pos.x - 1))] = 'o';
    }
  else
    {
      my_putstr(": hit\n\n");
      game->enemymap[pos.y + 1][pos.x + 1 + (1 * (pos.x - 1))] = 'x';
    }
}

void	my_shoot(t_vector2 target, t_game *game, char *buffer)
{
  int	i;

  i = 0;
  while (i < target.x)
    {
      kill(game->enemypid, SIGUSR1);
      usleep(100000);
      i++;
    }
  i = 0;
  usleep(100000);
  kill(game->enemypid, SIGUSR2);
  usleep(100000);
  while (i < target.y)
    {
      kill(game->enemypid, SIGUSR1);
      usleep(100000);
      i++;
    }
  kill(game->enemypid, SIGUSR2);
  usleep(100000);
  kill(game->enemypid, SIGUSR2);
  get_feedback(target, game, buffer);
}

void		my_play(t_game *game)
{
  char		*buffer;
  t_vector2	target;
  int		playing;

  playing = 1;
  my_putchar('\n');
  while (playing)
    {
      my_putstr("attack: ");
      buffer = get_next_line(0);
      if (my_strlen(buffer) != 2)
	my_putstr("wrong position\n");
      else
	{
	  if (buffer[0] >= 'A' && buffer[0] <= 'Z')
	    {
	      target.x = buffer[0] - 64;
	      target.y = buffer[1] - 48;
	    }
	  else
	    {
	      target.x = buffer[1] - 64;
	      target.y = buffer[0] - 48;
	    }
	  if (target.x < 1 || target.y < 1 || target.x > 8 || target.y > 8)
	    my_putstr("wrong position\n");
	  else
	    {
	      my_shoot(target, game, buffer);
	      playing = 0;
	      game->my_turn = 0;
	    }
	  free(buffer);
	}
    }
}
