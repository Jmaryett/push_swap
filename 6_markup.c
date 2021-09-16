#include "push_swap.h"

static void	init_markup_head(t_stack_a **begin)
{
	t_stack_a *tmp;

	tmp = *begin;
	while (tmp)
	{
		if (tmp->index == 0)
		{
			tmp->markup_head = 1;
			tmp->keep_in_stack_a = "true";
		}
		else
		{
			tmp->markup_head = 0;
			tmp->keep_in_stack_a = NULL;
		}
		tmp = tmp->next;
	}
}

static void	keep_in_stack_a(t_stack_a **begin)
{
	t_stack_a	*begin_tmp;
	t_stack_a	*mark;

	mark = *begin;
	while (mark->markup_head != 1)
		mark = mark->next;
	begin_tmp = *begin;
	while (mark->next)
	{
		if (mark->number < mark->next->number)
			mark->keep_in_stack_a = "true";
		else if (mark->number > mark->next->number)
		{
			mark->next->keep_in_stack_a = "false";
			break ;
		}
		mark = mark->next;
	}
	if (ft_strncmp(mark->keep_in_stack_a, "true", ft_strlen("true")))
	{
		if (begin_tmp->number > mark->number)
			begin_tmp->keep_in_stack_a = "true";
		else
			begin_tmp->keep_in_stack_a = "false";
	}
	else if (ft_strncmp(mark->keep_in_stack_a, "false", ft_strlen("true")))
	{
		while (begin_tmp->markup_head != 1)
			begin_tmp->keep_in_stack_a = "false";
		begin_tmp = begin_tmp->next;
	}
}

void	markups(t_stack_a **begin)
{
	//t_stack_a *tmp;

	//tmp = *begin;
	init_markup_head(begin);
	keep_in_stack_a(begin);

}