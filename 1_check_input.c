#include "push_swap.h"

static int	check_duplicates_2(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (0);
		s++;
	}
	return (1);
}

static int	check_duplicates(char **array)
{
	char	*s;
	int		i;

	i = 1;
	s = NULL;
	while (array[i])
	{
		s = ft_strjoin(s, array[i]);
		i++;
	}
	printf ("%s\n", s);
	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!check_duplicates_2(s + i, s[i]))
			return (0);
		i++;
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
		error_case("Error\nFound duplicates.");
	return ;
}