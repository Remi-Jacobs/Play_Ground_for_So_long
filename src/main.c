
#include "../inc/so_long.h"


// int main(int argc, char **argv)
// {
//     t_game game;

//     if (argc != 2)
//     {
//         write(2, "Usage: ./so_long <map_file.ber>\n", 32);
//         return (1);
//     }
//     init_game(&game);
//     load_map(&game, argv[1]);
//     game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE, game.map_height * TILE_SIZE, "so_long");
//     render_map(&game);
//     mlx_key_hook(game.win, key_hook, &game);
//     mlx_hook(game.win, 17, 0, close_game, &game); // Handle window close
//     mlx_loop(game.mlx);
//     return (0);
// }