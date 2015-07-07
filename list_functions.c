/*
** list_functions.c for list_functions in /home/girard_r/Documents/CPE_2013_Pushswap
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Fri Dec 20 17:11:57 2013 girard_r
** Last update Sat Jan 18 16:27:39 2014 girard_r
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include <termios.h>
#include <term.h>
#include "my_select.h"

t_list		*init_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->before = list;
  list->next = list;
  return (list);
}

void		del_first_elem(t_list **list)
{
  t_list	*tmp;

  tmp = (*list)->next;
  if (tmp != *list)
    {
      tmp->before->next = tmp->next;
      tmp->next->before = tmp->before;
      free(tmp);
    }
}

void		del_last_elem(t_list **list)
{
  t_list	*tmp;

  tmp = (*list)->before;
  if (tmp != *list)
    {
      tmp->before->next = tmp->next;
      tmp->next->before = tmp->before;
      free(tmp);
    }
}

int		list_len(t_list *list)
{
  int		cmp;
  t_list	*tmp;

  cmp = 0;
  tmp = list->next;
  while (tmp != list)
    {
      cmp = cmp + 1;
      tmp = tmp->next;
    }
  return (cmp);
}

int		init_buffer(char *buffer)
{
  int		i;

  i = 0;
  while (i < 4)
    buffer[i++] = 0;
  return (0);
}
