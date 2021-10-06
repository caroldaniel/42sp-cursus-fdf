<h1 align=center>
	<b>fdf</b>
</h1>

<h2 align=center>
	 <i>42cursus' project #5</i>
</h2>

<p align=center>
	The <b>fdf</b> program is a wireframe generator that takes .fdf format files and transforms them into tridimensional representations of relief landscapes. It manages colors and basic transformation, such as zoom, translation, rotation and Z axis scaling. This project aims for the student to get familiarized with window management and pixel insertion on screen, using <i>MinilibX</i> library and pure C coding.  

---
<div align=center>
<h2>
	Final score
</h2>

</div>

---

<h3 align=center>
Mandatory
</h3>

> <i> fdf <b>must</b> have: 
> - isometric projection;
> - Exiting of screen by pressing 'ESC';
> - Use of MinilibX's 'images' is strongly reccomended.</i>

<h3 align=center>
Bonus
</h3>

> <i> fdf <b>can</b> have: 
> - Extra projections; 
> - Zoom in and map translation;
> - Rotate map.<i>

---

<h2>
The project
</h2>

<img width="800px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/cedf0153543ddce81fef1b5e5953d8dd40485ea1/images/FdF.png alt="FdF"/>
	
### Implementation files
	
- [`Makefile`](Makefile)

Header files
- [`fdf.h`](include/fdf.h)
- [`keys.h`](include/keys.h)
- [`colors.h`](include/colors.h)

Main function	
- [`main.c`](srcs/main.c)

Initialization
- [`init.c`](srcs/init.c)
- [`init_utils.c`](srcs/init_utils.c)
- [`utils.c`](srcs/utils.c)

Parsing and reading
- [`read.c`](srcs/read.c)

Render and drawing
- [`render.c`](srcs/render.c)
- [`draw.c`](srcs/draw.c)
- [`menu.c`](srcs/menu.c)
- [`color.c`](srcs/color.c)

Transformation and projections
- [`rotate.c`](srcs/rotate.c)
- [`transform.c`](srcs/transform.c)
- [`project.c`](srcs/project.c)

Key handling
- [`key_handle.c`](srcs/key_handle.c)

Error management and program closing
- [`error.c`](srcs/error.c)
- [`close.c`](srcs/close.c)

### Features

It was, ultimately, very hard not to extrapolate this project scope and go any further in implementing more functions, interactivity and color pallets. At some point, though, we had to stop. 

For this implementation we chose to deal with all the mandatory requirements, all the bonus requirements and some bonus' bonuses, such as color gradients, top view and Z axis scaling.

<img width="300px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/a51b587e91e3ce6a41f74fc6ab785815eb21375e/images/FdF-isometric.png alt="FdF isometric"/>
<img width="300px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/507d616345c7eeadcd809c6631efe0c854452218/images/FdF-topview.png alt="FdF Top View"/>
<img width="300px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/507d616345c7eeadcd809c6631efe0c854452218/images/FdF-perspective.png alt="FdF Perspective"/>

#### Different projections

By pressing `I`, `O` and `P` keys on your keyboard, you will switch projection views to `Isometric`, `Top View` and `Perspective`, respectively. 

---
<h2>
Usage
</h2>

### Requirements
`fdf` requires a *gcc* compiler, MinilibX, X-Window and some standard libraries. At the moment, this particular project runs only on Ubuntu systems. 

### Instructions

Clone this repository in your local computer:

```sh
$> git clone https://github.com/caroldaniel/42sp-cursus_libft.git path/to/fdf
```

In your local repository, run `make`

```sh
$> make 
```

> `make` suports 9 flags:
> - `make install` makes sure your system has all the prerequisites for running the program
> - `make all` or simply `make` compiles fdf in its mandatory format
> - `make bonus` compiles fdf in its bonus format
> - `make clean` deletes the `.o` files generated during compilation
> - `make fclean` deletes the `.o` and the `fdf` file generated
> - `make re` executes `fclean` and `all` in sequence, recompiling the program
> - `make rebonus` executes `fclean` and `bonus` in sequence, recompiling the program with the bonus functions
> - `make leaks` executes valgrind to check for any possible leaks and puts it into a log file
> - `make cleanleaks` cleans the leaks log file

To run `fdf`, type:
```sh
./fdf maps/<choose-your-map.fdf>
```
