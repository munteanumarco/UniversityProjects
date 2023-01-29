;inorder traversal of tree of type (2) 

;my_append(l1,l2,...,ln,k) = {
;   k, n = 0
;   l1 U my_append(l2,...,ln,k), otherwise
;}

(defun my_append (l k)
    (if (null l) 
        k
        (cons (car l) (my_append (cdr l) k))
    )
)

; traverse(l1,l2,..,ln) = {
;   nil, n = 0
;   my_append(traverse(l2), my_append(list(l1), traverse(l3))), otherwise
;}

(defun traverse(l)
  (cond
    ((null l) nil)
    (t (my_append (traverse (cadr l)) (my_append (list (car l)) (traverse (caddr l)))))
  )
)

(print (traverse '(A (B) (C (D) (E))) ))