/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:06:01 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 18:57:29 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../pushswap.h"

int	error_check(char *command);
void	excute_command(t_stack *stack_a, t_stack *stack_b,char *command);
int	checker(t_stack *stack_a, t_stack *stack_b, char *command);
int	ft_strncmp(const char *s1, const char *s2, int n);

#endif