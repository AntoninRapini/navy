/*
** my_putchar.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Feb  3 03:39:05 2017 Antonin Rapini
** Last update Fri Feb  3 03:39:24 2017 Antonin Rapini
*/

#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}
