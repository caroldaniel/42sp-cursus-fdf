# gcc -Wall -Wextra -Werror srcs/*.c -lm -L./mlx_linux/ -lmlx -Llibft -lft -lXext -lX11 -o fdf
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./fdf maps/42.fdf