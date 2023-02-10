; 1. Write a function to check if an atom is member of a list (the list is non-liniar)

; checkExistence(l,elem) = { 
;   true, if l = elem and l is an atom
;   false, if l != elem and l is an atom
;   checkExistence(l1 elem) or checkExistence(l2 elem) or ... or checkExistence(ln elem) , otherwise
;}

(defun checkExistence(l elem)
  (cond
    ((and (atom l) (equal l elem)) t)
    ((atom l) nil) 
    (t (some #'identity (mapcar #'(lambda (a) (checkExistence a elem)) l)))
  )
)

(print (checkExistence '(1 2 3 ((4 5) (6)) 7 8 9) 9))
(print (checkExistence '(1 2 3 ((4 5) (6)) 7 8 9) -1))