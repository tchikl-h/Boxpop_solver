/*
** tekpixel.c for tekpixel in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Thu Apr 28 18:21:15 2016 Hervé TCHIKLADZE
** Last update Fri Jun 10 16:20:28 2016 Hervé TCHIKLADZE
*/

#include "boxpop.h"

void    tekpixel(t_bunny_pixelarray *pix, \
                 t_bunny_position pos, unsigned int color)
{
  t_color       *map;
  int           start;

  start = pos.y + pix->clipable.buffer.width * pos.x;
  map = (t_color*)pix->pixels;
  if (pos.y <= pix->clipable.buffer.width && pos.y >= 0 && \
      pos.x <= pix->clipable.buffer.height && pos.x >= 0)
    map[start].full = color;
}
