#include "../includes/so_long.h"

int key_press(int keycode)
{
    if (keycode == 53 || keycode == 65307)
        exit(0);
    return (0);
}

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        logex("Invalid number of arguments");
    game.map = malloc(sizeof(t_map));
    if (!game.map)
        logex("Memory allocation failed");
    read_map(game.map, argv[1]);
    check_map(game.map);
    check_path(game.map);
    ft_printf("Map validation successful!\n");
    init_graphics(&game);
    mlx_key_hook(game.display->win, key_press, &game);
    mlx_hook(game.display->win, 17, 0, close_window, &game);
    mlx_loop(game.display->mlx);
    return 0;
}
