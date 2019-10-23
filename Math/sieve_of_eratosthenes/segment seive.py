# Python3 program to print all primes 
# smaller than n, using segmented sieve 
import math 
prime = [] 

# This method finds all primes 
# smaller than 'limit' using 
# simple sieve of eratosthenes. 
# It also stores found primes in list prime 
def simpleSieve(limit): 
	
	# Create a boolean list "mark[0..n-1]" and 
	# initialize all entries of it as True. 
	# A value in mark[p] will finally be False 
	# if 'p' is Not a prime, else True. 
	mark = [True for i in range(limit + 1)] 
	p = 2
	while (p * p <= limit): 
		
		# If p is not changed, then it is a prime 
		if (mark[p] == True): 
			
			# Update all multiples of p 
			for i in range(p * p, limit + 1, p): 
				mark[i] = False
		p += 1
		
	# Print all prime numbers 
	# and store them in prime 
	for p in range(2, limit): 
		if mark[p]: 
			prime.append(p) 
			print(p,end = " ") 
			
# Prints all prime numbers smaller than 'n' 
def segmentedSieve(n): 
	
	# Compute all primes smaller than or equal 
	# to square root of n using simple sieve 
	limit = int(math.floor(math.sqrt(n)) + 1) 
	simpleSieve(limit) 
	
	# Divide the range [0..n-1] in different segments 
	# We have chosen segment size as sqrt(n). 
	low = limit 
	high = limit * 2
	
	# While all segments of range [0..n-1] are not processed, 
	# process one segment at a time 
	while low < n: 
		if high >= n: 
			high = n 
			
		# To mark primes in current range. A value in mark[i] 
		# will finally be False if 'i-low' is Not a prime, 
		# else True. 
		mark = [True for i in range(limit + 1)] 
		
		# Use the found primes by simpleSieve() 
		# to find primes in current range 
		for i in range(len(prime)): 
			
			# Find the minimum number in [low..high] 
			# that is a multiple of prime[i] 
			# (divisible by prime[i]) 
			# For example, if low is 31 and prime[i] is 3, 
			# we start with 33. 
			loLim = int(math.floor(low / prime[i]) *
										prime[i]) 
			if loLim < low: 
				loLim += prime[i] 
				
			# Mark multiples of prime[i] in [low..high]: 
			# We are marking j - low for j, i.e. each number 
			# in range [low, high] is mapped to [0, high-low] 
			# so if range is [50, 100] marking 50 corresponds 
			# to marking 0, marking 51 corresponds to 1 and 
			# so on. In this way we need to allocate space 
			# only for range 
			for j in range(loLim, high, prime[i]): 
				mark[j - low] = False
				
		# Numbers which are not marked as False are prime 
		for i in range(low, high): 
			if mark[i - low]: 
				print(i, end = " ") 
				
		# Update low and high for next segment 
		low = low + limit 
		high = high + limit 

# Driver Code 
n = 100
print("Primes smaller than", n, ":") 
segmentedSieve(100) 
 
