/*
** process_keys.c for process_keys in /home/girard_r/Documents/PSU_2013_my_select
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat Jan 18 16:13:23 2014 girard_r
** Last update Sun Jan 19 19:50:47 2014 girard_r
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my_select.h"

extern int		g_fd;

int			select_down(t_list **list, t_code *entry, struct termios usual)
{
  t_list		*tmp;

  tmp = (*list)->next;
  while (tmp != *list && tmp->mode != 1)
    tmp = tmp->next;
  tmp->mode = 0;
  if (tmp->next == *list)
    tmp->next->next->mode = 1;
  else
    tmp->next->mode = 1;
  return (0);
}

int			select_up(t_list **list, t_code *entry, struct termios usual)
{
  t_list		*tmp;

  tmp = (*list)->next;
  while (tmp != *list && tmp->mode != 1)
    tmp = tmp->next;
  tmp->mode = 0;
  if (tmp->before == *list)
    tmp->before->before->mode = 1;
  else
    tmp->before->mode = 1;
  return (0);
}

int			select_enter(t_list **list, t_code *entry, struct termios usual)
{
  t_list		*tmp;
  int			count;

  if (tputs(tgetstr("clear", NULL), g_fd, my_puts) == ERR)
    exit(EXIT_SUCCESS);
  tmp = (*list)->next;
  count = count_sel(*list);
  while (tmp != *list)
    {
      if (tmp->sel == 1)
	{
	  my_putstr(tmp->name);
	  if (count > 1)
	    write(1, " ", 1);
	  if (count == 1)
	    write(1, "\n", 1);
	  count = count - 1;
	}
      tmp = tmp->next;
    }
  exit_myselect(list, entry, usual);
}

int			select_esc(t_list **list, t_code *entry, struct termios usual)
{
  if (tputs(tgetstr("clear", NULL), g_fd, my_puts) == ERR)
    exit(EXIT_SUCCESS);
  exit_myselect(list, entry, usual);
}

int			select_space(t_list **list, t_code *entry, struct termios usual)
{
  t_list		*tmp;

  tmp = (*list)->next;
  while (tmp != *list && tmp->mode != 1)
    tmp = tmp->next;
  if (tmp->sel == 0)
    tmp->sel = 1;
  else if (tmp->sel == 1)
    tmp->sel = 0;
  tmp->mode = 0;
  if (tmp->next == *list)
    tmp->next->next->mode = 1;
  else
    tmp->next->mode = 1;
  return (0);
}
