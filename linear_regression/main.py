#!/usr/bin/python

def getThetas():
	try:
		f = open('results.txt', 'r')
		theta0 = float(f.readline())
		theta1 = float(f.readline())
		minX = float(f.readline())
		maxX = float(f.readline())
		f.close()
		return [theta0, theta1, minX, maxX]
	except:
		print "This car is worth 0 euro."
		exit()

def getUserInput():
	try:
		print "Please enter a mileage:"
		mileage = float(raw_input())
		return mileage
	except:
		print "Error: Enter an floateger input !"

def calculatePrice(theta0, theta1, mileage, minX, maxX):
	price = theta0  + theta1  * (mileage - minX) / (maxX - minX)
	print "This car is worth %d euros." % (price)

def main():
	theta0, theta1, minX, maxX = getThetas()
	mileage = getUserInput()
	calculatePrice(theta0, theta1, mileage, minX, maxX)

if __name__ == '__main__':
	main()
