<h1 align=center>
	<b>fdf</b>
</h1>

<h2 align=center>
	 <i>42cursus' project #5</i>
</h2>

<p align=center>
	The <b>fdf</b> program is a wireframe 

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

> <i>A small description of the required conversion:
> - `%c` print a single character.
> - `%s` print a string of characters.
> - `%p` The void * pointer argument is printed in hexadecimal.
> - `%d` print a decimal (base 10) number.
> - `%i` print an integer in base 10.
> - `%u` print an unsigned decimal (base 10) number.
> - `%x` print a number in hexadecimal (base 16).
> - `%%` print a percent sign.</i>

<h3 align=center>
Bonus
</h3>

> <i>Manage any combination of the following flags: 
> - `-0.` and minimum field width with all conversions
> - Manage all the following flags: `# +`(yes, one of them is a space)<i>

---

<h2>
The project
</h2>

### Implementation files
	
- [`Makefile`](Makefile)
- [`libft functions`](libft/)
- [`header file`](include/libftprintf.h)

Main functions
	
- [`ft_printf.c`](srcs/ft_printf.c)
- [`ft_initialize.c`](srcs/ft_initialize.c)
- [`ft_placeholder.c`](srcs/ft_placeholder.c)
- [`ft_parse.c`](srcs/ft_parse.c)
- [`ft_conversion.c`](srcs/ft_conversion.c)

Conversion functions

- [`ft_convert_c.c`](srcs/ft_convert_c.c)
- [`ft_convert_d_i.c`](srcs/ft_convert_d_i.c)
- [`ft_convert_p.c`](srcs/ft_convert_p.c)
- [`ft_convert_pct.c`](srcs/ft_convert_pct.c)
- [`ft_convert_s.c`](srcs/ft_convert_s.c)
- [`ft_convert_ux.c`](srcs/ft_convert_ux.c)

### Conversions & Flags & Expected Order

| Conversion  | Description														 			| Project 		|
|-------|-----------------------------------------------------------------------------------|---------------|
| **c** | Single ascii character         													|Mandatory		|
| **s** | String of characters NULL terminated												|Mandatory		|
| **p** | Pointer location converted to hexadecimal value									|Mandatory		|
| **d** | Decimal number 																	|Mandatory		|
| **i** | Integer in decimal base                 											|Mandatory		|
| **u** | Unsigned integer in decimal base                									|Mandatory		|
| **x** | Unsigned number printed in lowercase hexadecimal base                				|Mandatory		|
| **X** | Unsigned number printed in uppercase hexadecimal base                				|Mandatory		|
| **%** | The '%' ascii character                 											|Mandatory		|
| **o** | Unsigned number printed in octal base                 							|Extra			|

| Flag  | Description														 				| Project 		|
|-------|-----------------------------------------------------------------------------------|---------------|
| **-** | Left align the argument passed	         										|Bonus 1		|
| **0** | Add '0' as a padding character in numeric conversions (single space is default)	|Bonus 1		|
| **.** | Precision definition, followed by a number 										|Bonus 1		|
| **+** | Add a plus sign ('+') in the front of positive numeric conversions 				|Bonus 2		|
| **' '** | Add a single space (' ') in the front of positive numeric conversions 			|Bonus 2		|
| **#** | Add the corresponding prefix in front of x, X and o conversions                 	|Bonus 2		|
| **\*** | Add a placeholder for numeric values that shall be passed through the variadic arguments  |Extra			|


| Holder key  | Prefix and justification flags *| Minimum Width *| Precision *	| Conversion 	|
|-------------|---------------------------------|---------------|---------------|---------------|
|`%`		  | `-` , `0` , `+` ,  ...			| `10`, `5` , ... | `.`, `.10`, `.5`, ... | `c`, `d`, `i`, `s`, ... |  

##### * : optional flags and definitions

---
<h2>
Usage
</h2>

### Requirements
`libftprintf` requires a *gcc* compiler and some standard libraries.

### Instructions

Clone this repository in your local computer:

```sh
$> git clone https://github.com/caroldaniel/42sp-cursus_libft.git path/to/libftprintf
```

In your local repository, run `make`

```sh
$> make 
```

> `make` suports 6 flags: 
> - `make all` or simply `make` compiles printf in its mandatory format
> - `make bonus` compiles printf in its bonus format
> - `make clean` deletes the `.o` files generated during compilation
> - `make fclean` deletes the `.o` and the `libftprintf.a` library file generated
> - `make re` executes `fclean` and `all` in sequence, recompiling the library
> - `make rebonus` executes `fclean` and `bonus` in sequence, recompiling the library with the bonus functions

To use the libftprintf in your code you will need to include the header:
```c
#include "libftprintf.h" 
```

When compiling your own code with `libftprintf`, don't forget to use the flags:
```sh
$> ... -lftprintf -L path/to/libftprintf.a -I path/to/libftprintf.h 
```
