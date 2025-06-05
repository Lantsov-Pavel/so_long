 #include "../includes/so_long.h"

void game_off(t_game *game)
{
    int i;

    if (game->display->txr_wall)
        mlx_destroy_image(game->display->mlx, game->display->txr_wall);
    if (game->display->txr_ground)
        mlx_destroy_image(game->display->mlx, game->display->txr_ground);
    if (game->display->txr_player)
        mlx_destroy_image(game->display->mlx, game->display->txr_player);
    if (game->display->txr_collect)
        mlx_destroy_image(game->display->mlx, game->display->txr_collect);
    if (game->display->txr_exit)
        mlx_destroy_image(game->display->mlx, game->display->txr_exit); 
    mlx_destroy_window(game->display->mlx, game->display->win);
    i = 0;
    while (i < game->map->height)
        free(game->map->map[i++]);
    free(game->map->map);
    free(game->display);
    free(game->map);
    
    exit(0);
}

void    key_press(t_game *game, int k_code)
{ 
    t_map *map = game->map;
    if (k_code == 65307)
        game_off(game);
    else if(k_code = 65362)
        pl_move(game, map,0, -1);
    else if(k_code = 65361)
        pl_move(game, map, -1, 0);
    else if(k_code = 65364)
        pl_move(game, map, 0, 1);
    else if(k_code = 65363)
        pl_move(game, map, 1, 0);

}
void refresh_pos_player(t_game *game, t_map *map, int next_x, int next_y)
{
    map->map[map->pos_pl_y][map->pos_pl_x] = '0';
    map->pos_pl_x = next_x;
    map->pos_pl_y = next_y;
    map->map[next_y][next_x] = 'P';
    draw_map(game, 32);
}

void    pl_move(t_game *game, t_map *map, int x, int y)
{
    int next_x;
    int next_y;

    next_x = map->pos_pl_x + x;
    next_y = map->pos_pl_y + y;
    if (map->map[next_y][next_x] == '1')
        return ;
    game->moves++;
    if (map->map[next_y][next_x] == 'C')
    {
        game->collects++;
        map->map[next_y][next_x] = '0';
    }
    if (map->map[next_y][next_x] == 'E')
    {
        if(game->collects == map->collects)
        {   
            game_off(game);
        }
        return ;
    }
    refresh_pos_player(game, map, next_x, next_y);
}