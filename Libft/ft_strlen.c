/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencali <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:40 by mgencali          #+#    #+#             */
/*   Updated: 2022/10/27 14:06:20 by mgencali         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a])
	{
		a++;
	}
	return (a);
}
/*
int main()
{
    char a[] = "hshjhkjhsaaaaa";
    char b[3];

    printf("%d",ft_strlen(a));
    return 0;
} */
