/*
** my_strlen.c for my_strlen in /home/girard_r/Documents/Piscine-C-Jour_04
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Thu Oct  3 18:15:54 2013 girard_r
** Last update Fri Dec 13 15:15:08 2013 girard_r
*/

#include <stdlib.h>

int    	my_strlen(char *str)
{
  int	n;

  n = 0;
  if (str == NULL)
    return (0);
  while (*str != 0)
    {
      str = str + 1;
      n = n + 1;
    }
  return (n);
}
