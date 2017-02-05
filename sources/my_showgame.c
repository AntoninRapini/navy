/*
** my_showgame.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb  4 15:36:14 2017 Antonin Rapini
** Last update Sun Feb  5 20:59:04 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"

void my_showgame(t_game *game)
{
  my_putstr("my positions:\n");
  my_show_wordtab(game->mymap);
  my_putstr("\nenemy's positions:\n");
  my_show_wordtab(game->enemymap);
}
