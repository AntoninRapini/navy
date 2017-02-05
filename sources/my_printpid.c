/*
** my_printpid.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Feb  3 03:36:55 2017 Antonin Rapini
** Last update Fri Feb  3 03:51:32 2017 Antonin Rapini
*/

#include <unistd.h>
#include <sys/types.h>
#include "utils.h"

void my_printpid()
{
  my_putstr("my_pid: ");
  my_put_nbr(getpid());
  my_putchar('\n');
}
