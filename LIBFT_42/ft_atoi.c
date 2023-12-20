/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:22:38 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/10 16:51:09 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	over_fix(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		// 922337203685477580
		printf("9BELL: %ld\n", num);
		printf("FIN WESLAT INDEX: %d\n\n", i);
		if (num > 922337203685477580 || (num > 922337203685477580 && str[i] > '7')) // "9223372036854775808"
			return (over_fix(sign));
		num = num * 10 + str[i] - 48; // PLUS THE LAST ONE // 9223372036854775808 -1 // 9223372036854775808 = -9
		i++;
		printf("BE3D: %ld\n", num);
		printf("FIN WESLAT INDEX: %d\n\n\n\n\n", i);
		if (str[i] == '\0')
			printf("RAH WSELNA\n");
	}
	return (num * sign);
}
#include <string.h>
int main ()
{
	printf("%d\n", ft_atoi("9223372036854775890"));
	printf("%d\n", atoi("9223372036854775890"));
}
