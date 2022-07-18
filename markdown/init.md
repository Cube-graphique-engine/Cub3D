# Welcome to the Cub3D wiki!

<h3>INITIALISATION</h4>

<p>Déclaration des structures:</p>

```c
t_game      *game;
t_map       *map;
t_texture   *texture;
t_player    *player;
t_window    *window;
t_image     *images...;
```

<h3>Initialisation des structures:</h3>

<p style="text-align: center">Initialisation de la structure principal <code>t_game *</code><br>
Cette fonction va initialiser toutes les autres structures car la structure t_game* contient tous les autres structures</p>

```c
//src/init_main_struct.c
t_game 	*init_main_struct(void);

//HOW TO BE USE
t_game *game;

game = init_main_struct();
```

<p style="text-align: center; font-size: medium">Initialisation des différentes structures:</p>
<p>Structure <code>t_map *</code><br>
mise à la valeur NULL de toutes les valeurs nécessaires</p>

```c
//src/init_main_struct.c
t_map	*init_map_struct(void);

//HOW TO BE USE
t_map *map;

map = init_map_struct();
//For game struct
game->map = init_map_struct();
```

<p>Structure <code>t_texture *</code><br>
mise à la valeur NULL de toutes les valeurs nécessaires</p>

```c
//src/init_main_struct.c
t_texture	*init_texture_struct(void);

//HOW TO BE USE
t_texture	*texture;

texture = init_texture_struct();
//For game struct
game->texture = init_texture_struct();
```

<p>Structure <code>t_player *</code><br>
mise à la valeur NULL de toutes les valeurs nécessaires</p>

```c
//src/init_main_struct.c
t_player	*init_player(void);

//HOW TO BE USE
t_player	*player;

texture = init_player();
//For game struct
game->player = init_player();
```

<p style="text-align: center; font-size: medium">Initialisation des structures spécialement utilisée par la mlx <br>
leur initialisation se fait par le biais de la librairie bettermlx</p>

<p>Structure <code>t_window *</code><br>
mise à la valeur NULL de toutes les valeurs nécessaires</p>

```c
t_window *bettermlx_init_window((char*)"name", (int)widht, (int)height, (int)divider);

//HOW TO BE USE
t_window *window;

window = bettermlx_init_window("Cub3D", WIN_WIDTH, WIN_HEIGHT, WIN_DIVIDER);
//For game struct
game->window = bettermlx_init_window("Cub3D", WIN_WIDTH, WIN_HEIGHT, WIN_DIVIDER);
```

<p>Structure <code>t_image *</code><br>
mise à la valeur NULL de toutes les valeurs nécessaires</p>

```c
t_image *bettermlx_init_xpm_image((t_window*), (char*)path);

//HOW TO BE USE
t_image *image;

image = bettermlx_init_xpm_image(window, path);
//For game struct
game->image = bettermlx_init_xpm_image(window, path);
```