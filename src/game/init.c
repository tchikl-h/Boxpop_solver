/*
** init.c for init in /home/tchikl_h/rendu/B2/Infography/gfx_boxpop
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Jun 10 16:40:29 2016 Hervé TCHIKLADZE
** Last update Fri Jul  1 12:47:34 2016 Hervé TCHIKLADZE
*/

#include "boxpop.h"

int             init_board(t_box *data)
{
  int           x;
  int           y;

  y = 0;
  data->board = NULL;
  if (!(data->board = malloc(sizeof(*data->board) * (100 + 1))))
    return (ERROR);
  while (y < 100)
    {
      if (!(data->board[y] = malloc(sizeof(*data->board[y]) * (100 + 1))))
        return (ERROR);
      x = 0;
      while (x < 100)
        {
          data->board[y][x] = 0;
          x++;
        }
      data->board[y][x] = -1;
      y++;
    }
  data->board[y] = NULL;
  return (SUCCESS);
}

int             count_case(t_box *data)
{
  int           nb;
  int           x;
  int           y;

  nb = 0;
  y = 0;
  while (data->board[y] != NULL)
    {
      x = 0;
      while (data->board[y][x] != -1)
        {
          if (data->board[y][x] > 0)
            nb++;
          x++;
        }
      y++;
    }
  return (nb);
}

int		init_tab(t_box *data)
{
  int		nb;

  nb = count_case(data);
  if (!(data->list = malloc(sizeof(*data->list) * (nb + 1))))
    return (-1);
  data->list[nb].x = -1;
  data->list[nb].y = -1;
  return (0);
}
