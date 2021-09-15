#include "push_swap.h"

static void	init_flags(t_stack_a **begin)
{
	t_stack_a	*tmp;

	tmp = *begin;
	while (tmp)
	{
		tmp->flag = 0;
		tmp = tmp->next;
	}
}

static void	index_for_all_other_numbers(int min, int max, int len, t_stack_a **begin)
{
	t_stack_a	*begin_tmp;
	//t_stack_a	*tmp;
	int			i;

	init_flags(begin);
	i = len - 2;
	while (i > 0)
	{
		begin_tmp = *begin;
		while (begin_tmp)
		{
			if (begin_tmp->number < max)
			{
				
			}
		}
	}
	//begin_tmp = *begin;
}

static void	largest_number(t_stack_a **begin, int len, int min)
{
	int			max;
	//t_stack_a	*tmp;
	t_stack_a	*begin_tmp;

	begin_tmp = *begin;
	max = INT_MIN;
	while (begin_tmp)
	{
		if (begin_tmp->number > max)
		{
			max = begin_tmp->number;
			//tmp = begin_tmp;
		}
		begin_tmp = begin_tmp->next;
	}
	//tmp->index = len - 1;
	//printf ("largest number = %d\nindex of it = %d\n", max, tmp->index);
	index_for_all_other_numbers(min, max, len, begin);
}

static void	small_elem(t_stack_a **begin, int len)
{
	t_stack_a	*begin_tmp;
	int			min;

	begin_tmp = *begin;
	min = INT_MAX;
	while (begin_tmp)
	{
		if (begin_tmp->number < min)
			min = begin_tmp->number;
		begin_tmp = begin_tmp->next;
	}
	largest_number(begin, len, min);
	//index_for_all_other_numbers(min, len, begin);
}

void	indexation(t_stack_a **begin)
{
	int	len;

	len = lstsize(*begin);
	small_elem(begin, len);
	//i dont need to keep minimum number i need to keep the address of that element of list and assign its index to 0 so then 
	//to assign all other indexex of the list
}