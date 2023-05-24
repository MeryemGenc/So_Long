#include "so_long.h"

void err_msg(char *message)
{
    ft_printf("%s", message);
    exit(0);
}

int mouse_hook(int mousecode, t_data *data)
{
    (void)mousecode;   // kullanmayacaksak neden bu değişkenleri parametre olarak aldık?
    (void)data;
    err_msg("Exit Success!");
    return (0);
}

int exit_door(t_data *data)
{
    if (data->collected_coin == data->coin_count)
    {
        ft_printf("\nToplam hamle: %d\n", data->step_count);
        err_msg("FINISH!");
    }
    else if (data->collected_coin != data->coin_count)
        return (1);
    else
        ft_printf("Sorry! You can't exit.");
    return (0);
}

int main(int argc, char **argv)
{
    t_data *data;

    if (argc != 2)
        err_msg("Error: 2 argument required..");
    map_control(argv, &data);
    size_control(&data);
    mlx_create(&data);
}


