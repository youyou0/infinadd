# include <unistd.h>
# include <stdlib.h>
# include "my.h"
# include "mylist.h"
# include "infinadd.h"

int			is_digit(char c)
{
  if (c < 48 || c > 57)
    return (0);
  return (1);
}

nb_list_t		*add_in_res(nb_list_t *res, int add)
{
  if (!is_digit(res->digit))
    {
      res->digit = TO_CHAR(add % 10);
    }
  else if ((res = add_in_list_prev(res, TO_CHAR(add % 10))) == NULL)
    {
      my_printerr();
    }
  return (res);
}

nb_list_t		*infin_add(nb_list_t *a, nb_list_t *b)
{
  nb_list_t		*res;
  int			add;
  int			carry;

  carry = 0;
  if ((res = create_nb_elem()) == NULL)
    {
      my_printerr();
      return (NULL);
    }
  while (a)
    {
      add = TO_INT(a->digit) + TO_INT(b->digit) + carry;
      carry = add / 10;
      res = add_in_res(res, add);
      a = a->prev;
      b = b->prev;
    }
  if (carry > 0)
    {
      if ((res = add_in_list_prev(res, TO_CHAR(carry))) == NULL)
	my_printerr();
    }
  return (res);
}

void			fill_zero_in_nb(nb_list_t *a, nb_list_t *b,
					 int len_nb1, int len_nb2)
{
  int			zeros;
  nb_list_t		*tmp;

  zeros = 0;
  if (len_nb1 < len_nb2)
    {
      tmp = a;
      zeros = len_nb2 - len_nb1;
    }
  else if (len_nb1 > len_nb2)
    {
      tmp = b;
      zeros = len_nb1 - len_nb2;
    }
  while (tmp->prev)
    {
      tmp = tmp->prev;
    }
  while (zeros)
    {
      tmp = add_in_list_prev(tmp, '0');
      zeros -= 1;
    }
}

void			display_nb(nb_list_t *nb)
{
  while (nb)
    {
      my_putchar(nb->digit);
      nb = nb->next;
    }
}
