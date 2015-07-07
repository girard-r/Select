/*
** display.c for display.c in /home/girard_r/Documents/PSU_2013_my_select
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat Jan 18 16:39:35 2014 girard_r
** Last update Sun Jan 19 19:23:12 2014 girard_r
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <term.h>
#include <signal.h>
#include <sys/ioctl.h>
#include "my_select.h"

extern int		g_fd;
extern t_win		g_win;

void			display_list(t_list *list)
{
  t_list		*tmp;
  char			*str;

  tmp = list->next;
  my_tputs(tgetstr("clear", NULL));
  while (tmp != list)
    {
      if ((str = tgoto(tgetstr("cm", NULL) ,
		       tmp->coord_x, tmp->coord_y)) == NULL)
	exit(0);
      my_tputs(str);
      if (tmp->mode == 1)
	my_tputs(tgetstr("us", NULL));
      if (tmp->sel == 1)
	my_tputs(tgetstr("so", NULL));
      if (write(g_fd, tmp->name, my_strlen(tmp->name)) < 0)
	exit(EXIT_SUCCESS);
      if (tmp->mode == 1)
	my_tputs(tgetstr("ue", NULL));
      if (tmp->sel == 1)
	my_tputs(tgetstr("se", NULL));
      tmp = tmp->next;
    }
}

int			check_display(t_list *list)
{
  if (g_win.nb_col == 0)
    return (-1);
  else if (list_len(list) > (g_win.nb_col * g_win.row))
    return (-1);
  else
    return (0);
}

int			my_puts(int a)
{
  char			c;

  c = (char)a;
  if (write(g_fd, &c, 1) < 0)
    exit(EXIT_SUCCESS);
}

void			get_size_term(int nb)
{
  struct winsize	win;

  if (ioctl(0, TIOCGWINSZ, &win) < 0)
    exit(EXIT_FAILURE);
  g_win.col = (int)win.ws_col;
  g_win.row = (int)win.ws_row;
  g_win.nb_col = g_win.col / g_win.step;
  g_win.state = 1;
  signal(SIGWINCH, get_size_term);
}

int			get_coord(char **av)
{
  int			i;
  int			save;

  save = 0;
  i = 1;
  while (av[i])
    {
      if (save < my_strlen(av[i]))
	save = my_strlen(av[i]);
      i = i + 1;
    }
  if (i == 1)
    return (-1);
  g_win.step = save + 2;
  return (0);
}
