## How fast does the harmonic series converge

I found this really interesting blog post by Nick Higham when I was googling about the difference
between binary fp16 and bfloat16. So I made a cpp code example to test it locally.

## Libs

Post: https://nhigham.com/2018/12/03/half-precision-arithmetic-fp16-versus-bfloat16/

bfloat16 impl: https://github.com/biovault/biovault\_bfloat16

half point precision: https://half.sourceforge.net/

## run
```
g++ main.cpp -Ihalf.hpp -Ibfloat16.h
./a.out
```
