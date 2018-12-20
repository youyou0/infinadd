# include <unistd.h>
# include <stdlib.h>
# include "my.h"
# include "mylist.h"
# include "infinadd.h"

nb_list_t		*create_nb_elem()
{
  nb_list_t		*nb_list;

  if ((nb_list = (nb_list_t *) malloc(sizeof(nb_list_t))) == NULL)
    {
      return (NULL);
    }
  nb_list->next = NULL;
  nb_list->prev = NULL;
  nb_list->digit = 0;
  return (nb_list);
}

nb_list_t		*add_in_list_prev(nb_list_t *nb, char digit)
{
  nb_list_t		*new_elem;

  if ((new_elem = create_nb_elem()) == NULL)
    {
      return (NULL);
    }
  new_elem->digit = digit;
  new_elem->prev = NULL;
  new_elem->next = nb;
  nb->prev = new_elem;
  return (new_elem);
}

nb_list_t		*add_in_list_next(nb_list_t *nb, char digit)
{
  nb_list_t		*new_elem;

  if ((new_elem = create_nb_elem()) == NULL)
    {
      return (NULL);
    }
  new_elem->digit = digit;
  new_elem->next = NULL;
  new_elem->prev = nb;
  nb->next = new_elem;
  return (new_elem);
}

nb_list_t		*array_to_list(char *nb)
{
  nb_list_t		*new_nb;
  int			i;

  if ((new_nb = create_nb_elem()) == NULL)
    {
      my_printerr();
      return (NULL);
    }
  new_nb->digit = nb[0];
  i = 1;
  while (nb[i])
    {
      new_nb = add_in_list_next(new_nb, nb[i]);
      i += 1;
    }
  return (new_nb);
}
