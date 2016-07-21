/*
** teksquare.c for teksquare in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Thu Apr 28 18:23:33 2016 Hervé TCHIKLADZE
** Last update Fri Jun 10 16:20:37 2016 Hervé TCHIKLADZE
*/

#include "boxpop.h"

void			teksquare(t_bunny_pixelarray *pix, int x, int y, unsigned int color)
{
  t_bunny_position	pos;

  x *= 10;
  y *= 10;
  pos.y = y;
  while (pos.y < y + 10)
    {
      pos.x = x;
      while (pos.x < x + 10)
	{
	  tekpixel(pix, pos, color);
	  pos.x++;
	}
      pos.y++;
    }
}
