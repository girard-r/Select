/*
** my_select.h for my_select.h in /home/girard_r/Documents/CPE_2013_Pushswap
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Fri Dec 20 17:07:55 2013 girard_r
** Last update Sun Jan 19 20:54:23 2014 girard_r
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

typedef struct	s_list
{
  char		*name;
  int		mode;
  int		sel;
  int		coord_x;
  int		coord_y;
  struct s_list	*next;
  struct s_list	*before;
}		t_list;

typedef struct	s_code
{
  char		code[4];
  int		(*ptrf)();
}		t_code;

typedef struct	s_win
{
  int		row;
  int		col;
  int		nb_col;
  int		step;
  int		state;
}		t_win;

int		select_up(t_list **list, t_code *entry, struct termios usual);
int		select_down(t_list **list, t_code *entry, struct termios usual);
t_list		*init_list();
int		add_before(t_list **elem, char *new_name);
void		display_list(t_list *list);
void		del_first_elem(t_list **list);
void		del_last_elem(t_list **list);
int		list_len(t_list *list);
int		my_puts(int a);
t_code		*init_entry();
void		init_entry_2(t_code *entry);
void		init_entry_3(t_code *entry);
int		select_enter(t_list **list, t_code *entry, struct termios usual);
int		select_esc(t_list **list, t_code *entry, struct termios usual);
int		select_space(t_list **list, t_code *entry, struct termios usual);
int		exit_myselect(t_list **list, t_code *entry, struct termios usual);
int		check_display(t_list *list);
void		get_size_term(int nb);
int		get_coord(char **av);
int		init_select(t_list **list);
int		count_sel(t_list *list);
int		compare_entry(char *buffer, t_code *entry);
int		my_modify_list(t_list **list);
void		process_bad_display(int *save);
void		get_entry(t_code *entry, t_list *list, struct termios usual);
void		process_good_display(t_list *list, char *buffer,
				     t_code *entry, struct termios usual);
void		process_select(t_list *list, struct termios tmp);
int		empty_list(t_list *list, char **av);
int		select_right(t_list **list, t_code *entry, struct termios usual);
int		select_left(t_list **list, t_code *entry, struct termios usual);
int		select_del(t_list **list, t_code *entry, struct termios usual);
void		normal_mode(struct termios *tmp);
void		raw_mode(struct termios *t);
void		my_tputs(char *str);
void		process_esc_bad_display(t_list *list, char *buffer,
					t_code *entry, struct termios usual);

#endif /* !MY_SELECT_H_ */
