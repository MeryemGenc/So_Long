#include "so_long.h"

static void recur_func(int **int_map, t_data *data, int x, int y) // komple anlamadım?
{
    if (data->map[y][x] == 'P' || data->map[y][x] == 'C')
        data->i_map.read_count++;
    if (data->map[y][x + 1] != '1' && int_map[y][x] < 1)
    {
        int_map[y][x + 1] = int_map[y][x] + 1;
        recur_func(int_map, data, x + 1, y);
    }
    if (data->map[y+ 1][x] != '1' && int_map[y + 1][x] < 1)
    {
        int_map[y + 1][x] = int_map[y][x] + 1;
        recur_func(int_map, data, x, y + 1);
    }
    if (data->map[y][x - 1] != '1' && int_map[y][x - 1] < 1)
    {
        int_map[y][x - 1] = int_map[y][x] + 1;
        recur_func(int_map, data, x - 1, y);
    }
    if (data->map[y - 1][x] != '1' && int_map[y - 1][x] < 1)
    {
        int_map[y - 1][x] = int_map[y][x] + 1;
        recur_func(int_map, data, x, y - 1);
    }
}

static void print(t_data *data, int **int_map)
{
    int x;
    int k;

    x = 0;
    k = 0; // nedennnnnn nedennnnnnn?
    if (1) // +3125 nedennnnnnnnnnnnnn
    {
        if (data->i_map.read_count == data->coin_count + 1)
            ft_printf("\n\n********* MAP OK ***********");
        ft_printf("\n********* Collected-Available: %d", data->i_map.read_count); // burada ne anlatılmak istenmektedir?
        ft_printf("\n******* VIRTUAL MAP *******\n");
        while (x < data->map_height)
        {
            k = 0;
            ft_printf("\n");
            while (k < data->map_width)
            {
                ft_printf("%d ", int_map[x][k]);
                k++;
            }
            x++;
        }
        ft_printf("\n\n");
    }
}

static void int_map_free(int **int_map, t_data *data)
{
    int i;

    i = 0;
    while (i < data->map_height)
    {
        free(int_map[i]);
        i++;
    }
    free(int_map);
}

void placeholder(t_data *data, int x, int y)
{
    int **int_map;
    int i;
    int j;

    i = 0;
    j = 0;
    int_map = (int **)malloc(sizeof(int *) * data->map_height);
    while (i < data->map_height)
    {
        int_map[i] = (int *)malloc(sizeof(int) * data->map_width);
        j = 0;
        while (j < data->map_width)
        {
            int_map[i][j] = 0;
            j++;
        }
        i++;
    }
    int_map[y][x] = 1;
    data->i_map.read_count = 0;
    recur_func(data, int_map, x, y);
    print(data, int_map);
    int_map_free(int_map, data);
}