fun last a = foldl(fn (a,b) => a) (hd a) a;
fun reverse a = foldl(fn (a,b) => a::b) [] a;
fun fibb(b) = if b = 1 then 1::[] else if b = 2 then 1::1::[] else (hd(fibb(b-1)) + hd(tl(fibb(b-1))))::(fibb(b-1));

fun fib(b) = reverse(fibb b);

fun isprimecheck(a, 1) = true
	| isprimecheck (_, 0) = false
	| isprimecheck(0, _) = false
	| isprimecheck (a, b) = if a mod b = 0 then false else isprimecheck(a, b - 1);

fun isprime a = isprimecheck(a, a - 1);


fun primes 0 = []
	| primes n = if (isprime n) then (n::primes(n-1)) else primes(n -1);   

fun prime_list n = reverse(primes n);