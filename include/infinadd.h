#ifndef _INFINADD_H_
# define _INFINADD_H_

# define TO_CHAR(x) ((char) (x + 48))
# define TO_INT(x) ((int) (x - 48))

typedef struct		nb_list
{
  char			digit;
  struct nb_list	*next;
  struct nb_list	*prev;
}			nb_list_t;

nb_list_t		*create_nb_elem();
nb_list_t		*add_in_list_prev(nb_list_t *nb, char const digit);
nb_list_t		*add_in_list_next(nb_list_t *nb, char const digit);
nb_list_t		*array_to_list(char const * const nb);
nb_list_t		*infin_add(nb_list_t const *a, nb_list_t const *b);
nb_list_t		*add_in_res(nb_list_t *res, int const add);
int			is_digit(char const c);
void			fill_zero_in_nb(nb_list_t *a, nb_list_t *b,
					int const len_nb1, int const len_nb2);
void			my_printerr();
void			display_nb(nb_list_t const *nb);

#endif /* _INFINADD_H_ */
