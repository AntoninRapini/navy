/*
** utils.h for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Feb  2 19:16:58 2017 Antonin Rapini
** Last update Sat Feb 11 02:19:18 2017 Antonin Rapini
*/

#ifndef UTILS_H_
# define UTILS_H_

#include "vector2.h"

void	my_show_wordtab(char **);
void	my_putstr(char *);
void	my_putchar(char);
void	my_put_nbr(int);
int	my_getnbr(char *);
int	my_abs(int);
int	my_strlen(char *);
t_vector2 my_str_to_pos(char *);

#endif /* !UTILS_H_ */
