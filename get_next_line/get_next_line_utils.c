/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansurcanatmaca <mansurcanatmaca@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:25:38 by matmaca           #+#    #+#             */
/*   Updated: 2024/04/14 17:52:35 by mansurcanat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_strjoin(char const *stack, char const *buffer)
{
	size_t	i;
	char	*new_str;

	if (!stack || !buffer)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(stack) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (*stack)
		new_str[i++] = *stack++;
	while (*buffer)
		new_str[i++] = *buffer++;
	new_str[i] = '\0';
	return (new_str);
}

void	*ft_free_stack(char **stack, int create_line)
{
	char	*line;

	if (!*stack)
		return (NULL);
	if (!create_line)
	{
		if (*stack)
		{
			free(*stack);
			*stack = NULL;
		}
		return (NULL);
	}
	else if (create_line)
	{
		line = ft_strdup(*stack);
		free(*stack);
		*stack = NULL;
		return (line);
	}
	return (NULL);
}
