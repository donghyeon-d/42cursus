#include <stdlib.h>
#include "stack.h"
#include "c.h"

// () 체크
// () 사이에 "" '' 있는지 체크
// "" 사이에 ' 있으면 무시, '' 사이에 " 있으면 무시


// 괄호 시작되는 지점에서 input 넘겨주기
// (부터 )까지의 길이 반환해주기
// "" 안에 있는 ) 는 무시함
// int	parentheses_pair_long(char *input)
// {
// 	int	input_len;
// 	int	i;

// 	if (input == NULL)
// 		return (-1);
// 	input_len = ft_strlen(input);
// 	i = 0;
//     while (++i < input_len)
//     {
//         if (input[i] == ')')
//             break ;
//         else if (input[i] == '\"')
//         {
//             while (input[++i] != '\"' && i < input_len)
//                 ;
//         }
//         else if (input[i] == '\'')
//         {
//             while (input[++i] != '\'' && i < input_len)
//                 ;
//         }
//     }
//     if (i >= input_len)
//         i = -1;
//     return (i);
// }

// 괄호 시작되는 지점에서 input 넘겨주기
// (부터 )까지의 길이 반환해주기
// "" 안에 있는 ) 는 무시함
int	parentheses_pair_long(char *input)
{
	int	input_len;
	int	i;

	if (input == NULL)
		return (-1);
	input_len = ft_strlen(input);
	i = 0;
    while (++i < input_len)
    {
        if (input[i] == ')')
            break ;
        else if (input[i] == '\"' || input[i] == '\'')
            i += quote_pair_long(&input[i]);
    }
    if (i >= input_len)
        print_error_exit(parentheses);
    return (i);
}

// "의 시작 지점에서 함수 호출, "가 끝나는 지점까지의 길이 반환, 못찾으면 -1
// "" 안에 있는 ' () 는 무시함(그냥 문자로 취급함)
int quote_pair_long(char *input)
{
	int	input_len;
	int	i;

	if (input == NULL)
		return (-1);
	input_len = ft_strlen(input);
	i = 0;
    if (input[i] == '\"')
    {
        while (input[++i] != '\"' && i < input_len)
            ;
    }
    else if (input[i] == '\'')
    {
        while (input[++i] != '\'' && i < input_len)
            ;
    }
    if (i >= input_len)
        print_error_exit(quote);
    return (i);
}
