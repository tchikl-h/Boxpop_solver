/*
** end.c for end in /home/tchikl_h/rendu/B2/Infography/gfx_boxpop
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Jun 10 17:33:58 2016 Hervé TCHIKLADZE
** Last update Sun Jun 26 06:32:34 2016 Hervé TCHIKLADZE
*/

#include "boxpop.h"

int		finish(t_box *data)
{
  int		x;
  int		y;
  int		i;

  y = 0;
  i = 0;
  while (data->board[y] != NULL)
    {
      x = 0;
      while (data->board[y][x] != -1)
	{
	  if (data->board[y][x] == 1)
	    i++;
	  if (i > 1)
	    return (-1);
	  x++;
	}
      y++;
    }
  return (0);
}
