/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:58:11 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/04 18:45:05 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

# define SET  "!%0#51x!", 1962401082

int main()
{
	int len;
	printf("ORIGINAL:\n");
	len = printf(SET);
	printf("-------> %d", len);
	printf("\n");
	printf("OWN:\n");
	len = ft_printf(SET);
	printf("-------> %d", len);
	printf("\n");
}
