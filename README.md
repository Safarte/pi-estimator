# Pi Estimator

Simple C program to approximate pi up to the n-th digit using the MPFR library and the Bailey–Borwein–Plouffe formula.

Based on an exercise from the [Modern C](https://modernc.gforge.inria.fr/) book by Jens Gustedt.

## Usage

To build the tool run:

```shell
make
```

To compute pi up to the n-th digit run:

```shell
./pi [n]
```

Example: compute pi up to the 50-th digit:

```shell
./pi 50
Pi=3.14159265358979323846264338327950288419716939937510
```
