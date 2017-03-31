
(defvar a)
(defvar b)
(defvar c)
(defvar d)

(write-line " Enter two numbers ")
	(setf a(read))
	(setf b(read))
		
	(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c(+ a b))
	(print " Addition in binary ")
	(format t " ~b " c)
	(print " Add in decimal ")
	(print c))))		

