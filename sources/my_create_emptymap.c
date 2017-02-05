/*
** my_createmap.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Feb  2 03:02:45 2017 Antonin Rapini
** Last update Thu Feb  2 19:25:57 2017 Antonin Rapini
*/

#include <get_next_line.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	**my_create_emptymap()
{
  char	**map;
  char	*str;
  int	fd;
  int	i;

  i = 0;
  if ((map = malloc(sizeof(char *) * 11)) == NULL)
    return (NULL);
  if ((fd = open("emptymap", O_RDONLY)) == -1)
    return (NULL);
  while (i++ < 11)
    map[i - 1] = NULL;
  i = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (i < 10)
	map[i] = str;
      else
	return (NULL);
      i++;
    }
  return (i == 10 ? map : NULL);
}
