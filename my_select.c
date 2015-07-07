/*
** my_select.c for my_select in /home/girard_r/Documents/TP_mySelect
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Tue Jan 14 15:56:13 2014 girard_r
** Last update Sun Jan 19 19:30:22 2014 girard_r
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <term.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_select.h"

t_win			g_win= {0, 0, 0, 0, 0};
extern int		g_fd;

void			normal_mode(struct termios *tmp)
{
  if (tcsetattr(0, 0, tmp) == -1)
    if (write(g_fd, "SETATTR ERROR\n", 14) < 0)
      exit(EXIT_SUCCESS);
}

void			raw_mode(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_lflag &= ~ECHO;
  t->c_cc[VMIN] = 0;
  t->c_cc[VTIME] = 0.1;
  if (tcsetattr(0, 0, t) == -1)
    if (write(g_fd, "SETATTR ERROR\n", 14) < 0)
      exit(EXIT_SUCCESS);
}

int			add_before(t_list **elem, char *new_name)
{
  t_list		*new_elem;
  static int		x = 0;
  static int		y = 0;
  static int		n = 1;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return (-1);
  new_elem->mode = 0;
  new_elem->sel = 0;
  if (y == g_win.row - 1)
    {
      x = g_win.step * n++;
      y = 0;
    }
  new_elem->coord_x = x;
  new_elem->coord_y = y++;
  new_elem->name = new_name;
  new_elem->before = (*elem)->before;
  new_elem->next = *elem;
  (*elem)->before->next = new_elem;
  (*elem)->before = new_elem;
  return (0);
}

int			empty_list(t_list *list, char **av)
{
  int			i;

  i = 1;
  while (av[i])
    add_before(&list, av[i++]);
  display_list(list);
}

void			process_select(t_list *list, struct termios tmp)
{
  t_code		*entry;

  init_select(&list);
  display_list(list);
  if ((entry = init_entry()) == NULL)
    exit(EXIT_SUCCESS);
  get_entry(entry, list, tmp);
}
