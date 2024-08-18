#include <mlx.h>
#include <stdio.h>

int key_press(int keycode, void *param)
{
    (void)param; // unused parameter
    printf("Keycode: %d\n", keycode);
    return (0);
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Keycode Finder");

    mlx_hook(win, 2, 1L<<0, key_press, NULL);
    mlx_loop(mlx);

    return (0);
}
