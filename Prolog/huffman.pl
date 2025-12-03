% huffman.pl
% Chase Gartner

% Huffman Encoding Algorithm

% huffman
% recieves an assocation list and returns a huffman tree
huffman([], []).

huffman(AssocList, Tree):-
    % Citation to get rid of Ellipses in Output: https://stackoverflow.com/questions/4964782/why-appears-in-my-answer-of-matrix-in-prolog
    set_prolog_flag(answer_write_options, [quoted(true), portray(true), max_depth(0), spacing(next_argument)]),
    reverseEach(AssocList, NewAssocList),
    makePq(NewAssocList, PQ),
    extractMin(PQ, NewPQ, MIN1),
    huffmanH(NewPQ, MIN1, Tree).

% huffmanH
% helper function for huffman
huffmanH([], Tree, Tree).

huffmanH(PQ, MIN1, Tree) :- 
    extractMin(PQ, NewPQ1, MIN2),
    makeTree(MIN1, MIN2, NewNode),
    insert(NewNode, NewPQ1, NewPQ2),
    extractMin(NewPQ2, ReturnPQ, NewMin),
    huffmanH(ReturnPQ, NewMin, Tree).
