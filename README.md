# Logic

**A new Language**

The grammar like this

* define functions

  * if-else style:

    `fib(x)=(x==1||x==2)?1:fib(x-1)+fib(x-2)`
    
  * piecewise style:
    
    ```
    fib(x)={
    	x==1||x==2:1
    	else:fib(x-1)+fib(x-2)
    }
    ```
  
* define variables
  
  `x=1+2`  

* lazy variables

  It likes lazy evaluation, but have a different

  * It's variable oriented, not expression oriented
  
  The code like this:
  
  `#x=1+2`
  
  In fact, it can do this:
  
  ```
  randseed = 0
  #randnum = (randseed ++)*2021 + randseed % 1000 + 324315
  ```