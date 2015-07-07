/*
** left_right.c for left_right in /home/girard_r/Documents/PSU_2013_my_select
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat Jan 18 18:36:03 2014 girard_r
** Last update Sun Jan 19 17:32:24 2014 girard_r
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my_select.h"

extern t_win	g_win;

int		select_right(t_list **list, t_code *entry, struct termios usual)
{
  t_list	*tmp;
  int		save;

  tmp = (*list)->next;
  while (tmp != *list && tmp->before->mode != 1)
    tmp = tmp->next;
  save = tmp->before->coord_y;
  tmp->before->mode = 0;
  while (tmp->coord_y != save)
    {
      if (tmp->next == *list)
	tmp = tmp->next->next;
      else
	tmp = tmp->next;
    }
  tmp->mode = 1;
}

int		select_left(t_list **list, t_code *entry, struct termios usual)
{
  t_list	*tmp;
  int		save;

  tmp = (*list)->before;
  while (tmp != *list && tmp->next->mode != 1)
    tmp = tmp->before;
  save = tmp->next->coord_y;
  tmp->next->mode = 0;
  if (tmp == *list)
    tmp = tmp->before;
  while (tmp->coord_y != save)
    {
      if (tmp->before == *list)
	tmp = tmp->before->before;
      else
	tmp = tmp->before;
    }
  tmp->mode = 1;
  return (0);
}

int		select_del(t_list **list, t_code *entry, struct termios usual)
{
  t_list	*tmp;

  g_win.state = 1;
  tmp = (*list)->next;
  while (tmp != *list && tmp->mode != 1)
    tmp = tmp->next;
  if (tmp->next == *list)
    tmp->next->next->mode = 1;
  else
    tmp->next->mode = 1;
  tmp->before->next = tmp->next;
  tmp->next->before = tmp->before;
  free(tmp);
  if (list_len(*list) == 0)
    exit_myselect(list, entry, usual);
  return (0);
}
