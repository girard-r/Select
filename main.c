/*
** main.c for main in /home/girard_r/Documents/PSU_2013_my_select
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat Jan 18 18:11:06 2014 girard_r
** Last update Sun Jan 19 20:04:22 2014 girard_r
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

int			g_fd = 0;

int			get_env_term(char **envp)
{
  int			i;
  char			*str;

  i = 0;
  if (envp[0] == NULL)
    {
      write(g_fd, "No environnement: ABORT, need TERM=\n", 36);
      exit(EXIT_SUCCESS);
    }
  while (envp[i])
    {
      if (my_strncmp("TERM=", envp[i], 5) == 0)
	return (i);
      i = i + 1;
    }
  write(g_fd, "No TERM= environnement variable\n", 32);
  exit(EXIT_SUCCESS);
}

int			main(int ac, char **av, char **envp)
{
  struct termios	tmp;
  t_list		*list;
  int			max_col;
  struct termios	t;

  if ((g_fd = open("/dev/tty", O_WRONLY)) == -1 ||
      tcgetattr(0, &t) == -1)
    return (-1);
  if (tgetent(NULL, &(envp[get_env_term(envp)][5])) == ERR)
    return (-1);
  my_tputs(tgetstr("vi", NULL));
  tmp = t;
  if ((list = init_list()) == NULL)
    return (-1);
  if (get_coord(av) == -1)
    {
      write(g_fd, "No argument : abort\n", 20);
      return (-1);
    }
  get_size_term(0);
  empty_list(list, av);
  raw_mode(&t);
  process_select(list, tmp);
  return (0);
}
