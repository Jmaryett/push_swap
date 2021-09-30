#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == ' ')
		return (1);
	else
		return (0);
}
