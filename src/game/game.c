/*
** game.c for game in /home/tchikl_h/rendu/B2/Infography/gfx_boxpop
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Jun 10 16:18:57 2016 Hervé TCHIKLADZE
** Last update Sat Jul  2 02:07:51 2016 Hervé TCHIKLADZE
*/

#include "boxpop.h"

int			init_pos(t_box *data)
{
  /* This part will complete informations about the 8 possibilities around us */
  if (fct_u_r(data) == ERROR)
    return (ERROR);
  if (fct_r_u(data) == ERROR)
    return (ERROR);
  if (fct_r_d(data) == ERROR)
    return (ERROR);
  if (fct_d_r(data) == ERROR)
    return (ERROR);
  if (fct_d_l(data) == ERROR)
    return (ERROR);
  if (fct_l_d(data) == ERROR)
    return (ERROR);
  if (fct_l_u(data) == ERROR)
    return (ERROR);
  if (fct_u_l(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int			init_maillon(t_box *data)
{
  int			i;

  i = -1;
  data->maillon->dispo = NULL;
  /* Dispo will be the neighbours, the slots where we can go */
  if (!(data->maillon->dispo = malloc(sizeof(*data->maillon->dispo) * 8)))
    return (ERROR);
  /* Status will tell us if the slot is available */
  if (!(data->maillon->status = malloc(sizeof(*data->maillon->status) * 8)))
    return (ERROR);
  while (++i < 8)
    data->maillon->status[i] = 0;
  if (init_pos(data) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		move(t_box *data, int *i)
{
  int		j;

  j = -1;
  while (++j < 8)
    {
      /* In case we've found a slot available */
      if (data->maillon->status[j] == 0)
	{
	  /* Getting the positions of the next slot (in order to know where we went) */
	  data->maillon->next.x = data->maillon->dispo[j]->pos.x;
	  data->maillon->next.y = data->maillon->dispo[j]->pos.y;
	  data->maillon->j = j;
	  /* Disable the slot where we are */
	  data->board[data->maillon->pos.y][data->maillon->pos.x] = 0;
	  /* Assign the position of the next slot TO the next slot */
	  data->maillon->dispo[j]->pos.x = data->maillon->next.x;
	  data->maillon->dispo[j]->pos.y = data->maillon->next.y;
	  if (!(data->maillon->dispo[j]->prev = malloc(sizeof(*data->maillon->dispo[j]->prev))))
	    return (ERROR);
	  /* Linking the slots so that we can come back */
	  data->maillon->dispo[j]->prev = data->maillon;
	  /* Going to the next slot */
	  data->maillon = data->maillon->dispo[j];
	  /* write the path we took in the list */
	  data->list[*i].x = data->maillon->pos.x;
	  data->list[*i].y = data->maillon->pos.y;
	  (*i)++;
	  return (SUCCESS);
	}
    }
  /* If there is no available slot */
  /* Going back */
  data->maillon = data->maillon->prev;
  /* Changing the status of the slot that leads to a dead end */
  data->maillon->status[data->maillon->j] = -1;
  /* Enable the actual slot */
  data->board[data->maillon->pos.y][data->maillon->pos.x] = 1;
  data->blocked = 1;
  (*i)--;
  return (SUCCESS);
}

int		game(t_box *data)
{
  int		i;

  if (init_tab(data) == ERROR)
    return (ERROR);
  data->blocked = 0;
  i = 1;
  /* Writting the first slot in the list */
  data->list[0].x = data->maillon->pos.x;
  data->list[0].y = data->maillon->pos.y;
  /* Disable the first slot */
  data->board[data->maillon->pos.y][data->maillon->pos.x] = 0;
  while (finish(data) != 0)
    {
      if (data->blocked != 1 && init_maillon(data) == ERROR)
	return (ERROR);
      if (i == 1 && data->blocked == 1)
	{
	  printf("NO SOLUTION.\n");
	  exit(0);
	}
      data->blocked = 0;
      move(data, &i);
    }
  return (0);
}
