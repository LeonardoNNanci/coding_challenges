# Supermarket Line

### [Problem description](https://www.beecrowd.com.br/judge/en/problems/view/2065).

### Solution

Use a priority queue sorted by available timestamp, then by cachier id, to pick the first cashier available. Each time a client is attended, the cashier available timestamp is incremented by __v * c__. After all clients have been attended, print the timestamp of the last cashier in the priority queue.