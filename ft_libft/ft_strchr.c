/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:15:33 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/24 10:24:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*locate;

	if (s == NULL)
		return (NULL);
	locate = (char *)s;
	while ((char)*locate != (char)c && *locate != '\0')
		locate++;
	if (*locate == '\0' && c != '\0')
		return (NULL);
	return (locate);
}
