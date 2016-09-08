# school_projects
some of my school projects at Ecole 42

## libft (C)
own library of:
- linked list simple and circular (with merge sort)
- binary trees (with red & black balance)
- hashtable dictionary

## linear regression (Python)
Introduction to machine learning.
Program that predicts the price of a car by using a linear function train with a gradient descent algorithm
#### How it works:
```
python linear_reg.py
```
(to load the data in Datasets directory)

####options:
- g: to draw a graph representing the data set and the linear regression
- i: to set the number of iterations (default: 1000)
- s: to set the learning rate (default: 0.1)
- p: to print all theta values into a file
- e: to print estimation errors
```
python main.py
```
**type de number of miles the car has travelled**

## npuzzle (Javascript / Express)
N-puzzle game solver using the Astar search algorithm.

### Installation
```
npm install
```
## Launch  on terminal
Create a npuzzle map file
```
python doc/npuzzle-gen.py -s -i 150 4 > test.txt
```
#### options:
- s: solvable
- u: unsolvable
- i [nb]: number of iterations
- last option: size of the puzzle

Launch the solver on the generated npuzzle map file
```
node ./bin/main.js test.txt  [-m -h -e] [-g -u]
```
#### options:
- m: manhattan heuristic
- h: hamming heuristic
- e: euclidian heuristic
- g: sets greedy (heuristics = 0 => fast)
- u: sets uniform cost (djiskstra => long)

### Launch it on browser:
This command launches an express server
```
npm start
```
Then go to [localhost:4242](http://localhost:4242)

## taskmaster (Python)
Fully-fledged job control daemon similar to supervisor

### Installation
```
pip install pyyaml
```
configs of the program could be changed in config/default_config.yml

# other projects

##study heroes (Symfony2, Angular, Ionic)
Mobile application that use Gamification and science to make learning fun and effective for students.
[Study Heroes](http://studyheroes.fr/)

##shorei kan (Symfony2, React Redux)
(in progress)
Website with an admin panel, a blog, a newsletter, google map integration etc.
[Shorei Kan Europe](http://shorei-kan-europe.com/)
