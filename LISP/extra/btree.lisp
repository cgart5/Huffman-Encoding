;;;; btree.lisp
;;;; Binary Tree Implementation for Huffman Encoding

;;; combine-trees
;;; takes in two trees, retrieves their roots frequencies and letters
;;; sums frequencies and combines list of letters into 'root node'
;;; and appends two trees into the left and right elements of the root 
(defun combine-trees (tree1 tree2)
  (list (append (list (+ (get-frequency tree1) (get-frequency tree2))) (get-letters tree1)(get-letters tree2)) tree1 tree2)
)

;;; get-frequency
;;; returns the frequency of the tree
(defun get-frequency (tree)
    (car (car tree))
)

;;; get-letters
;;; returns the list of letters of the tree
(defun get-letters (tree)
  (cdr (car tree))
) 

;;; make-tree
;;; takes in an association ex: (a 4) and creates an initial tree
;;; ex: (a 4) -> ((4 a) nil nil)
(defun make-tree (assoc)
  ; frequency value is switched so it will always be the first element in the first list
  (list (list (cadr assoc) (car assoc)) nil nil)
)

;;; value
;;; returns the value list of the tree
(defun value (tree)
  (car tree)
)

;;; left
;;; returns the left tree
(defun left (tree)
  (cadr tree)
)

;;; right
;;; returns the right tree
(defun right (tree)
  (caddr tree)
)