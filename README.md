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
> - Rotate map.</i>

---

<h2>
The project
</h2>

<img width="850px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/ead93a55e9f08f84a0dae6b4a7f090daa94248f8/images/FdF-42.gif alt="FdF"/>
	
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

#### Different projections

By pressing `I`, `O` and `P` keys on your keyboard, you will switch projection views to `Isometric`, `Top View` and `Perspective`, respectively. 

<figure>
<figcaption><i>Isometric View</i></figcaption>
<img width="400px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/a51b587e91e3ce6a41f74fc6ab785815eb21375e/images/FdF-isometric.png alt="FdF isometric"/>
</figure>
<figure>
<figcaption><i>Top View</i></figcaption>
<img width="400px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/507d616345c7eeadcd809c6631efe0c854452218/images/FdF-topview.png alt="FdF Top View"/>
</figure>
<figure>
<figcaption><i>Perspective View</i></figcaption>
<img width="400px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/507d616345c7eeadcd809c6631efe0c854452218/images/FdF-perspective.png alt="FdF Perspective"/>
</figure>

#### Scaling Z

By pressing `Z` or `X`, you can decrease or increse, respectively, de `Z Scale Factor` on your map, maxing out at 100% on either direction.
<figure>
<figcaption><i>Z Scaling</i></figcaption>
<img width="400px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/f81a99491d039091eb10d1ded284f61f689846eb/images/FdF-ScaleZ.gif alt="FdF isometric"/>
</figure>

#### Zoom

By pressing `-` or `+`, you can `Zoom Out` and `Zoom In`, respectively.
<figure>
<figcaption><i>Zoom Out</i></figcaption>
<img width="400px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/f81a99491d039091eb10d1ded284f61f689846eb/images/FdF-ZoomOut.gif alt="FdF isometric"/>
</figure>
<figure>
<figcaption><i>Zoom In</i></figcaption>
<img width="400px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/f81a99491d039091eb10d1ded284f61f689846eb/images/FdF-ZoomIn.gif alt="FdF isometric"/>
</figure>

#### Rotate

By pressing `S` or `W`, you can `Rotate on the X axis`.
By pressing `Q` or `E`, you can `Rotate on the Y axis`.
By pressing `A` or `D`, you can `Rotate on the Z axis`.

<figure>
<figcaption><i>Rotate X</i></figcaption>
<img width="400px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/9d225d46980b24278e4dbefb3d4d6cfa39a7739f/images/FdF-RotateX.gif alt="FdF isometric"/>
</figure>
<figure>
<figcaption><i>Rotate Y</i></figcaption>
<img width="400px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/9d225d46980b24278e4dbefb3d4d6cfa39a7739f/images/FdF-RotateY.gif alt="FdF isometric"/>
</figure>
<figure>
<figcaption><i>Rotate Z</i></figcaption>
<img width="400px" src=https://github.com/caroldaniel/42sp-cursus-fdf/blob/9d225d46980b24278e4dbefb3d4d6cfa39a7739f/images/FdF-RotateZ.gif alt="FdF isometric"/>
</figure>

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
