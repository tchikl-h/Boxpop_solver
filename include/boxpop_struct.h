/*
** boxpop_struct.h for boxpop_struct in /home/tchikl_h/rendu/B2/Infography/gfx_boxpop/include
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Jun 10 16:16:13 2016 Hervé TCHIKLADZE
** Last update Fri Jul  1 05:36:16 2016 Hervé TCHIKLADZE
*/

#ifndef BOXPOP_STRUCT_H_
# define BOXPOP_STRUCT_H_

typedef struct		s_graph
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
}			t_graph;

typedef struct		s_maillon
{
  int			*status;
  struct s_maillon	**dispo;
  struct s_maillon	*prev;
  t_bunny_position	next;
  t_bunny_position	pos;
  int			j;
}			t_maillon;

typedef struct		s_box
{
  t_maillon		*maillon;
  t_bunny_position	*list;
  t_graph		*graph;
  int			**board;
  int			**board_disp;
  int			pause;
  int			blocked;
}			t_box;

#endif /* BOXPOP_STRUCT_H_ */
