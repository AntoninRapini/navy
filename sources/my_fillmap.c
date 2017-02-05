/*
** my_fillmap.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb  4 03:25:40 2017 Antonin Rapini
** Last update Sun Feb  5 17:54:30 2017 Antonin Rapini
*/

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "utils.h"
#include "vector2.h"

int	my_placeboat(int i, t_vector2 start, t_vector2 end, char **map)
{
  int	j;
  int	dir;

  j = 0;
  if (start.x != end.x)
    {
      dir = start.x < end.x ? 1 : -1;
      if (my_abs(start.x - end.x) != i + 1)
	return (1);
      while (j < i + 2)
	{
	  if (map[start.y + 1][start.x + 2 + (1 * start.x + j * dir) + j * dir] != '.')
	    return (1);
	  map[start.y + 1][start.x + 2 + (1 * start.x + j * dir) + j * dir] = i + 2 + 48;
	  j++;
	}
    }
  else
    {
      dir = start.y < end.y ? 1 : -1;
      if (my_abs(start.y - end.y) != i + 1)
	return (1);
      while (j < i + 2)
	{
	  if (map[start.y + 1 + j * dir][start.x + 2 + (1 * start.x)] != '.')
	    return (1);
	  map[start.y + 1 + j * dir][start.x + 2 + (1 * start.x)] = i + 2 + 48;
	  j++;
	}
    }
  return (0);
}

int		my_fillmap(char **map, char *path)
{
  char		*currline;
  int		i;
  int		fd;
  t_vector2	start;
  t_vector2	end;

  i = 0;
  if ((fd = open(path, O_RDONLY)) == -1)
    return (1);
  while ((currline = get_next_line(fd)))
    {
      if (my_strlen(currline) != 7 || currline[0] != i + 2 + 48)
	return (1);
      start.x = currline[2] - 65;
      start.y = currline[3] - 48;
      end.x = currline[5] - 65;
      end.y = currline[6] - 48;
      if (start.x > 8 || end.x > 8 || start.y > 8 || end.y > 8)
	return (1);
      if ((start.y != end.y && start.x != end.x)
	  || my_placeboat(i, start, end, map))
	return (1);
      i++;
    }
  return (i != 4);
}
