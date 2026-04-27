#ifndef MINRT_H
#define MINRT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minilibx-linux/mlx.h"
#include "../src/libft/libft.h"

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    int     wdh;
    int     hgt;
}   t_mlx;

#endif
