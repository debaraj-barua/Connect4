# Artificial Intelligence for Robotics – Lab
<p align = 'center'>
    <b> Prof. Dr. Erwin A. Prassler </b><br>
    <b> Maximilian Schöbel </b>
</p>

### SUBMISSION RULES:

- All results have to be submitted in a single PDF-file.
- Please use the following naming convention for that file:
    YYYYMMDD_<LastNamesOfGroupMembers>_AI<AssignmentNr>.pdf
    (whereYYYYMMDDdenotes the date of the deadline).
- Sourcecode has to be submitted in an extra folder along with all necessary files to run the code.
- Members of teams have to be stated clearly in an additional filemembers.txt, one line per team member.
- Please submit your files in an archive using the following naming convention:
    YYYYMMDD_<LastNamesOfGroupMembers>_AI<AssignmentNr>.tar.gz
- Late submissions will not be regarded.

# Assignment 10

### *Due Date*: Sunday, 11.6.2017, 23:

Implement a simple Connect 4 game to demonstrate the use of adversarial search for deterministic, fully observable, two player turn-taking zero-sum games.

For the adversarial search problem, implement a **minmax** and **alpha-beta pruning**  agent tha tallows you to play against the computer. 

Compare these two approaches based on their search time, space requirement and other information that you think is important. 

You need not implement a nice GUI. A simple console interface is sufficient.

# How to build and run
- Create the _build_ and _bin_ folders

```sh 
mkdir build bin
```
- Build the project and create the binary file
```sh 
cd build && cmake ..
```
```sh
make
```
- Run the program
```sh 
cd ../bin
```
```sh
./Connect4
```


