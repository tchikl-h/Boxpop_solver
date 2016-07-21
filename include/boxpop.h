/*
** boxpop.h for boxpop in /home/tchikl_h/rendu/B2/Infography/gfx_boxpop/include
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Jun 10 16:16:20 2016 Hervé TCHIKLADZE
** Last update Thu Jun 23 16:48:40 2016 Hervé TCHIKLADZE
*/

#ifndef BOXPOP_H_
# define BOXPOP_H_

#define SUCCESS 0
#define ERROR -1

#include <stdio.h>
#include <unistd.h>
#include <lapin.h>
#include <math.h>
#include "boxpop_struct.h"

void		tekpixel(t_bunny_pixelarray *, t_bunny_position, unsigned int);
void		teksquare(t_bunny_pixelarray *, int, int, unsigned int);
void            display_board(t_box *);
int             init_board(t_box *);
int             game_of_box(t_box *);
int             init_save(t_box *);
void            my_free_all(t_box *);
void            my_free_tab(void ***);
void            my_free(void **);
int             possibility(t_box *, int);
int             init_tab(t_box *);
int             game(t_box *);
int             check_end(t_box *, int);
int             finish(t_box *);
int             fct_u_r(t_box *);
int             fct_r_u(t_box *);
int             fct_r_d(t_box *);
int             fct_d_r(t_box *);
int             fct_d_l(t_box *);
int             fct_l_d(t_box *);
int             fct_l_u(t_box *);
int             fct_u_l(t_box *);

#endif /* BOXPOP_H_ */
