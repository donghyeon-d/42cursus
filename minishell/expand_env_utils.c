/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhwang <hhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:04:24 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/14 15:27:59 by hhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

void	free_value_and_input(char *value, t_token_node *node)
{
	free(value);
	free(node->token);
}

int	expand_env(t_token_node *node, char *value, int i, int k)
{
	int		old_len;
	int		value_len;
	int		x;
	int		j;
	char	*new;

	if (value == NULL)
		value = ft_strdup("");
	value_len = ft_strlen(value);
	old_len = ft_strlen(node->token);
	new = (char *)malloc(sizeof(char) * (old_len + value_len - (k - i)));
	if (new == NULL)
		exit(1);
	x = -1;
	while (++x < i)
		new[x] = node->token[x];
	j = 0;
	while (j < value_len)
		new[x++] = value[j++];
	while (node->token[++k])
		new[x++] = node->token[k];
	new[x] = '\0';
	free_value_and_input(value, node);
	node->token = new;
	return (i + value_len - 1);
}

int	expand_exit_status(int i, t_token_node *node)
{
	char	*temp;

	temp = ft_itoa(g_status);
	i = expand_env(node, temp, i, i + 1);
	return (i);
}

int	get_end_point(int x, t_token_node *node)
{
	if (node->token[x] == ' ' || node->token[x] == '$'
		|| node->token[x] == '\'' || node->token[x] == '\"'
		|| node->token[x] == '(' || node->token[x] == ')'
		|| node->token[x] == '/')
		return (1);
	else
		return (0);
}

int	match_env(t_token_node *node, t_env *env, int i)
{
	int		x;
	int		j;
	int		k;
	char	*temp;
	char	*value;

	if (node->token[i + 1] == '?')
		return (expand_exit_status(i, node));
	x = i;
	k = i;
	while (node->token[++x])
		if (get_end_point(x, node))
			break ;
	x = x - i;
	temp = (char *)malloc(sizeof(char) * x);
	if (temp == NULL)
		exit(1);
	j = -1;
	while (++j < x - 1)
		temp[j] = node->token[++k];
	temp[j] = '\0';
	value = ft_getenv(env, temp);
	free(temp);
	i = expand_env(node, value, i, k);
	return (i);
}
