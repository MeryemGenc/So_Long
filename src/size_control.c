#include "so_long.h"

void size_control(t_data *data) // map'in width & height değerlerini bulup, data struct'ına ekler
{
    int x;
    int y;
    int fd;
    char *line;

    y = 0;
    fd = open(data->tmp_map, O_RDONLY);
    line = get_next_line(fd);
    x = ft_strlen(line);
    while (1)
    {
        free(line);
        y++;
        line = get_next_line(fd);
        if (line[0] == '\0') // şöyle olamaz mı? -> if (!line)
            break;
        if (x != (int)ft_strlen(line) && line[0] != '\0') // buna gerek var mı? (line[0] != '\0') -> zaten NULL olsa buraya giremez ki di mi?
            err_msg("ERROR: Map is not rectangular.");
    }
    if (!line)
        free(line);
    data->map_height = y;
    data->map_width = x - 1;
    close(fd);
}

void wall_control(t_data *data) //map kenarları full duvarla çevrili mi kontrol eder.
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < data->map_width)  
        if (data->map[0][x++] != '1') // üst-yatay kenar kontrol
            err_msg("ERROR: The map has to be surrounded by walls."); 
    while (y < data->map_height) 
    {
        if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1'); // sol-dikey kenar & sağ-dikey kenar kontrol
            err_msg("ERROR: The map has to be surrounded by walls.");
        y++;
    }
    x = 0;
    while (x < data->map_width) 
        if (data->map[data->map_height - 1][x++] != '1'); // alt-yatay kenar kontrol
            err_msg("ERROR: The map has to be surrounded by walls.");  
}

void min_element_control(t_data *data) // map gerekli şekilde değilse => error + exit
{
    if (data->player_count != 1)
        err_msg("ERROR: There must be 1 player on the map.");
    if (data->exit_count != 1)
        err_msg("ERROR: There must be 1 exit on the map.");
    if (data->coin_count < 1)
        err_msg("ERROR: Must have at least 1 collectible on the map.");
    if (data->wall_count < 12)
        err_msg("ERROR: Missing wall count on the map.");
    if (data->unwanted_char_count != 0)
        err_msg("ERROR: There are unwanted character on the map.");
}