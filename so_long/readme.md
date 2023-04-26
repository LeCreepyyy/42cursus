# so_long

## Description :
So_long is my first graphic projet in language C.
This objectif is create a little puzzle game with item,
start, end and player.
For finish the game you must take all item dans go to exit.
Witch MLX42 library we can create graphic interface.


## Using :

### - Compile and run :
In your terminal enter:
```
make
```
for compile so_long program, and for launch it enter:
```
./so_long
```

### - Playing :

> UP = key W or ↑

> DOWN = key S or ↓

> LEFT = key A or ←

> RIGHT = key D or →

### - Finish :

> SUCCES FINISH : Take all gold and go to the end.

> FAILURE FINISH : Press ESCAPE.


## Code :

### - Get and Check the map :

In file we got map.txt and it looks like this:
```
1111111111111
1C010000000C1
1000011111001
1P0011E000001
1111111111111
```
- 1 = Wall

- 0 = Path

- C = Collectable (item)

- P = Player (start of the game)

- E = Exit

and with this map, we take it to translate this in the table of string (char **) with the function get_next_line.

With table of string we can check if map containt only 1, 0, C, E, P and check if had a border (1) and if is possible to succes.

For check if is possible to succeed we use the algorithm **D**eep **F**irst **S**earch (DFS)

It consists of creating a path beginning from the starting point and which will travel in the map to check all the possible paths. They are going to pass everywhere from the starting point and once he has covered everything, check if he got all the items and can go to the exit. If he can't take all item or go to exit, he return an error "Map is not possible".

To create this function we use the recursion. If he can go to the right, the left, up or down then he move. If he as blocked, so we check if he take all item and he as passing of the exit.
If it has not explored everything we go back to check if other paths exist and if no other path is possible then it is that everything has been explored.

```
(Current...)
```