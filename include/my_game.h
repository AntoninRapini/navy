/*
** my_game.h for navy in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Feb  3 02:58:50 2017 Antonin Rapini
** Last update Sun Feb  5 02:31:43 2017 Antonin Rapini
*/

#ifndef MY_GAME_H_
# define MY_GAME_H_

typedef struct	s_game
{
  char		**mymap;
  char		**enemymap;
  int		playernbr;
  int		enemypid;
  int		my_turn;
}		t_game;

#endif /* !MY_GAME_H_ */
