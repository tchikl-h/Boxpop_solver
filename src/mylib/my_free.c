/*
** my_free.c for my_free in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Tue May  3 15:03:26 2016 Hervé TCHIKLADZE
** Last update Sat Jul  2 01:44:06 2016 Hervé TCHIKLADZE
*/

#include "boxpop.h"

void		my_free(void **ptr)
{
  if (*ptr != NULL)
    {
      free(*ptr);
      *ptr = NULL;
    }
}
