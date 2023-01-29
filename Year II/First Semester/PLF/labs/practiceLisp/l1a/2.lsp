;Build a list with the positions of the minimum number from a linear list. 

;minimum(l1,...,ln) = {
;   10000, n = 0
;   min(l1, minimum(l2,...,ln)), l1 is a number
;   minimum(l2,...,ln), otherwise
;}


(defun minimum (l)
    (cond
        ((null l) 10000)
        ((numberp (car l)) (min (car l) (minimum (cdr l))))
        ((atom (car l)) (minimum (cdr l)))
    )
)

;(print (minimum '(1 2 3 1 0 9 8 10 1)))


;positions(l1,...,ln,e,cp) = {
;   nil, n = 0
;   cp U positions(l2,...,ln,e,cp + 1), l1 = e
;   positions(l2,...,ln,e,cp + 1), otherwise
;}


(defun positions (l e cp)
    (cond
        ((null l) nil)
        ((= (car l) e) (cons cp (positions (cdr l) e (+ cp 1))))
        (T (positions (cdr l) e (+ cp 1)))
    )
)

(defun mainPosMin (l)
    (positions l (minimum l) 1)
)

(print (mainPosMin '(1 2 3 1 9 8 10 1)))
