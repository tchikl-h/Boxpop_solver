/*
** display.c for display in /home/tchikl_h/rendu/B2/Infography/gfx_boxpop
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Fri Jun 10 16:19:21 2016 Hervé TCHIKLADZE
** Last update Sat Jun 11 16:23:16 2016 Hervé TCHIKLADZE
*/

#include "boxpop.h"

void			display_board(t_box *data)
{
  t_bunny_position	pos;

  pos.y = 0;
  while (pos.y < 100)
    {
      pos.x = 0;
      while (pos.x < 100)
	{
	  if (data->board[pos.y][pos.x] == 0)
	    teksquare(data->graph->pix, pos.x, pos.y, BLACK);
	  if (data->board[pos.y][pos.x] == 1)
	    teksquare(data->graph->pix, pos.x, pos.y, GREEN);
	  if (data->board[pos.y][pos.x] == 2)
	    teksquare(data->graph->pix, pos.x, pos.y, WHITE);
	  if (data->board[pos.y][pos.x] == 3)
	    teksquare(data->graph->pix, pos.x, pos.y, YELLOW);
	  pos.x++;
	}
      pos.y++;
    }
}
