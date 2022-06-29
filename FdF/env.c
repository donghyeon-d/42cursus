#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include "c.h"

t_env *init_env(void)
{
	t_env	*new_env;

	new_env = ft_calloc(1, sizeof(t_env));
	new_env->angle_radian = 0.5;
	new_env->distance = 10;
}