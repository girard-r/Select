/*
** process_keys_2.c for process_keys_2 in /home/girard_r/Documents/PSU_2013_my_select
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat Jan 18 16:36:55 2014 girard_r
** Last update Sun Jan 19 19:29:17 2014 girard_r
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my_select.h"

extern int	g_fd;

t_code		*init_entry()
{
  t_code	*entry;

  if ((entry = malloc(sizeof(t_code) * 9)) == NULL)
    return (NULL);
  entry[0].code[0] = 27;
  entry[0].code[1] = 91;
  entry[0].code[2] = 65;
  entry[0].code[3] = 0;
  entry[0].ptrf = &select_up;
  entry[1].code[0] = 27;
  entry[1].code[1] = 91;
  entry[1].code[2] = 66;
  entry[1].code[3] = 0;
  entry[1].ptrf = &select_down;
  entry[2].code[0] = 27;
  entry[2].code[1] = 0;
  entry[2].code[2] = 0;
  entry[2].code[3] = 0;
  entry[2].ptrf = &select_esc;
  init_entry_2(entry);
  init_entry_3(entry);
  return (entry);
}

void		init_entry_2(t_code *entry)
{
  entry[3].code[0] = 32;
  entry[3].code[1] = 0;
  entry[3].code[2] = 0;
  entry[3].code[3] = 0;
  entry[3].ptrf = &select_space;
  entry[4].code[0] = 10;
  entry[4].code[1] = 0;
  entry[4].code[2] = 0;
  entry[4].code[3] = 0;
  entry[4].ptrf = &select_enter;
  entry[5].code[0] = 27;
  entry[5].code[1] = 91;
  entry[5].code[2] = 67;
  entry[5].code[3] = 0;
  entry[5].ptrf = &select_right;
}

void		init_entry_3(t_code *entry)
{
  entry[6].code[0] = 27;
  entry[6].code[1] = 91;
  entry[6].code[2] = 68;
  entry[6].code[3] = 0;
  entry[6].ptrf = &select_left;
  entry[7].code[0] = 27;
  entry[7].code[1] = 91;
  entry[7].code[2] = 51;
  entry[7].code[3] = 126;
  entry[7].ptrf = &select_del;
  entry[8].code[0] = 127;
  entry[8].code[1] = 0;
  entry[8].code[2] = 0;
  entry[8].code[3] = 0;
  entry[8].ptrf = &select_del;
}

int		init_select(t_list **list)
{
  t_list	*tmp;

  tmp = (*list)->next;
  tmp->mode = 1;
  return (0);
}

int		count_sel(t_list *list)
{
  t_list	*tmp;
  int		count;

  tmp = list->next;
  count = 0;
  while (tmp != list)
    {
      if (tmp->sel == 1)
	count = count + 1;
      tmp = tmp->next;
    }
  return (count);
}
