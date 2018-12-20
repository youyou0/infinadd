# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "my.h"
# include "mylist.h"
# include "infinadd.h"

void			my_printerr()
{
  if (errno == ENOMEM)
    {
      write(2, "Out of memory\n", 14);
    }
}

int			main(int ac, char **av)
{
  nb_list_t		*a;
  nb_list_t		*b;
  nb_list_t		*result;
  int			len_nb1;
  int			len_nb2;

  if (ac < 3)
    {
      return (EXIT_FAILURE);
    }
  a = array_to_list(av[1]);
  b = array_to_list(av[2]);
  len_nb1 = my_strlen(av[1]);
  len_nb2 = my_strlen(av[2]);
  fill_zero_in_nb(a, b, len_nb1, len_nb2);
  if ((result = infin_add(a, b)) == NULL)
    {
      return (EXIT_FAILURE);
    }
  display_nb(result);
  return (EXIT_SUCCESS);
}
