/*
** error.c for error.c in /home/girard_r/Documents/PSU_2013_my_select
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun Jan 19 18:54:09 2014 girard_r
** Last update Sun Jan 19 20:53:39 2014 girard_r
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my_select.h"

extern int	g_fd;

void		my_tputs(char *str)
{
  if (tputs(str, g_fd, my_puts) == ERR)
    exit(EXIT_SUCCESS);
}

void		process_esc_bad_display(t_list *list, char *buffer,
					t_code *entry, struct termios usual)
{
  int			select;

  if ((select = compare_entry(buffer, entry)) == 2)
    entry[select].ptrf(&list, entry, usual);
}

int		exit_myselect(t_list **list, t_code *entry, struct termios usual)
{
  if (tputs(tgetstr("clear", NULL), g_fd, my_puts) == ERR)
    exit(EXIT_SUCCESS);
  my_tputs(tgetstr("vs", NULL));
  normal_mode(&usual);
  free(entry);
  while (list_len(*list) > 1)
    del_first_elem(list);
  if (list_len(*list) == 1)
    del_last_elem(list);
  close(g_fd);
  exit(EXIT_SUCCESS);
}
