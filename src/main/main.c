/*
** main.c for main in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_box
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Thu Apr 28 17:14:15 2016 Hervé TCHIKLADZE
** Last update Sat Jul  2 01:50:19 2016 Hervé TCHIKLADZE
*/

#include "boxpop.h"

int			modify_board(t_box *data)
{
  static int		i = 0;

  if (finish(data) == 0 || data->list[i].x == -1)
    exit(0);
  if (i != 0)
    data->board[data->list[i - 1].y][data->list[i - 1].x] = 0;
  data->board[data->list[i].y][data->list[i].x] = 2;
  data->board[data->list[i + 1].y][data->list[i + 1].x] = 3;
  i++;
  return (SUCCESS);
}

int			save_board(t_box *data)
{
  int			x;
  int			y;

  y = 0;
  if (!(data->board_disp = malloc(sizeof(*data->board_disp) * 101)))
    return (ERROR);
  while (data->board[y] != NULL)
    {
      x = 0;
      if (!(data->board_disp[y] = malloc(sizeof(*data->board_disp[y]) * 101)))
	return (ERROR);
      while (data->board[y][x] != -1)
	{
	  data->board_disp[y][x] = data->board[y][x];
	  x++;
	}
      data->board_disp[y][x] = -1;
      y++;
    }
  data->board_disp[y] = NULL;
  return (SUCCESS);
}

int			reset_board(t_box *data)
{
  int			x;
  int			y;

  y = 0;
  while (data->board_disp[y] != NULL)
    {
      x = 0;
      while (data->board_disp[y][x] != -1)
	{
	  data->board[y][x] = data->board_disp[y][x];
	  x++;
	}
      data->board[y][x] = -1;
      y++;
    }
  data->board[y] = NULL;
  return (SUCCESS);
}

t_bunny_response        mouse_draw(t_bunny_event_state  state,
                                   t_bunny_mousebutton  button,
                                   void                 *your_data)
{
  t_box			*data;
  t_bunny_position	*pos;
  int			tmp;

  data = (t_box *)your_data;
  (void)button;
  if (state == GO_DOWN && data->pause != 2)
    {
      pos = (t_bunny_position *)bunny_get_mouse_position();
      tmp = pos->x;
      pos->x = pos->y;
      pos->y = tmp;
      if (data->pause == 1 && data->board[pos->y / 10][pos->x / 10] == 1)
	{
	  if (data->maillon->pos.y != -1 && data->maillon->pos.x != -1)
	    data->board[data->maillon->pos.y][data->maillon->pos.x] = 1;
	  data->board[pos->y / 10][pos->x / 10] = 2;
	  data->maillon->pos.y = pos->y / 10;
	  data->maillon->pos.x = pos->x / 10;
	  return (GO_ON);
	}
      if (data->pause == 1 && data->board[pos->y / 10][pos->x / 10] == 2)
	{
	  data->board[pos->y / 10][pos->x / 10] = 1;
	  return (GO_ON);
	}
      if (data->pause == 0 && data->board[pos->y / 10][pos->x / 10] == 1)
	{
	  data->board[pos->y / 10][pos->x / 10] = 0;
	  return (GO_ON);
	}
      if (data->pause == 0 && data->board[pos->y / 10][pos->x / 10] == 0)
	{
	  data->board[pos->y / 10][pos->x / 10] = 1;
	  return (GO_ON);
	}
    }
  return (GO_ON);
}

int			backspace_cond(t_box *data)
{
  if (data->pause == 0)
    {
      data->pause = 1;
      return (0);
    }
  if (data->pause == 1)
    data->pause = 0;
  return (0);
}

t_bunny_response	echap_down(t_bunny_event_state	state,
				   t_bunny_keysym	key,
				   void			*your_data)
{
  t_box		*data;

  data = (t_box *)your_data;
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      if (key == BKS_SPACE)
	backspace_cond(data);
      if (key == BKS_RETURN)
	{
	  if (save_board(data) == ERROR)
	    return (ERROR);
	  game(data);
	  data->board = data->board_disp;
	  data->pause = 2;
	}
    }
  return (GO_ON);
}

t_bunny_response	loop(void *pass)
{
  t_box		*data;
  t_bunny_key		key;
  t_bunny_click		mouse;

  data = (t_box *)pass;
  key = &echap_down;
  mouse = &mouse_draw;
  bunny_set_key_response(key);
  bunny_set_click_response(mouse);
  if (data->pause == 3)
    exit(0);
  if (data->pause == 2)
    modify_board(data);
  display_board(data);
  bunny_blit(&data->graph->win->buffer, &data->graph->pix->clipable, NULL);
  bunny_display(data->graph->win);
  /* The "2" in the "sleep" below is referring to the time (in second) to wait between two frames during the solving part*/
  if (data->pause > 1)
    sleep(2);
  return (GO_ON);
}

int			main()
{
  t_box			data;
  t_bunny_loop		main_loop;

  main_loop = &loop;
  if (!(data.graph = malloc(sizeof(*data.graph))))
    return (ERROR);
  if (!(data.maillon = malloc(sizeof(*data.maillon))))
    return (-1);
  data.maillon->pos.x = -1;
  data.maillon->pos.y = -1;
  data.pause = 0;
  data.graph->pix = bunny_new_pixelarray(1000, 1000);
  data.graph->win = bunny_start(1000, 1000, false, "BoxPop");
  if (init_board(&data) == ERROR)
    return (ERROR);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(data.graph->win, 10, &data);
  bunny_stop(data.graph->win);
  bunny_delete_clipable(&data.graph->pix->clipable);
  return (SUCCESS);
}
