# Custom Zork

This game is a test to access the master in Advanced Progamming for AAA Video Games.

## Plot
You are an explorer that has been assigned an important task. You need to deliver a precious Golden Idol to the temple it belongs to. It seems like an easy task, but it won't be that way...

## Map
The map has 9 rooms. In order to get to the temple, the player will have to pick items and choose the best (or safest) way to arrive to the temple.

You can [find the map here](https://github.com/magalenyo/zork/blob/master/zork/map/map.png)

![Map of Custom Zork](https://github.com/magalenyo/zork/blob/master/zork/map/map.png)

## Items
- **Idol**: the item that needs to get delivered to the temple. The player starts with this item.
- **Rock**: a small-regular size rock. Used to create noise and make go away creatures.
- **Berries**: juicy berries. This can restore some health after a good fight.
- **Key**: a rusty key. This can be used to open a house.
- **Backpack**: a basic backpack. You can store many items inside the backpack.
- **Sword**: sharpen sword. Use it to fight.
- **Coins**: shiny golden coins.

## Gameplay
The player can find different ways to get to the temple. Going through the wolves, or getting over the river, using the bridge.

The player can store only 2 items in the inventory, but can have the backpack in the inventory, and all the items inside the backpack.

| 1 Word commands| Action |
| --- | --- |
|Look / L | Exhaustive description of the environment |
|Direction (north / n, south /s, east / e, west / w, up / u, down / d) | Moves in a direction|
|Quit / Q | Quit the game |
|Inventory / I | Shows the inventory of the player |
|Fight | If possible, fights with the sword |
|Chances | Shows the chance of passing the river without the bridge breaking |
|Cross | Tries to cross the bridge|

| 2 Words commands| Action |
| --- | --- |
|Go Direction (north / n, south /s, east / e, west / w, up / u, down / d) | Moves in a direction|
|Take Item | Takes the item from the floor |
|Drop Item | Drops the item if the user has it in its inventory or backpack |
|Throw Rock | Throws a rock to make the wolves go away |
|Eat item | Tries to eat the item |

| 4 Words commands| Action | Example |
| --- | --- | --- |
|Take Item From Place | Tries to take the item from a given place | take idol from backpack (idol put previosuly in the backpack and backpack is in the floor) |
|Unlock Exit With Item | Tries to unlock the exit with the given item | unlock west with key |
|Put Item1 into Item2 | Tries to put Item1 into Item2 | put key into backpack |

## Endings
The user has different endings depending the gameplay style.
- The player can throw a rock away to make the wolves go away and free the path of the wolves to get to the temple.
- The player can fight the wolves, but will get damaged dies before getting to the temple. The user can avoid dying if eats berries before getting to the temple.
- The player can cross the bridge, but has a chance of success. The player reduces the chance of getting to the other side of the river when taking objects. The player can drop objects in order to have a higher chance of crossing the bridge.

If the player gets to the temple without the idol, it will die.

There are variations in the gameplay, in the section **TESTS** there are some examples.

[Link to my project repository](https://github.com/magalenyo/zork)

## References

[Repository given by UPC](https://github.com/d0n3val/zork)

[Repository found, author: Sergi Ledesma](https://github.com/SergiLedesma/ZorkProject)

[Zork Command List](https://zork.fandom.com/wiki/Command_List)

### Tests

#### The player gets to the temple throwing the rock and carries the idol.
w

take rock

e

e

n

n

throw rock


n

#### The player gets to the temple throwing the rock but loses the idol.
w

take rock

e

e

n

n

throw rock

drop idol

n

#### The player fights the wolves but doesn't eat berries, so it dies.
w

n

n

u

l

i

take key

take backpack

put idol into backpack

l

put key into backpack

l

take backpack

i

d

s

w

w

unlock west with key

w

l

put sword into backpack

i

e

e

e

e

n

fight

n

#### The player fights the wolves but eat berries and it doesn't die.
eat idol

w

n

n

u

l

i

take key

take backpack

put idol into backpack

l

put key into backpack

l

take backpack

i

d

put berries into backpack

s

w

w

unlock west with key

w

l

put sword into backpack

i

e

e

e

e

n

fight

eat berries

n


#### The player fights the wolves but eat berries and it doesn't die, but forgets the idol.
eat idol

w

n

n

u

l

i

take key

take backpack

put idol into backpack

l

put key into backpack

l

take backpack

i

d

put berries into backpack

s

w

w

unlock west with key

w

l

put sword into backpack

drop idol

i

e

e

e

e

n

fight

eat berries

n

#### The player tries to cross the bridge only with the idol (higher chance of surviving).
e

e

n

chances

cross


#### The player tries to cross the bridge only with the idol (lower chance of surviving).
w

n

n

u

l

i

take key

take backpack

put idol into backpack

l

put key into backpack

l

take backpack

i

d

put berries into backpack

s

w

w

unlock west with key

w

l

put sword into backpack

i

e

e

e

e

e

chances

take coins

chances

cross

*Author: Miguel Ángel Bueno Rivera*

*mail: magalenyo7@gmail.com*
