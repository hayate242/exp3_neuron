
connected(X,Y):-adjacent(X,Y).
connected(X,Y):-adjacent(X,Z),connected(Z,Y).

adjacent(start,1).
adjacent(1,3).
adjacent(1,2).

/*adjacent(1,3).*/
adjacent(1,4).
adjacent(2,5).
adjacent(2,6).
adjacent(3,7).
adjacent(3,8).
adjacent(4,10).
adjacent(4,9).
adjacent(5,11).
adjacent(5,12).
adjacent(6,14).
adjacent(6,13).
adjacent(7,15).
adjacent(7,16).
adjacent(8,17).
adjacent(8,18).
adjacent(9,19).
adjacent(9,20).
adjacent(16,goal).
