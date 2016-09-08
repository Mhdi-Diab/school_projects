/**
 * Created by antoinetamano on 06/11/15.
 */
var StringSet = require('Set')
    , Heap = require('heap')
    , dict = require('dict')
    , Q = require('q')
    , _ = require('lodash');

function aStar(params) {

    var weight = params.weight;
    var hash = params.getHash;
    var endPuzzle = params.endPuzzle;
    var startPuzzle = {
        data: params.startPuzzle,
        g: 0,
        h: params.getHeuristic(params.startPuzzle, endPuzzle)
    };
    var bestPuzzle = startPuzzle;

    startPuzzle.f = weight.h * startPuzzle.h;

    var closedDataSet = new StringSet();
    var openHeap = new Heap(heapComparator);
    var openDataMap = dict();

    openHeap.push(startPuzzle);
    openDataMap.set(hash(startPuzzle.data), startPuzzle);

    var count = 0;
    var max = 0;
    var size;
    var hashGoal = hash(endPuzzle);
    while ((size = openHeap.size())) {
        var puzzle = openHeap.pop();
        count++;
        if (max < size - 1) {
            max = size - 1;
        }
        var hashData = hash(puzzle.data);
        openDataMap.delete(hashData);
        if (hashData === hashGoal) {
            var path = reconstructPath(puzzle);
            return {
                sizeComplexity: max,
                timeComplexity: count,
                numberMoves: path.length - 1,
                path: path
            };
        }
        closedDataSet.add(hashData);
        var neighbors = params.getNeighbors(puzzle.data);

        for (var i = 0; i < neighbors.length; i++) {
            var neighborData = neighbors[i];
            var hashNeighbor = hash(neighborData);
            if (closedDataSet.contains(hashNeighbor)) {
                continue;
            }
            var gFromThisPuzzle = puzzle.g + params.getDistance(puzzle.data, neighborData);
            var neighborPuzzle = openDataMap.get(hashNeighbor);
            var update = false;
            if (neighborPuzzle === undefined) {
                neighborPuzzle = {
                    data: neighborData
                };
                openDataMap.set(hashNeighbor, neighborPuzzle);
            } else {
                if (neighborPuzzle.g < gFromThisPuzzle) {
                    continue;
                }
                update = true;
            }
            neighborPuzzle.parent = puzzle;
            neighborPuzzle.g = gFromThisPuzzle;
            neighborPuzzle.h = params.getHeuristic(neighborData, endPuzzle);
            neighborPuzzle.f = weight.g * gFromThisPuzzle + weight.h * neighborPuzzle.h;
            if (neighborPuzzle.h < bestPuzzle.h) {
                bestPuzzle = neighborPuzzle;
            }
            if (update) {
                openHeap.heapify();
            } else {
                openHeap.push(neighborPuzzle);
            }
        }
    }
    return {
        status: "noPath",
        cost: bestPuzzle.g,
        path: reconstructPath(bestPuzzle)
    };
}

function reconstructPath(puzzle) {
    if (puzzle.parent !== undefined) {
        var pathSoFar = reconstructPath(puzzle.parent);
        pathSoFar.push(puzzle.data);
        return pathSoFar;
    }
    return [puzzle.data];
}

function heapComparator(a, b) {
    return a.f - b.f;
}

module.exports = {
    aStar : aStar
};