# Ai_Tic-tac-toe
 
<h3> The Min-Max Algorithm is a recursive or backtracking algorithm which helps to find the best move in Tic-Tac-Toe, but needs to run and check for all possibilities and then return the best move. The aim of the proposed system is to reduce the time complexity of the min-max algorithm which is used to find the best move in the game of Tic-Tac-Toe. This proposed model is an extension of the min-max algorithm. This is a C language program AI based Tic-Tac-Toe game. AI is used to find the best moves for the computer's turn. This program works on a tree based approach to give better results then Min-Max algorithm.</h3>

# Flow

![dsa_flowchart](https://user-images.githubusercontent.com/61201836/149081163-4d9e70da-db36-44aa-9fc1-cfaff10fc617.png)

<h4>The program starts with display of a menu which has 2 entities:
1.	New Game
2.	Exit

When we choose “New Game”, it asks for a move from the player. After the move has been entered, it runs the algorithm to search for the move in the general tree against the move entered by the player. If the move is found, the computer plays it. But, if the move is not found in the tree, it goes to the min-max algorithm function and finds the optimal move to play. This move is also stored in the general tree for future use. This loop runs until a winner or draw is declared.

After the end of each loop the main menu appears and many consecutive games can be played.

If the user chooses “Exit”, the program terminates.</h4>
 
# Results and Discussion:

To achieve the mentioned objective and to conclude, we did tests on 3 test cases mentioned below. The test files give input to the program for execution. The program takes the first character of a row as the menu input whether to start a new game (1) or exit (2). The following characters are the player moves. After completion of each game it moves to the next row of the test file. Using this test file, we can run the program for multiple games in an automated way.

The mentioned test cases are executed on both kinds of algorithms for comparison of their time complexities.

test1.txt

![t1](https://user-images.githubusercontent.com/61201836/149082325-f0ca4cb8-c87e-4259-b407-9d909e07b155.png)

test2.txt

![t2](https://user-images.githubusercontent.com/61201836/149082339-71b24a0e-1da0-4bef-8e14-fc4f039fd904.png)
                
test3.txt

![t3](https://user-images.githubusercontent.com/61201836/149082353-9078a405-2e97-44c5-889a-216ffda2b853.png)

Test 1 consists of 28 games in which the computer wins 9 times and draws 19 games. 
Test 2 consists of 30 games in which the computer wins 9 times and draws 21 games. 
Test 3 consists of 23 games in which the computer wins 8 times and draws 15 games. 

The graphs below compares the time complexity of both the algorithms:

 ![r1](https://user-images.githubusercontent.com/61201836/149082563-de96653c-95f3-4cc3-a744-6a583f57126d.png)

![r2](https://user-images.githubusercontent.com/61201836/149082571-130e4a16-0b86-414b-a3a8-8c33b9971a72.png)

 ![r3](https://user-images.githubusercontent.com/61201836/149082581-3aa55594-3975-4519-8d42-239edceddb32.png)


We can see that the graph of the proposed algorithm shows peaks when new games occur, which are almost equal to the time complexity occuring in the other algorithm for the same game. Troughs are seen when similar/same moves occur.

# Conclusion:

The time complexity of min-max varies for different games played but if the game is played again there is no change in the time complexity as the number of recursions will be the same for that particular game.

Whereas in the proposed model, the time complexity of the new games is similar to min-max but it is not same if the similar game is played again. As the proposed model saves the game in a tree structure initially using min-max and when a similar game occurs it directly searches the tree and gets the optimal move. By this we reduce the use of min-max for similar/repeated games, which significantly affects the time complexity in repeated games.
