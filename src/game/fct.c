/*
** fct.c for fct in /home/tchikl_h/rendu/B2/Infography/gfx_boxpop
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Thu Jun 23 16:41:44 2016 Hervé TCHIKLADZE
** Last update Sat Jul  2 01:56:57 2016 Hervé TCHIKLADZE
*/

#include "boxpop.h"

int		fct_u_r(t_box *data)
{
  /* What we basically do is complete the status, and the position of the slot */
  if (data->maillon->pos.x + 1 > 100 || data->maillon->pos.y - 2 < 0)
    data->maillon->status[0] = -1;
  if (data->maillon->status[0] != -1 && data->board[data->maillon->pos.y - 2][data->maillon->pos.x + 1] != 1)
    data->maillon->status[0] = -1;
  if (!(data->maillon->dispo[0] = malloc(sizeof(*data->maillon->dispo[0]))))
    return (ERROR);
  if (data->maillon->status[0] != -1 && data->board[data->maillon->pos.y - 2][data->maillon->pos.x + 1] == 1)
    data->maillon->dispo[0]->pos.x = data->maillon->pos.x + 1;
  if (data->maillon->status[0] != -1 && data->board[data->maillon->pos.y - 2][data->maillon->pos.x + 1] == 1)
    data->maillon->dispo[0]->pos.y = data->maillon->pos.y - 2;
  return (SUCCESS);
}

int		fct_r_u(t_box *data)
{
  if (data->maillon->pos.x + 2 > 100 || data->maillon->pos.y - 1 < 0)
    data->maillon->status[1] = -1;
  if (data->maillon->status[1] != -1 && data->board[data->maillon->pos.y - 1][data->maillon->pos.x + 2] != 1)
    data->maillon->status[1] = -1;
 if (!(data->maillon->dispo[1] = malloc(sizeof(*data->maillon->dispo[1]))))
    return (ERROR);
  if (data->maillon->status[1] != -1 && data->board[data->maillon->pos.y - 1][data->maillon->pos.x + 2] == 1)
    data->maillon->dispo[1]->pos.x = data->maillon->pos.x + 2;
  if (data->maillon->status[1] != -1 && data->board[data->maillon->pos.y - 1][data->maillon->pos.x + 2] == 1)
    data->maillon->dispo[1]->pos.y = data->maillon->pos.y - 1;
  return (SUCCESS);
}

int		fct_r_d(t_box *data)
{
  if (data->maillon->pos.x + 2 > 100 || data->maillon->pos.y + 1 > 100)
    data->maillon->status[2] = -1;
  if (data->maillon->status[2] != -1 && data->board[data->maillon->pos.y + 1][data->maillon->pos.x + 2] != 1)
    data->maillon->status[2] = -1;
 if (!(data->maillon->dispo[2] = malloc(sizeof(*data->maillon->dispo[2]))))
    return (ERROR);
  if (data->maillon->status[2] != -1 && data->board[data->maillon->pos.y + 1][data->maillon->pos.x + 2] == 1)
    data->maillon->dispo[2]->pos.x = data->maillon->pos.x + 2;
  if (data->maillon->status[2] != -1 && data->board[data->maillon->pos.y + 1][data->maillon->pos.x + 2] == 1)
    data->maillon->dispo[2]->pos.y = data->maillon->pos.y + 1;
  return (SUCCESS);
}

int		fct_d_r(t_box *data)
{
  if (data->maillon->pos.x + 1 > 100 || data->maillon->pos.y + 2 > 100)
    data->maillon->status[3] = -1;
  if (data->maillon->status[3] != -1 && data->board[data->maillon->pos.y + 2][data->maillon->pos.x + 1] != 1)
    data->maillon->status[3] = -1;
 if (!(data->maillon->dispo[3] = malloc(sizeof(*data->maillon->dispo[3]))))
    return (ERROR);
  if (data->maillon->status[3] != -1 && data->board[data->maillon->pos.y + 2][data->maillon->pos.x + 1] == 1)
    data->maillon->dispo[3]->pos.x = data->maillon->pos.x + 1;
  if (data->maillon->status[3] != -1 && data->board[data->maillon->pos.y + 2][data->maillon->pos.x + 1] == 1)
    data->maillon->dispo[3]->pos.y = data->maillon->pos.y + 2;
  return (SUCCESS);
}

