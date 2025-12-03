% pq.pl 

% makePq
% makes a priority queue given an assocation list
makePq(AssocList, PQ) :- 
    makePqH(AssocList, [], PQ).

% makePqH
% helper function for makePq
makePqH([], PQ, PQ).

makePqH([H|T], CurrPQ, PQ) :-
    insert(H, CurrPQ, NewPQ),
    makePqH(T, NewPQ, PQ).

% insert
% inserts an item into the priority queue
insert(Item, PQ, NewPQ) :-
    insertH(Item, PQ, NewPQ).

% insertH
% helper function for insert
insertH(Item, [], [Item]).

insertH(Item, [Min|T], [Item,Min|T]) :-
    getFreq(Item, ItemFreq),
    getFreq(Min, MinFreq),
    ItemFreq =< MinFreq.

insertH(Item, [Min|Tail], [Min|NewTail]) :-
    getFreq(Item, ItemFreq),
    getFreq(Min, MinFreq),
    ItemFreq > MinFreq,
    insertH(Item, Tail, NewTail).

% reverseEach
% reverses each list within a list
reverseEach([], []).

reverseEach([H|T], [RH|RT]) :-
    reverse(H, RH),
    reverseEach(T, RT).

% extractMin
% takes in a priorityqueue and returns the minimum and the new priority queue
extractMin([Node | NewPQ ], NewPQ,  Node).

