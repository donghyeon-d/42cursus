/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:53:02 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:42:40 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "type.h"
# define TRUE 1
# define FALSE 0
# define LEFT 1
# define RIGHT 2
# define NO_ECHO 1
# define YES_ECHO 0

int				g_status;

// paircheck.c
int				parentheses_pair_check(char *input);
int				parentheses_pair_long(char *input);
int				quote_pair_long(char *input);

// error.c
void			print_error_exit(t_error error);
void			syntax_error_exit(void);
void			custom_error(t_cmd *cmd, char *line, int flag);

// split_input.c
int				get_word_cnt(char *input);
char			**split_input_to_word(char *input);
void			input_to_word(char *input, char **word, int word_cnt);
int				get_word_len(char *input);

// token.c
void			define_type(t_token_node *token, char *word);
t_token			*word_to_token(char **word);

// syntax.c
int				syntax_check(t_token *token);
int				is_type_delimiter(t_token_node *node);
int				is_type_words(t_token_node *node);
int				is_type_parenthesis(t_token_node *node);
int				check_parenthesis_pair(t_token_node *node);

// utils.c
int				ft_strsame(char *s1, char *s2);
char			*ft_strndup(char *s1, int len);
int				ft_strlen(char *s);
char			*ft_strdup(char *s1);
void			*ft_calloc(int count, int size);
void			*ft_memset(void *b, int c, int len);
char			*ft_strjoin_with_space(char *s1, char *s2);
char			*ft_strjoin_with_c(char *s1, char *s2, char c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strrchr_idx(char *s, int c);
int				ft_isalpha(int c);
int				ft_isempty(char *line);
int				ft_strncmp(char *s1, char *s2, int n);
void			ft_strcpy(char *dst, char *src);
char			**ft_split(char const *s, char c);

// token_list.c
t_token			*create_token(void);
t_token_node	*create_token_node(char *data);
void			token_add_back(t_token *token, t_token_node *node);
t_token_node	*token_pop_front(t_token *token);
void			del_token(t_token **token);

// tree_traversal.c
void			traversal_print(t_tree_node *node);
void			traversal_fucn(t_tree_node *root, void (*fp)(t_tree_node **));
void			traversal_cmd_set(t_tree_node *root, t_cmd *cmd);

// token_to_tree.c
t_tree			*make_token_tree(t_token *token);
void			split_token_tree(t_tree_node *node);
void			token_to_child(t_tree_node *parent, t_token_node *node, int d);
void			split_left_node(t_tree_node *node);
void			split_left_rdr(t_tree_node *node);

//split_token_tree.c
void			add_and_split(t_tree_node *node, t_token_node *node_token);
void			split_token_tree(t_tree_node *node);

//expand_wildcard.c
void			expand_wildcard(t_token *token);

//expand_wildcard_utils.c
t_token_node	*make_wc_list(t_token_node *node);

//grammar_check.c
int				check_rdr(t_token_node *node);
int				check_pipe(t_token_node *node);
int				check_parenthesis(t_token_node *node);
int				check_quotes(t_token_node *node);

t_tree			*creat_tree(void);
t_tree_node		*creat_tree_node(void);

//del.c
void			del(t_tree **tree, t_token **token, char **input, t_cmd **cmd);
void			del_tree(t_tree **tree);
void			del_tree_node(t_tree_node **tree_node);
// void			del_token(t_token **token);
void			del_token_node(t_token_node **token_node);
void			del_word(char ***word);
void			del_cmd(t_cmd **cmd);

//expand_tilde.c
void			expand_tilde(t_token_node *node, t_env *env);

//expand_quotes_hhwang.c
int				count_quotes(t_token_node *node);
void			filling_quotesless(t_token_node *node, char *new);
void			expand_quotes(t_token_node *node);

//expand.c
void			expanding(t_token *token, t_env *env);

//signal.c
void			sigint_wait(int num);
void			sigquit_wait(int num);
void			sigint_insert(int num);
void			sigquit_insert(int num);
void			set_term_echoctl(int flag);
void			set_signal(void (*sig_int)(int), void (*sig_quit)(int));

// cmd_init.c
t_cmd			*create_cmd(t_env *env);
int				cmd_path_setting_cmd(t_cmd *cmd);
int				is_builtin(char *word);

// void			cmd_set_cmd(t_cmd *cmd, t_token *token);
void			cmd_set_rdr(t_cmd *cmd, t_token *token);
void			cmd_set_link(t_cmd *cmd, t_token *token);
void			cmd_set_argv(t_cmd *cmd, t_token *token);
void			cmd_set_pipe(t_cmd *cmd, t_token *token);
void			cmd_set_parenth(t_cmd *cmd, t_token *token);
void			cmd_set_num(t_cmd *cmd);
void			cmd_set_argc(t_cmd *cmd, t_token *token);
void			cmd_set(t_cmd *cmd, t_token *token);
void			heredoc_set(t_cmd *cmd, t_token *token);

// cmd_path.c  // 테스트 필요
char			*cmd_expand(char *cmd, t_env *env_list);
int				file_name_check(char *cmd, char *path);
int				file_exec_check(char *cmd_path);
int				cmd_valid_check(char *cmd_with_path);

// rdr_set.c  // 테스트 필요
void			rdr_set_stdin(t_cmd *cmd, t_token *token);
void			rdr_set_stdout(t_cmd *cmd, t_token *token);
void			rdr_set_append(t_cmd *cmd, t_token *token);
void			rdr_set_herdoc(t_cmd *cmd);//, t_token *token);
void			rdr_set_herdoc_open(t_cmd *cmd, t_token *token);
void			rdr_set_herdoc_read(t_cmd *cmd);//, t_token *token);

//env_list.c
t_env			*new_env(char *str, int len);
void			env_add_back(t_env *node, t_env *tmp);
void			env_pop(t_env **node, char *key);
void			del_env(t_env **node);
t_env			*create_env_list(char **env);
char			**envlist_to_str(t_env *env);

// built_in.c
int				execute_built_in(t_cmd *cmd, pid_t *last_pid);

int				ft_cd(t_cmd *cmd);
int				ft_pwd(t_cmd *cmd);
int				ft_export(t_cmd *cmd);
int				export_add_env(t_cmd *cmd, char *line);
int				key_and_value(t_cmd *cmd, char *line, int i);
int				key_check(char *line, int end);
int				ft_env(t_cmd *cmd);
int				ft_unset(t_cmd *cmd);
int				ft_exit(t_cmd *cmd);
int				ft_echo(t_cmd *cmd);

// ft_unset.c
void			env_pop(t_env **node, char *key);
void			del_env_one(t_env *del);
int				ft_unset(t_cmd *cmd);

// ft_atoi.c
int				ft_isspace(char c);
int				ft_isdigit(int c);
int				ft_atoi(char *str);
int				ft_count_number(int n);
char			*ft_itoa(int n);

//expand_env_hhwang.c
char			*ft_getenv(t_env *env, char *key);
int				expand_env(t_token_node *node, char *value, int i, int k);
int				match_env(t_token_node *node, t_env *env, int i);
void			find_env(t_token_node *node, t_env *env);

// execute_single.c
int				execute_parenthesis(t_cmd *cmd);
void			execute_pipe(t_cmd **cmd);
void			execute_or(t_cmd **cmd);
void			execute_and(t_cmd **cmd);

// main.c
t_token			*parsing(char *input);

int				execute_fork(t_cmd *cmd, int prev_in);
int				execute(t_cmd *cmd);
void			close_cmd_fd(t_cmd *cmd);
void			make_pipe(t_cmd *cmd);

void			wait_child(pid_t pid);
int				execute_multi_cmd(t_cmd *cmd, int pipe_read, pid_t *last_pid);
int				execute_single_cmd(t_cmd *cmd, pid_t *last_pid);
int				execute_os(t_cmd *cmd, pid_t *last_pid);
void			fd_setting(t_cmd *cmd);
void			ft_close(t_cmd *cmd);
int				execute_built_in_func(t_cmd *cmd);
int				execute_pipe_single_cmd(t_cmd *cmd);

void			wait_heredoc(void);
void			traversal_heredoc_set(t_tree_node *root, t_cmd *cmd);

void			wait_cmd(t_cmd *cmd);
int				execute_single(t_cmd *cmd);
void			unlink_tempfiles(t_cmd *cmd);
char			*take_off_parenthesis(char *str);

#endif
