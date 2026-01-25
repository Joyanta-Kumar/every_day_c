# Random number generator  

For now, it only deals with integers. Float will come gradually.

## How to run it

First, compile it and then,  

```sh
./randint -b [bottom] -t [top]
```
or  
```sh
./randint --bottom [bottom] --top [top]
``` 

## Next plan  
- add a third parameter `count` to get multiple random number. (Now I thing it is useless)
- use named parameter like this: `--start`, `--end`, `--count`
- parameters should not be mendatory.
- if no start and end: start = 0 and end = MAX_INT  

hopefully I have done all that.
