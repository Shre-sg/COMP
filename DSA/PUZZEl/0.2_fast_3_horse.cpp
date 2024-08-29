// There are 25 horses among which you need to find out the fastest 3 horses. You can conduct a race among at most 5 to find out their relative speed. At no point, you can find out the actual speed of the horse in a race. Find out the minimum no. of races which are required to get the top 3 horses.

// Find the fastest 3 horses

// Solution:
// First, we group the horses into groups of 5 and race each group on the race course. This gives us 5 races (see image below).

// Find the fastest 3 horses

// In the image, each row represents one race of 5 horses. For convenience, let us name the horses using the row and column index. Therefore, the first race(row 1) was contested between the horses R1C1, R1C2, R1C3, R1C4 and R1C5. The second race (row 2) was contested between the horses R2C1, R2C2 and so on. Let us assume that the fifth member of each row won the race (R1C5 won the first race, R2C5 won the second race and so on), the fourth member of each row came second (R1C4 came second in the first race, R2C4 came second in the second race and so on) and the third member of each group came third (R1C3 came third in the first race, R2C3 came third in the second race and so on).

// Find the fastest 3 horses

// Next, we race the 5 level 1 winners (R1C5, R2C5, R3C5, R4C5 and R5C5). Let’s say R1C5 wins this race, R2C5 comes second and R3C5 comes third.

// Find the fastest 3 horses

// The winner of this race (R1C5) is the fastest horse of the entire group. Now, the horse which is second in the entire group can either be R2C5 or R1C4. The horse which is third in the entire group can either be R3C5, R2C4 or R1C3. Therefore, we race these 5 horses.

// Find the fastest 3 horses

// Therefore, the horse R1C5 is the fastest horse. The horses which come first and second in the last race are the horses which are second and third in the entire group respectively. in this way, the minimum number of races required to determine the first, second and third horses in the entire group is 7.

// Alternate Explanation:
// Make group of 5 horses and run 5 races. Suppose five groups are [a, b, c, d, e] and next alphabet is its individual rank in this group(of 5 horses).for eg. d3 means horse in group d and has rank 3rd in his group. [ 5 RACES DONE ]
// a1 b1 c1 d1 e1
// a2 b2 c2 d2 e2
// a3 b3 c3 d3 e3
// a4 b4 c4 d4 e4
// a5 b5 c5 d5 e5

// Now make a race of (a1,b1,c1,d1,e1).[RACE 6 DONE] suppose result is a1>b1>c1>d1>e1
// which implies a1 must be FIRST.
// b1 and c1 MAY BE(but not must be) 2nd and 3rd.
// FOR II position, horse will be either b1 or a2
// (we have to find top 3 horse therefore we choose horses b1,b2,a2,a3,c1 do racing among them [RACE 7 DONE].
// The only possibilities are :
// c1 may be third
// b1 may be second or third
// b2 may be third
// a2 may be second or third
// a3 may be third
// The final result will give ANSWER. suppose result is a2>a3>b1>c1>b2
// then answer is a1,a2,a3,b1,c1.
// HENCE ANSWER is 7 RACES