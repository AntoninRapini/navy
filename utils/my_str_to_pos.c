/*
** my_str_to_pos.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb 11 01:55:39 2017 Antonin Rapini
** Last update Sat Feb 11 02:20:22 2017 Antonin Rapini
*/

#include "vector2.h"

t_vector2	my_str_to_pos(char *buffer)
{
  t_vector2	target;

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
  return (target);
}
