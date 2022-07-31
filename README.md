<h1 style="text-align: center"> 🎮 Cub3D 🖥️ </h1>

<p style="text-align: center">
  <a href="https://fr.wikipedia.org/wiki/MacOS_Mojave" target="_blank">
    <img  src="https://img.shields.io/badge/-MACOS_MOJAVE-C13584?style=for-the-badge&logo=apple&logoColor=white" alt="macos"/>
  </a>
  <a href="https://www.apple.com/fr/macos/" target="_blank">
		<img src="https://img.shields.io/badge/-MACOS_MONTEREY-C13584?style=for-the-badge&logo=apple&logoColor=white" alt="macos"/>
	</a>
  <a href="https://fr.wikipedia.org/wiki/C_(langage)" target="_blank">
    <img alt="language: c" src="https://img.shields.io/badge/language-C-purple?style=for-the-badge"/>
  </a>
  <a href="https://fr.wikipedia.org/wiki/OpenGL" target="_blank">
    <img alt="framework: opengl" src="https://img.shields.io/badge/framework-OpenGL-green?style=for-the-badge"/>
  </a>
  <a href="https://developer.apple.com/documentation/appkit" target="_blank">
    <img alt="framework: appkit" src="https://img.shields.io/badge/framework-AppKit-green?style=for-the-badge"/>
  </a>
  <a href="https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html" target="_blank">
    <img alt="library: minilibx" src="https://img.shields.io/badge/library-MiniLibX-orange?style=for-the-badge"/>
  </a>
  <a href="https://github.com/LoisDuplain/best-libft" target="_blank">
    <img alt="library: best-libft" src="https://img.shields.io/badge/library-best--libft-orange?style=for-the-badge"/>
  </a>
  <a href="https://profile.intra.42.fr/users/mathmart" target="_blank">
    <img alt="42 login: mathmart" src="https://img.shields.io/badge/42%20login-mathmart-2DD57B?style=for-the-badge"/>
  </a>
 <a href="https://profile.intra.42.fr/users/plavergn" target="_blank">
    <img alt="42 login: mathmart" src="https://img.shields.io/badge/42%20login-plavergn-2DD57B?style=for-the-badge"/>
  </a>
</p>

<p style="text-align: center; font-size: medium">
the goal is to create a 3D graphic representation
"realistic" that we could have within a
maze using a subjective view. us
must create this representation using the
principles of ray-casting.
</p>

- ✍🏻 Created by Mathis Martini and Pierre Lavergne.
- 📫 How to reach us: **contact@mathis-martini.fr** **pierre.lvrgn@gmail.com**.
- 📫 How to reach us in 42: **mathmart@student.42lyon.fr** or **plavergn@student.42lyon.fr**.
- 👨🏻‍💻 Login 42Intra: **mathmart** **plavergn**

<h3>🏗️ Compile</h3>

<p>To basically compile program:</p>

```bash
make
```

<p>To recompile entire program:</p>

```bash
make re
```

<p>To clean all *.o in project:</p>

```bash
make clean
```

<p>To clean all *.o and compiled things in project:</p>

```bash
make fclean
```

<p>To clean all *.o and compiled things in project and libraries:</p>

```bash
make clean_all
```
<p align="left">To check if the project meets the standard set by School 42:</p>

```bash
make norme
```

This is 42School norminette, check their work: <a href="https://github.com/42School/norminette">norminette repository</a>

<h3 align="left">▶️ Run</h3>
<p style="text-align: left">To basically run:</p>

```bash
./cub3D <map_path_1>                (default maps in ./maps folder)
```

<h3 align="left">🎮 Controls (QWERTY)</h3>

<p style="text-align: left">Player movement:</p>

```
W A S D
```

<p style="text-align: left">Camera rotation:</p>

```
▲ ▼ ► ◄
```

<h3 align="left">📝 Parsing</h3>

<p style="text-align: left">Walls:</p>

```
NO --> North Wall
SO --> South Wall
WE --> West Wall
EA --> East Wall
```

<p style="text-align: left">Floor/ceiling:</p>

```
F --> Floor
C --> Ceiling
```

<p style="text-align: left">Debug mod:</p>
<p style="text-align: center">the mod debug allows to put images to the varible F/C</p>

```
D
```

<p align="left">Map description:</p>

```
1     --> Wall
0     --> Walkable
Space --> Void
N/S/W/E (North / South / West / East) --> Player spawn point and direction

Example:
1111111111111
1000000000001
1000000000001
1001010101001
100000S000001
1001010101001
1000000000001
1000000000001
1111111111111
```

<h2 align="left">⚖️ Copyright
<img src="https://avatars.githubusercontent.com/u/109475065?s=400&u=63d86cfbf17df8ec0e4b3b889230b85c0c951076&v=4" width="20">
<a href="https://42lyon.fr"><img src="https://campusnumerique.auvergnerhonealpes.fr/app/uploads/2020/06/logo-noir-42-lyon.png" height=" 20"></a>
</h2>
<p align="left">
  Mathis Martini (mmartini42) © 2022
<br>
  Pierre Lavergne (plavergn) © 2022
</p>
