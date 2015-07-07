/*
** my_putstr.c for my_putstr in /home/girard_r/Documents/Piscine-C-Jour_04
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Thu Oct  3 16:32:25 2013 girard_r
** Last update Sun Jan 19 19:55:13 2014 girard_r
*/

int	my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) < 0)
    return (-1);
  return (0);
}
