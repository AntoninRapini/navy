/*
** my_abs.c for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb  4 05:14:56 2017 Antonin Rapini
** Last update Sat Feb  4 05:19:29 2017 Antonin Rapini
*/

int my_abs(int nbr)
{
  return (0 - (nbr * (nbr < 0)) + (nbr * (nbr >= 0)));
}
