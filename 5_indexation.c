#include "push_swap.h"

static void init_index(t_stack_a **begin)
{
	t_stack_a *tmp;

	tmp = *begin;
	while (tmp)
	{
		tmp->index = -2;
		tmp = tmp->next;
	}
}

static void giving_index(t_stack_a **begin, int len)
{
	int i;
	int min;
	t_stack_a *begin_tmp;
	t_stack_a *tmp;

	min = INT_MAX;
	i = 0;
	init_index(begin);
	while (i < len)
	{
		begin_tmp = *begin;
		while (begin_tmp)
		{
			if (begin_tmp->number <= min && begin_tmp->index == -2)
			{
				min = begin_tmp->number;
				tmp = begin_tmp;
			}
			begin_tmp = begin_tmp->next;
		}
		min = INT_MAX;
		tmp->index = i;
		i++;
	}
}

/* static void	giving_index(t_stack_a **begin, int len)
{
	int			max;
	int			min;
	t_stack_a	*begin_tmp;

	begin_tmp = *begin;
	min = INT_MAX;
	max = INT_MIN;
	while (begin_tmp)
	{
		if (begin_tmp->number > max)
			max = begin_tmp->number;
		if (begin_tmp->number < min)
			min = begin_tmp->number;
		begin_tmp = begin_tmp->next;
	}
	printf("min number = %d, largest number = %d, len = %d\n", min, max, len);
}
 */

void indexation(t_stack_a **begin)
{
	int len;

	len = lstsize(*begin);
	giving_index(begin, len);
}