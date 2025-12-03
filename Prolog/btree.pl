% btree.pl

% makeTree
% recieves two nodes and combines them into one node
makeTree(Node1, Node2, Result) :-
    getFreq(Node1, Freq1),
    getFreq(Node2, Freq2),
    Sum is Freq1 + Freq2,
    getSymbols(Node1, Symbols1),
    getSymbols(Node2, Symbols2),
    append(Symbols1, Symbols2, SymbolsResult),
    Result = [[Sum|SymbolsResult], Node1, Node2].


% returnCodes
% recieves a huffman tree, the desired symbols, and returns the codes for the desired symbols
returnCodes(Tree, Symbols, FilteredCodes) :-
    returnCodesH(Tree, [], AllCodes),
    filterCodes(AllCodes, Symbols, FilteredCodes).

% returnCodesH
% helper function for return codes
returnCodesH([_, Symbol], BinCode, [[Symbol|BinCode]]).
 
returnCodesH([[_|_], Left, Right], BinCode, Codes) :-
    append(BinCode, [0], LeftCode),
    append(BinCode, [1], RightCode),
    returnCodesH(Left, LeftCode, LeftCodes),
    returnCodesH(Right, RightCode, RightCodes),
    append(LeftCodes, RightCodes, Codes).

% filterCodes
% takes in a list of codes and filters them based on what is passed in
filterCodes(_, [], []).

filterCodes(AllCodes, [Symbol|RestSymbols], [Code|RestCodes]) :-
    member([Symbol|BinCode], AllCodes),
    Code = [Symbol|BinCode],
    filterCodes(AllCodes, RestSymbols, RestCodes).