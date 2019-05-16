;this function calculates the nth fibbonacci number
(defun fibb (a)
	(if (= a 1) 1 (if (= a 2) 1 (+ (fibb (- a 1)) (fibb (- a 2))))))

;this function iterates up to n and prints each fibbonacci number
(defun fib (n)
	(loop for i from 1 to n do (progn (write (fibb i)) (write-char #\Space)))
)

;(write (fibb 10))
(fib 100)
