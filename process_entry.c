/*
** process_entry.c for process_entry in /home/girard_r/Documents/PSU_2013_my_select
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat Jan 18 17:15:26 2014 girard_r
** Last update Sun Jan 19 20:51:50 2014 girard_r
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include <termios.h>
#include <term.h>
#include "my_select.h"

extern int		g_fd;
extern t_win		g_win;

int			compare_entry(char *buffer, t_code *entry)
{
  int			i;
  int			j;
  int			cmp;

  i = 0;
  while (i < 9)
    {
      cmp = 0;
      j = 0;
      while (j < 4)
	{
	  if (entry[i].code[j] == buffer[j])
	    cmp += 1;
	  j = j + 1;
	}
      if (cmp == 4)
	return (i);
      i = i + 1;
    }
  return (-1);
}

int			my_modify_list(t_list **list)
{
  t_list		*tmp;
  int			x = 0;
  int			y = 0;
  int			n = 1;

  x = 0;
  y = 0;
  n = 1;
  tmp = (*list)->next;
  while (tmp != *list)
    {
      if (y == g_win.row)
	{
	  x = g_win.step * n++;
	  y = 0;
	}
      tmp->coord_x = x;
      tmp->coord_y = y++;
      tmp = tmp->next;
    }
  return (0);
}

void			process_bad_display(int *save)
{
  char			*str;

  *save = 1;
  if (tputs(tgetstr("clear", NULL), g_fd, my_puts) == ERR ||
      tputs(tgoto(tgetstr("cm", NULL) , 0, 0), g_fd, my_puts) == ERR ||
      write(g_fd, "Resize term\n", 13) < 0)
    exit(EXIT_SUCCESS);
}

void			process_good_display(t_list *list, char *buffer,
					     t_code *entry, struct termios usual)
{
  int			select;

  if (g_win.state == 1)
    {
      my_modify_list(&list);
      display_list(list);
      g_win.state = 0;
    }
  if ((select = compare_entry(buffer, entry)) != -1)
    {
      entry[select].ptrf(&list, entry, usual);
      display_list(list);
    }
}

void			get_entry(t_code *entry, t_list *list, struct termios usual)
{
  int			select;
  int			save;
  char			buffer[4];
  int			i;

  i = 0;
  save = 0;
  g_win.state = 0;
  init_buffer(buffer);
  while (read(0, buffer, 4) >= 0)
    {
      if (check_display(list) == 0)
	{
	  save = 0;
	  process_good_display(list, buffer, entry, usual);
	}
      else if (check_display(list) == -1 && save != 1)
	process_bad_display(&save);
      else if (check_display(list) == -1 && save == 1)
	process_esc_bad_display(list, buffer, entry, usual);
      init_buffer(buffer);
    }
  exit(EXIT_SUCCESS);
}
