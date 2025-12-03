;;;; huffman.lisp
;;;; Huffman encoding algorithm implementation

;;; HUFFMAN
;;; takes in an association list ex: ((a 3) (b 4))
;;; returns the huffman tree
(defun HUFFMAN (assoc-list)
    (huffman-h (make-pq assoc-list))
)

;;; huffman-h
;;; takes in a priority queue
;;; takes the first trees the priority queue, combines them
;;; and inserts the combination back into the priority queue
(defun huffman-h (pq)
  (cond
    ((null (cdr pq)) (extract-min pq))
    (t (huffman-h
         (insert (huffman-rest pq) (combine-trees (extract-min pq) (extract-min (rest pq))))
        )
    )
  )
)

;;; RETURN-CODES
;;; takes in a huffman tree and the symbols the user wants the binary representation of
(defun RETURN-CODES (tree symbols)
  (filter-codes (RETURN-CODES-H tree '()) symbols '())
)

;;; RETURN-CODES-H
;;; creates a binary position for each leaf in the tree
(defun RETURN-CODES-H (tree bin-code)
  (cond
    ((null tree) nil)
    ; trees with form (value nil nil) will only have a single symbol
    ((and (null (left tree)) (null (right tree))) (list (append (cdr (value tree)) bin-code)))
    (t(append
       (RETURN-CODES-H (left tree) (append bin-code '(0)))
       (RETURN-CODES-H (right tree) (append bin-code '(1)))
      )
    )
  )
)

;;; filter-codes
;;; checks if the symbol is in the list provided
;;; if it is, appended to match, if not its skipped
(defun filter-codes(codes symbols matches)
  (cond
    ((null codes) matches)
    ((member (get-element (get-code codes)) symbols) (filter-codes (cdr codes) symbols (append matches (list (get-code codes)))))
    (t(filter-codes (cdr codes) symbols matches))
  )
)

;;; get-code
;;; returns the first code in the list
(defun get-code (codes)
  (car codes)
)

;;; get-element
;;; returns the element in the binary code
(defun get-element (code)
  (car code)
)
