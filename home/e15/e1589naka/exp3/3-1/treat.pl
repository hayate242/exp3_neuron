/*
treat(X,Y):-veterinarian(X),is_animal(Y).

veterinarian(X):-has_qualification(X). 
is_animal(X):-is_dog(X).
*/

has_qualification(taro).
is_dog(john).            

veterinarian(X):-has_qualification(X). 
is_animal(X):-is_dog(X).

treat(X,Y):-veterinarian(X),is_animal(Y).
