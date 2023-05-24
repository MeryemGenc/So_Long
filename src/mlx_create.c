#include "so_long.h"

void    image_create(t_data *data) // terminal üzerinde görselleri oluşturmayı sağlar
{
    data->img.bg = mlx_xpm_file_to_image(data->mlx, "img/background.xpm", &data->img.img_width, &data->img.img_height);
    data->img.coin = mlx_xpm_file_to_image(data->mlx, "img/coin.xpm", &data->img.img_width, &data->img.img_height);
    data->img.wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &data->img.img_width, &data->img.img_height);
    data->img.door = mlx_xpm_file_to_image(data->mlx, "img/door.xpm", &data->img.img_width, &data->img.img_height);
    data->img.character = mlx_xpm_file_to_image(data->mlx, "img/character.xpm", &data->img.img_width, &data->img.img_height);
}

void map_read(t_data *data) // map için alan ayırma + bu alanda (.ber dosyası ile) map'i oluşturma
{
    int i;
    int j;
    int fd;
    char *area;

    i = 0;
    j = 0; // burada atamaya gerekvar mı? zaten döngüde atama yapılıyor. 
    fd = open(data->tmp_map, O_RDONLY);
    data->map = (char **)malloc(sizeof(char *) * data->map_height);
    while (i < data->map_height)
    {
        j = 0;
        area = get_next_line(fd);
        data->map[i] = (char *)malloc(sizeof(char) * data->map_width);
        if (area == NULL) // "!area" olma mı?
            break;
        while (j < data->map_width)
        {
            data->map[i][j] = area[j];
            j++; // bu arttırmayı 1 üst satırda yapsak olma mı?
        }
        data->map[i][j] = '\0';
        i++;
        free(area);
    } 
}

static void data_init(t_data *data) // data struct'ının başlangıç için değerlerini atıyor.
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->map_width * IMG_SIZE, data->map_height * IMG_SIZE, "SoLong");
    data->coin_count = 0;
    data->collected_coin = 0;
    data->step_count = 0;
    data->exit_count = 0;
    data->wall_count = 0;
    data->player_count = 0;
    data->unwanted_char_count = 0;
}

void    mlx_create(t_data *data) // başlangıç işlemlerini gerçekleştirdikten sonra; map-wall-element kontrolünü yapar, terminal üzerinde görüntülemeyi başlatır, ve oyun döngüsünü(oyunu) başlatır. 
{
    data_init(data);
    image_create(data);
    map_read(data);
    map_background_put(data);
    map_create(data);
    wall_control(data);
    min_element_control(data);
    placeholder(data, data->exit_x, data->exit_y);
    if (data->i_map.read_count != data->coin_count + 1)
        err_msg("ERROR: Map is wrong.");
    hook(data);
    mlx_loop(data->mlx);
}