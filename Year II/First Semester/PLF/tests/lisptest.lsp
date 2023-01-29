;Remove all occurences of a maximum numerical element from a nonlinear list. Example :
; (1 2 3 4 5 6) -> (1 2 3 4 5)

;maximum(l1,...,ln) = {
;   -1, n = 0
;   max(l1, maximum(l2,...,ln)), l1 is a number
;   max(maximum(l1),maximum(l2,...,ln)), otherwise
;}

(defun maximum (l)
    (cond
        ((null l) -1)
        ((numberp (car l)) (max (car l) (maximum (cdr l))))
        (T(max (maximum (car l)) (maximum (cdr l))))
    )
)

;(print (maximum '(1 2 (3 4) (5 (12 13) 6))))

;removeOcc(l1,...,ln,e) = {
;   nil, n = 0
;   removeOcc(l2,...,ln,e), l1 = e
;   l1 U removeOcc(l2,...,ln,e), l1 != e U atom(l1)
;
;   removeOcc(l1,e) U removeOcc(l2,...,ln,e), otherwise
;}

(defun removeOcc (l e)
    (cond
        ((null l) nil)
        ((listp (car l))(cons (removeOcc (car l) e) (removeOcc (cdr l) e)))
        ((and (numberp (car l))(= (car l) e)) (removeOcc (cdr l) e))
        (T(cons (car l) (removeOcc (cdr l) e)))
    )
)

;main(l1,...,ln) = {
;   nil, n = 0
;   removeOcc(l,maximum(l)), otherwise
;}

(defun main(k)
    (cond
        ((null k) nil)
        (T(removeOcc k (maximum k)))
    )
)

(print (main '(1 2 3 4 6 5 6)))
(print (main '(5(4(2 5 1)5 1)2 5 1 (5 4)3)))
(print (main '(A 2(7 B) C F 1(D 7 1 3))))


