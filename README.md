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

><i> - isometric projection;
> - Exiting of screen by pressing 'ESC';
> - Use of MinilibX's 'images' is strongly reccomended.</i>

<h3 align=center>
Bonus
</h3>

><i> - Extra projection; 
> - Zoom in and map translation;
> - Rotate map.<i>

---

<h2>
The project
</h2>

### Implementation files
	
- [`Makefile`](Makefile)

Main functions
	
- [`ft_printf.c`](srcs/main.c)

Parsing functions

- [`ft_convert_c.c`](srcs/read.c)


### Features

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

> `make` suports 7 flags:
> - `make install` makes sure your system has all the prerequisites for running the program
> - `make all` or simply `make` compiles fdf in its mandatory format
> - `make bonus` compiles fdf in its bonus format
> - `make clean` deletes the `.o` files generated during compilation
> - `make fclean` deletes the `.o` and the `fdf` file generated
> - `make re` executes `fclean` and `all` in sequence, recompiling the program
> - `make rebonus` executes `fclean` and `bonus` in sequence, recompiling the program with the bonus functions

To run `fdf`, type:
```sh
./fdf maps/<choose-your-map.fdf>
```