int		fct_d_l(t_box *data)
{
  if (data->maillon->pos.x - 1 < 0 || data->maillon->pos.y + 2 > 100)
    data->maillon->status[4] = -1;
  if (data->maillon->status[4] != -1 && data->board[data->maillon->pos.y + 2][data->maillon->pos.x - 1] != 1)
    data->maillon->status[4] = -1;
  if (!(data->maillon->dispo[4] = malloc(sizeof(*data->maillon->dispo[4]))))
    return (ERROR);
  if (data->maillon->status[4] != -1 && data->board[data->maillon->pos.y + 2][data->maillon->pos.x - 1] == 1)
    data->maillon->dispo[4]->pos.x = data->maillon->pos.x - 1;
  if (data->maillon->status[4] != -1 && data->board[data->maillon->pos.y + 2][data->maillon->pos.x - 1] == 1)
    data->maillon->dispo[4]->pos.y = data->maillon->pos.y + 2;
  return (SUCCESS);
}

int		fct_l_d(t_box *data)
{
  if (data->maillon->pos.x - 2 < 0 || data->maillon->pos.y + 1 > 100)
    data->maillon->status[5] = -1;
  if (data->maillon->status[5] != -1 && data->board[data->maillon->pos.y + 1][data->maillon->pos.x - 2] != 1)
    data->maillon->status[5] = -1;
  if (!(data->maillon->dispo[5] = malloc(sizeof(*data->maillon->dispo[5]))))
    return (ERROR);
  if (data->maillon->status[5] != -1 && data->board[data->maillon->pos.y + 1][data->maillon->pos.x - 2] == 1)
    data->maillon->dispo[5]->pos.x = data->maillon->pos.x - 2;
  if (data->maillon->status[5] != -1 && data->board[data->maillon->pos.y + 1][data->maillon->pos.x - 2] == 1)
    data->maillon->dispo[5]->pos.y = data->maillon->pos.y + 1;
  return (SUCCESS);
}

int		fct_l_u(t_box *data)
{
  if (data->maillon->pos.x - 2 < 0 || data->maillon->pos.y - 1 < 0)
    data->maillon->status[6] = -1;
  if (data->maillon->status[6] != -1 && data->board[data->maillon->pos.y - 1][data->maillon->pos.x - 2] != 1)
    data->maillon->status[6] = -1;
 if (!(data->maillon->dispo[6] = malloc(sizeof(*data->maillon->dispo[6]))))
    return (ERROR);
  if (data->maillon->status[6] != -1 && data->board[data->maillon->pos.y - 1][data->maillon->pos.x - 2] == 1)
    data->maillon->dispo[6]->pos.x = data->maillon->pos.x - 2;
  if (data->maillon->status[6] != -1 && data->board[data->maillon->pos.y - 1][data->maillon->pos.x - 2] == 1)
    data->maillon->dispo[6]->pos.y = data->maillon->pos.y - 1;
  return (SUCCESS);
}

int		fct_u_l(t_box *data)
{
  if (data->maillon->pos.x - 1 < 0 || data->maillon->pos.y - 2 < 0)
    data->maillon->status[7] = -1;
  if (data->maillon->status[7] != -1 && data->board[data->maillon->pos.y - 2][data->maillon->pos.x - 1] != 1)
    data->maillon->status[7] = -1;
 if (!(data->maillon->dispo[7] = malloc(sizeof(*data->maillon->dispo[7]))))
    return (ERROR);
  if (data->maillon->status[7] != -1 && data->board[data->maillon->pos.y - 2][data->maillon->pos.x - 1] == 1)
    data->maillon->dispo[7]->pos.x = data->maillon->pos.x - 1;
  if (data->maillon->status[7] != -1 && data->board[data->maillon->pos.y - 2][data->maillon->pos.x - 1] == 1)
    data->maillon->dispo[7]->pos.y = data->maillon->pos.y - 2;
  return (SUCCESS);
}
