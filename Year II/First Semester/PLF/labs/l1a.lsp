;a) Write a function to return the difference of two sets.
;contains(l1,l2,...,ln,e) = {
;    false, n = 0
;    true, l1 = e
;    contains(l2,...,ln,e),otherwise
;}

(defun contains (l e)
    (cond 
        ((null l) nil)
        ((= (car l) e) T)
        (T (contains (cdr l) e))
    )
)


;diffSets(l11,l12,...,l1n1, l21,l22,...,l2n2) = {
;    l11,l12,...,l1n1, n2 = 0
;    [], n1 = 0
;    l1 U diffSets(l12,...,l1n, l21,l22,...,l2n, not(present(l21,...,l2n, l1))
;    diffSets(l12,...,l1n, l21,l22,...,l2n, not_present(l21,...,l2n, l1), otherwise
;}


(defun diffSet (l k)
    (cond
         ((null l) nil)
         ((not (contains k (car l))) (cons (car l) (diffSet (cdr l) k)))
         (T (diffSet (cdr l) k))
    )
)

(print (diffSet '(1 2 3 4 5) '(4 5 6 7 8)))

;b) Write a function to reverse a list with its all sublists, on all levels.

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

;my_reverse(l1,l2,...,ln) = {
;   nil, n = 0
;   my_append(my_reverse(l2,...,ln), my_reverse(l1)), l1 is list  
;   my_append(my_reverse(l2,...,ln), l1), otherwise
;}

(defun my_reverse (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (my_append (my_reverse (cdr l)) (list (my_reverse (car l)))))
        (T (my_append (my_reverse (cdr l)) (list (car l))))
    )
)

(print (my_reverse '(1 2 (3 (4 5) (6 7)) 8 (9 10 11))))

; c) Write a function to return the list of the first elements of all list elements of a given list with an odd
; number of elements at superficial level. Example:
;  (1 2 (3 (4 5) (6 7)) 8 (9 10 11)) => (1 3 9).


;my_length(l1,l2,..,ln) = {
;   0, n = 0
;   1 + my_length(l2,...,ln), otherwise
;}

(defun my_length (l)
    (if (null l) 
        0
        (+ 1 (my_length (cdr l)))
    )
)

;odd_list_length(l1,l2,...,ln) = {
;   true, my_length(l) % 2 = 1
;   false, otherwise
;}

(defun odd_list_length (l)
    (= (mod (my_length l) 2) 1)
)

;first_elem(l1,l2,...,ln, f) = {
;   nil, atom l 
;   l1 U first_elem(l2,...,ln), odd_list_length(l) is true
;   first_elem(l2,...,ln), otherwise
;   
;}

(defun first_elem (l)
    (cond
        ((atom l) nil)
        ((odd_list_length l) (cons (car l) (apply 'append (mapcar 'first_elem (cdr l)))))
        (T (apply 'append (mapcar 'first_elem (cdr l))))
    )
)

(print (first_elem '(1 2 (3 (4 5) (6 7)) 8 (9 10 11))))

; d) Write a function to return the sum of all numerical atoms in a list at superficial level.

;sum(l1,l2,...,ln) = {
;   0, n = 0
;   l1 + sum(l2,...,ln) , l1 is number
;   sum(l2,...,ln), otherwise
;}


(defun sum(l)
  (cond
    ((null l) 0)
    ((numberp (car l)) (+ (car l) (sum (cdr l))))
    (t (sum (cdr l)))
  )
)

(print (sum '(1 2 (3 (4 5) (6 7)) 8 (9 10 11))))