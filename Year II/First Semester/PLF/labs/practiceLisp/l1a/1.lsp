;Define a function to remove all the occurrences of an element from a nonlinear list. 

;removeOcc(l1,...,ln,e) = {
;   nil, n = 0
;   removeOcc(l1,e) U removeOcc(l2,...,ln,e), l1 is list     
;   removeOcc(l2,...,ln,e), l1 = e
;   l1 U removeOcc(l2,...,ln,e), otherwise
;}


(defun removeOcc (l e)
    (cond
        ((null l) nil)
        ((listp (car l)) (cons (removeOcc (car l ) e) (removeOcc (cdr l) e)))
        ((= (car l) e) (removeOcc (cdr l) e))
        (T (cons (car l) (removeOcc (cdr l) e)))
    )
)

(print (removeOcc '(1 2 (3 8 1) 1 2 7 (3 4 (1 2 1)) 2 7 1 6 ) 1))

