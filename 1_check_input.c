#include "push_swap.h"

static int	check_min_max_int(char **array)
{
	long	n;
	int	i;

	n = 0;
	i = 0;
	while (array[++i])
	{
		n = ft_atoi(array[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		n = 0;
	}
	return (1);
}

static int	compare_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	else if (ft_strlen(s1) == ft_strlen(s2))
	{
		while (s2[i])
		{
			if (!ft_strchr(s2, s1[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

static int	check_duplicates(char **array)
{
	int	i;
	int	prev;

	i = 1;
	prev = 2;
	while (array[i])
	{
		while (array[prev])
		{
			if (!compare_str(array[i], array[prev]))
				return (0);
			prev++;
		}
		i++;
		prev = i + 1;
	}
	return (1);
}

void	check_input(char **array)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (array[i])
	{
		while (array[i][j])
		{
			if (array[i][j] < '0' && array[i][j] > '9' &&
				array[i][j] != '-')
				error_case("Invalid arguments.");
			j++;
		}
		i++;
	}
	if (!check_duplicates(array))
		error_case("Error\nFound duplicates.\n");
	else if (!check_min_max_int(array))
		error_case("Error\nValue is over MIN or MAX int.\n");
	return ;
}