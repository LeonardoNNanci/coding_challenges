# Rails

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/1062).

### Solution

Use queues to represent directions A and B and stack to represent the station.
- If A's first coach is the next desired one, it can move to B, passing through the station
- Otherwise, move coaches from A to the station until the first coach in A is the desired one or A is empty.
- If the top coach in the station is the desired one, move it to B.
- Otherwise, move from A to the station, if A is not empty. If it is empty, there is no solution.