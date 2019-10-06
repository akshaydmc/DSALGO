def sum_of_digits(temp):
	sod = 0
	while temp != 0:
		sod += temp % 10
		temp //= 10
	return sod

def main():
	print('Sum of digits: ' +str(sum_of_digits(6)))
	#Sum of digits: 6
	print('Sum of digits: ' +str(sum_of_digits(93)))
	#Sum of digits: 12
	print('Sum of digits: ' +str(sum_of_digits(864)))
	#Sum of digits: 18

if __name__ == '__main__':
	main()
