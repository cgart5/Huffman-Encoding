stSub(_, _, [], []).
stSub(Old, New, [Old | XS], [New | Result]) :- stSub(Old, New, XS, Result).
stSub(Old, New, [X | XS], [X | Result]) :- 
    Old < > X,
    stSub(Old, New, XS, Result).