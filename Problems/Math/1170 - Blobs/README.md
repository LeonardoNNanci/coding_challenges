# Blobs

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1170).

### Solution

Since the food is halved at every day:

- $\frac{total}{2^n}$ = food remainig

To find when it reaches 1 or less:

- $\frac{total}{2^n}$ <= 1

To get n:

- total <= 2<sup>n</sup>
- n <= log<sub>2</sub>(total)