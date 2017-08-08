# derangements
Randomly shuffle a vector of elements for [1, n] and check if it's a derangement. Run multiple trials and compare the results.

## Explanation

This simple program is inspired by the Derangements video by Numberphile on YouTube. I wanted to test how close the percentage of derangements to non-derangements when randomly shuffling a vector of 10 elements (or cards).

Numberphile defines a derangement as a permutation of elements where each element is a number, corresponding to an index. These indices are defined by the order in which the cards are placed down (after being shuffled). If none of the placed cards correspond to their index, then the permutation IS a derangement. Otherwise, it's not.

## Examples
The first row in each example is the index; the second row is the number on the "card", or the value of the chosen element.

*IS a derangement (win): no element corresponds to its own index*
```
1 2 3 4 5 6 7 8 9  10
3 5 4 8 6 7 9 2 10 1
```

*is NOT a derangement (loss): element placed at index 3 corresponds to its own index*
```
1 2 *3* 4 5  6 7 8 9 10
7 4 *3* 2 10 9 8 1 5 6
```

### Numberphile's YouTube Video, "Derangements - Numberphile"
<a href="http://www.youtube.com/watch?feature=player_embedded&v=pbXg5EI5t4c
" target="_blank"><img src="http://img.youtube.com/vi/pbXg5EI5t4c/0.jpg" 
alt="Derangements - Numberphile" width="480" height="360" border="10" /></a>
