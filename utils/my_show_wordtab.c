/*
** my_showa_wordtab.c for my_show_wordtab in /home/antonin.rapini/CPool_Day08/task03
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 21:18:48 2016 Antonin Rapini
** Last update Sat Feb  4 15:38:48 2017 Antonin Rapini
*/

#include "utils.h"
#include <unistd.h>

void	my_show_wordtab(char **tab)
{
  int	index;

  index = 0;
  while (tab[index++] != 0)
    {
      my_putstr(tab[index - 1]);
      write(1, "\n", 1);
    }
}
