/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhwang <hhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:49 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/14 18:19:15 by hhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H
# include <unistd.h>

typedef enum e_type
{
	words = 0,
	parenth,
	squote,
	dquote,
	and,
	or,
	pipeline,
	rdr,
	null
}	t_type;

typedef enum e_errort
{
	quote = 0,
	parentheses,
	redirection,
	rdr_nofile,
	nocmd,
	no_delimiter
}	t_error;

typedef struct s_token_node
{
	char				*token;
	t_type				type;
	struct s_token_node	*next;
	struct s_token_node	*prev;
}	t_token_node;

typedef struct s_token
{
	int				cnt;
	t_token_node	*head;
}	t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_tree_node
{
	t_token				*token;
	int					visited;
	t_type				type;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree_node;

typedef struct s_tree
{
	t_tree_node	*root;
	int			node_cnt;
}	t_tree;

t_tree		*creat_tree(void);
t_tree_node	*creat_tree_node(void);

typedef struct s_cmd
{
	int				num;
	int				fd_in;
	int				fd_out;
	char			*cmd;
	int				argc;
	char			**argv;
	t_env			*env;
	t_type			link_type;
	int				pipe[2];
	pid_t			pid;
	int				status;
	int				is_builtin;
	int				is_parenthesis;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_info
{
	char	*input;
	t_token	*token;
	t_tree	*tree;
	t_env	*env;
	t_cmd	*cmd;
	int		status;
}	t_info;

#endif
