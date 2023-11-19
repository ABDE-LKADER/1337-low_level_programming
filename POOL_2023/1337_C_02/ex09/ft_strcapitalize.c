/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:53:51 by abadouab          #+#    #+#             */
/*   Updated: 2023/09/16 17:53:53 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ' ';
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	_strlowcase(str);
	while (str[i] != '\0')
	{
		if (((str[i - 1] < 'a' || str[i - 1] > 'z')
				&& (str[i - 1] < 'A' || str[i - 1] > 'Z')
				&& (str[i - 1] < '0' || str[i - 1] > '9'))
			&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= ' ';
		i++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= ' ';
	return (str);
}
