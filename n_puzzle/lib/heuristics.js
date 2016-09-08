/**
 * Created by antoinetamano on 08/11/15.
 */
var utils          = require('../lib/utils');

function getDistance(a, b) {
    var sum = 0;
    for (var i = 0; i < a.size; i++) {
        for (var j = 0; j < a.size; j++) {
            var xy = utils.getIndexOf(a.puzzle[i][j], b);
            sum += Math.abs(j - xy.x) + Math.abs(i - xy.y);
        }
    }
    return sum;
}

function hamming(puzzle, goal) {
    var sum = 0;
    for (var i = 0; i < puzzle.size; i++) {
        for (var j = 0; j < puzzle.size; j++) {
            if (puzzle.puzzle[i][j] !== goal.puzzle[i][j]) {
                sum ++;
            }
        }
    }
    return sum;
}

function euclidian(puzzle, goal) {
    var sumX = 0;
    var sumY = 0;
    for (var i = 0; i < puzzle.size; i++) {
        for (var j = 0; j < puzzle.size; j++) {
            var xy = utils.getIndexOf(puzzle.puzzle[i][j], goal);
            sumX += Math.abs(j - xy.x);
            sumY += Math.abs(i - xy.y);
        }
    }
    return Math.sqrt(sumX * sumX + sumY * sumY);
}

function manhattan(puzzle, goal) {
    var sum = 0;
    for (var i = 0; i < puzzle.size; i++) {
        for (var j = 0; j < puzzle.size; j++) {
            var xy = utils.getIndexOf(puzzle.puzzle[i][j], goal);
            sum += Math.abs(j - xy.x) + Math.abs(i - xy.y);
        }
    }
    return sum;
}

function octile(puzzle, goal){
    var F = Math.SQRT2 - 1;
    var sumX = 0;
    var sumY = 0;
    for (var i = 0; i < puzzle.size; i++) {
        for (var j = 0; j < puzzle.size; j++) {
            var xy = utils.getIndexOf(puzzle.puzzle[i][j], goal);
            sumX += Math.abs(j - xy.x);
            sumY += Math.abs(i - xy.y);
        }
    }
    return (sumX < sumY) ? F * sumX + sumY : F * sumY + sumX;
}

module.exports = {
    manhattan : manhattan,
    hamming : hamming,
    euclidian : euclidian,
    getDistance : getDistance,
    octile : octile
};
