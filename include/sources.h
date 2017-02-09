/*
** sources.h for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Feb  2 19:16:05 2017 Antonin Rapini
** Last update Thu Feb  9 11:17:11 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "my_game.h"

t_game	*my_creategame(int, char **);
char	**my_create_emptymap();
int	my_fillmap(char **, char *);
void	my_printpid();
int	my_hostgame(t_game *);
int	my_joingame(t_game *);
int	my_gameloop(t_game *);
void	my_play(t_game *);
void	my_waitforinput(t_game *);
void	my_showgame(t_game *);
int	my_checkgamestatus(t_game *);

#endif /* !SOURCES_H_ */
