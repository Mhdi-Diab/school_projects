#!/usr/bin/python
import csv, getopt, sys, io
import matplotlib.pyplot as plt

def getDataSets():
	points = []
	i = 0
	with open('Datasets/data.csv', 'rb') as csvfile:
		spamreader = csv.reader(csvfile, delimiter=',')
		for row in spamreader:
			if i != 0:
				points.append([float(row[0]), float(row[1])])
			i += 1
	return points

def computeError(theta0, theta1, points):
	totalError = 0
	for i in points:
		x = i[0]
		y = i[1]
		totalError += (y - (theta1 * x + theta0)) ** 2
	return totalError / float(len(points))

def getMinMax(points):
	maxX = 0
	minX = 1000000
	for p in points:
		if p[0] < minX:
			minX = p[0]
		if p[0] > maxX:
			maxX = p[0]
	return [minX, maxX]

def featureScaling(points, minX, maxX):
	for p in points:
		p[0] = (p[0] - minX) / (maxX - minX)

def printToFile(file, points, flag):
	try:
		f = open(file, flag)
		for p in points:
			f.write(str(p) + '\n')
		f.close()
		return
	except:
		return

def stepGradient(tmp0, tmp1, points, learningRate):
	sum0 = 0
	sum1 = 0
	m = float(len(points))
	for i in points:
		sum0 += tmp1 * i[0] + tmp0 - i[1]
		sum1 += ((tmp1 * i[0] + tmp0) - i[1]) * i[0]
	tmp0 -= learningRate * sum0 / m
	tmp1 -= learningRate * sum1 / m
	return [tmp0, tmp1]

def gradientDescent(points, learningRate, iterations, printThetasToFile):
	tmp0 = 0
	tmp1 = 0
	for i in range(iterations):
		tmp0, tmp1 = stepGradient(tmp0, tmp1, points, learningRate)
		if (printThetasToFile):
			printToFile('thetas.txt', [tmp0, tmp1, '--------------'], 'a')
	return [tmp0, tmp1]

def calcLinear(theta0, theta1, minX, maxX, xs):
	for x in xs:
		x = theta0 + theta1  * (x - minX) / (maxX - minX)
	return xs

def drawGraph(theta0, theta1, minX, maxX):
	points = getDataSets()
	pointX = [point[0] for point in points]
	pointY = [point[1] for point in points]
	line = []
	for lx in pointX:
		line.append(theta0 + theta1  * (lx - minX) / (maxX - minX))
	plt.plot(pointX, pointY, 'ro', pointX, line, '-')
	plt.show()

def getParameters(argv):
	learningRate = 0.1
	iterations = 1000
	drawFlag = False
	printThetasToFile = False
	printErrors = False

	try:
		opts, args = getopt.getopt(argv, "hepgi:ds:d", ["graph=", "iterations="])
	except getopt.GetoptError as err:
		print str(err)
		sys.exit(2)

	for o, a in opts:
		if o == "-g":
			drawFlag = True
		if o == "-i":
			iterations = int(a)
		if o == "-s":
			learningRate = float(a)
		if o == "-p":
			printThetasToFile = True
		if o == "-e":
			printErrors = True
		if o == "-h":
			print "usage: [-g] [-i nb] [-s nb] [-e] [-p]"
			sys.exit(0)
	return [learningRate, iterations, drawFlag, printThetasToFile, printErrors]

def main(argv):
	learningRate, iterations, drawFlag, printThetasToFile, printErrors = getParameters(argv)
	points = getDataSets()
	minX, maxX = getMinMax(points)
	featureScaling(points, minX, maxX)

	[theta0, theta1] = gradientDescent(points, learningRate, iterations, printThetasToFile)
	print "After {0} iterations theta0 = {1}, theta1 = {2}".format(iterations, theta0, theta1)
	if (printErrors):
		print "Error: {0}".format(computeError(theta0, theta1, points))
	printToFile('results.txt', [theta0, theta1, minX, maxX], 'w')
	if (drawFlag):
		drawGraph(theta0, theta1, minX, maxX)

if __name__ == '__main__':
	main(sys.argv[1:])
