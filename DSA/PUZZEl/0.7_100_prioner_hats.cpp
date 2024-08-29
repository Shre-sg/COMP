// Puzzle 13 | (100 Prisoners with Red/Black Hats)
// https://www.youtube.com/watch?v=RtidKw-qDxY&t=329s

// Last Updated : 19 Jan, 2023
// 100 prisoners in jail are standing in a queue facing in one direction. Each prisoner is wearing a hat of color either black or red. A prisoner can see hats of all prisoners in front of him in the queue, but cannot see his hat and hats of prisoners standing behind him.
// The jailer is going to ask color of each prisoner’s hat starting from the last prisoner in queue. If a prisoner tells the correct color, then is saved, otherwise executed. How many prisoners can be saved at most if they are allowed to discuss a strategy before the jailer starts asking colors of their hats.

// Answer:
// At-most 99 prisoners can be saved and the 100th prisoner has 50-50 chances of being executed.
// The idea is that every prisoner counts number of red hats in front of him.

// 100th prisoner says red if the number of red hats is even. He may or may not be saved, but he conveys enough information to save 99th prisoner.

// The 99’th prisoner decides his answer on the basis of answer of 100’th prisoner’s answer. There are following possibilities and 99’th prisoner can figure out color of his hat in every case.

// If 100’th prisoner said ‘Red’ (There must have been even number of red hats in front of him)
// a) If 99’th prisoner sees even number of red hats in front of him, then his color is black.
// b) If 99’th prisoner sees odd number of red hats in front of him, then his color is red.

// If 100’th prisoner said ‘Black’ (There must have been odd number of red hats in front of him)
// a) If 99’th prisoner sees even number of red hats in front of him, then his color is Red.
// b) If 99’th prisoner sees odd number of red hats in front of him, then his color is Black.

// The 98’th prisoner decides his answer on the basis of answer of 99’th prisoner’s answer and uses same logic.

// Similarly other prisoners from 97 to 1 are saved.

// OR

// They could come up with a strategy where initially two random guys stands at the front, then if both of them have the same color then the third will stand behind them, and in between them if their hats are of different color, now the 4th guy will also do the same, he will stand at a position where hat color changes, else stands at the last position and so on, so at last they will be sorted with same hat colors, 50 in front 50 at back, last guy tells the color of the hat of the guy in front of him and the 51st guy changes the color of his ha