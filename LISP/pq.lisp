;;;; pq.lisp
;;;; Priority Queue Interface and Implementation

;;; make-pq
;;; takes in an association list ex: ((a 3) (b 6))
;;; passes it and an empty list to the helper function
(defun make-pq (assoc-list)
    (make-pq-h assoc-list '())
)

;;; make-pq-h
;;; takes in an association list and the priority queue that we are building tail recursively
;;; inserts a tree of the first element of the association list into the priority queue
(defun make-pq-h (assoc-list pq)
    (cond 
        ((null assoc-list) pq)
        (t(make-pq-h (cdr assoc-list) (insert pq (make-tree(car assoc-list)))))
    )
)

;;; insert
;;; takes in a priority queue and an item to insert
;;; sends those elemenets to the helper function with an empty list
(defun insert(pq item)
    (insert-h pq item '())
)

;;; insert-h
;;; inserts the tree into the priority queue based on frequency
;;; lower the frequency, the higher the priority
(defun insert-h(pq item newlist)
    (cond 
        ((null pq) (append newlist (list item)))
        ((>= (get-frequency(car pq)) (get-frequency item))(append newlist (cons item pq)))
        (t(insert-h (cdr pq) item (append newlist (list (car pq)))))
    )
)

;;; extract-min
;;; returns the first element of the priority queue
(defun extract-min(pq)
    (car pq)
)

;;; huffman-rest
;;; returns everything but the first two elements in the pq
(defun huffman-rest(pq)
    (cddr pq)
)
