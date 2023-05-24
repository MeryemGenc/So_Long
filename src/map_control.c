#include "so_long.h"

void ber_control(char *map_name) // map uzantı (.ber) kontrol
{
    int len;

    len = ft_strlen(map_name) - 1;
    if (map_name[len] != 'r' || map_name[len - 1] != 'e' 
        || map_name[len - 2] != 'b' || map_name[len - 3] != '.')
        err_msg("ERROR: Map file is not '.ber'");
    if (!map_name)
        free(map_name);
}

void tmp_control(char *map_name) // map dosya var mı? kontrol
{
    int fd;

    fd = open(ft_strjoin("map/", map_name), O_RDONLY);
    if (fd == -1)
        err_msg("ERROR: File not found.");
    close(fd);
    if (!map_name)
        free(map_name);
}

void map_control(char **argv, t_data *data)
{
    char *map_name;
    char *map_path;

    map_name = argv[1];
    map_path = ft_strjoin("map/", map_name);
    data->tmp_map = map_path;
    free(map_path);
    ber_control(argv[1]); // argv[1] yerine -> map name kullanabilir miyiz?
    tmp_control(argv[1]); // argv[1] yerine -> map name kullanabilir miyiz?
}
