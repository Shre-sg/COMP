// Puzzle 14 | (Strategy for a 2 Player Coin Game)
// Last Updated : 10 Jul, 2024
// Puzzle: Consider a two-player coin game where each Player A and Player B gets the turn one by one. There is a row of even number of coins, and a player on his/her turn can pick a coin from any of the two corners of the row.  The player that collects coins with more value wins the game. Develop a strategy for the player making the first turn i.e, Player A, such that he/she never loses the game. Note that the strategy to pick a maximum of two corners may not work. In the following example, the first player, Player A loses the game when he/she uses a strategy to pick a maximum of two corners.

//  Example:

// Initial row:  18 20 15 30 10 14
// Player A picks 18, now row of coins is: 20,15,30,10,14

// After first pick:  20 15 30 10 14
// Player B picks 20, now row of coins is: 15,30,10,14

// After second pick:  15 30 10 14
// Player A picks 15, now row of coins is

// After third pick:  30 10 14
// Player B picks 30, now row of coins is

// After 4th pick:  10 14
// Player A picks 14, now row of coins is

// Last pick:  10
// Player B picks 10, game over.

// The total value collected by Player B is more (20 +
// 30 + 10) compared to first player (18 + 15 + 14).
// So the second picker, Player B wins.
// Solution: The idea is to count the sum of values of all even coins and odd coins, compare the two values. The player that makes the first move can always make sure that the other player is never able to choose an even coin if the sum of even coins is higher. Similarly, he/she can make sure that the other player is never able to choose an odd coin if the sum of odd coins is higher. So here are the steps to a proper algorithm of either winning the game or getting a tie:

// Step 1: Count the sum of all the coins in the even places(2nd, 4th, 6th and so on). Let the sum be “EVEN”.
// Step 2: Count the sum of all the coins in the odd places(1st, 3rd, 5th and so on). Let the sum be “ODD”.
// Step 3: Compare the value of EVEN and ODD and this is how the first player, here Player A must begin its selection.
// if (EVEN > ODD), start choosing from the right-hand corner and select all the even placed coins.
// if (EVEN < ODD), start choosing from the left-hand corner and select all the odd placed coins.
// if (EVEN == ODD), use a dynamic strategy to maximize the value based on the immediate and subsequent possible values (see approach below).
// Example: Suppose you are given the following rows of coins:

// 18 20 15 30 10 14
// Coins at even places: 20, 30, 14 Coins at odd places: 18, 15, 10 These places are fixed independent of whether the choice of selection must begin from the left or the right-hand side.

// Step 1: Sum of all even placed coins = 20 + 30 + 14 = 64

// Step 2: Sum of all odd placed coins = 18 + 15 + 10 = 43

// Step 3: Comparing the even and the odd placed coins where EVEN > ODD Therefore, Player A must start selecting from the right-hand side and choose all the even-placed coins every time(here they are 14, 30 and 20). So first picker, Player A picks 14. Now, irrespective of whether the second Player B starts selecting from the left-hand side i.e., 18 or from the right-hand side i.e., 10, the even placed coins i.e., 14, 30 and 20 are booked for the Player A. Therefore, be it any situation that arises, the first picker Player A will always win the game.

// Illustration: Here are the illustrations to both the cases of pick by Player B:

// Case 1: When Player B starts picking from the left corner.Case 2: When Player B starts picking from the right corner after Player A.

// Dynamic Strategy for EVEN = ODD:

// When EVEN = ODD, Player A should dynamically evaluate the potential outcomes of the first few moves and choose the highest immediate benefit while considering the opponent’s optimal responses.

// Example: Suppose you are given the following rows of coins:

// 5, 2, 3, 4, 2, 4
// Sum of even-placed coins: 2 + 4 + 4 = 10
// Sum of odd-placed coins: 5 + 3 + 2 = 10
// In this case, since EVEN == ODD, Player A should dynamically choose based on immediate benefit:

// Player A picks 5 (left end), remaining: 2,3,4,2,42, 3, 4, 2, 42,3,4,2,4
// Player B picks 4 (right end), remaining: 2,3,4,22, 3, 4, 22,3,4,2
// Player A picks 2 (left end), remaining: 3,4,23, 4, 23,4,2
// Player B picks 2 (right end), remaining: 3,43, 43,4
// Player A picks 4 (right end), remaining: 333
// Player B picks 3, game over.
// Totals:

// Player A: 5 + 2 + 4 = 11
// Player B: 4 + 2 + 3 = 9
// Player A wins.
