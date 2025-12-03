% node.pl

% getFreq
% returns the freq of the first item in a priority queue
getFreq([[Freq | _], _, _], Freq) :- !.

% getFreq
% returns the freq of an item
getFreq([Freq, _], Freq).

% getSymbols
% returns the symbols list of an item in a priority queue
getSymbols([[_ | Symbols], _, _], Symbols) :- !.

% getSymbols
% returns the symbols list of an item
getSymbols([_, Symbol], [Symbol]).