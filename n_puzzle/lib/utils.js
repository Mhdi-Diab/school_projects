/**
 * Created by antoinetamano on 07/11/15.
 */

function arrayClone(arr) {
    var i, copy;

    if (Array.isArray(arr)) {
        copy = arr.slice(0);
        for (i = 0; i < copy.length; i++) {
            copy[i] = arrayClone(copy[i]);
        }
        return copy;
    } else if( typeof arr === 'object' ) {
        throw 'Cannot clone array containing an object!';
    } else {
        return arr;
    }
}

function getIndexOf(number, puzzle) {
    for (var i = 0; i < puzzle.size; i++) {
        for (var j = 0; j < puzzle.size; j++) {
            if (parseInt(puzzle.puzzle[i][j]) === number) {
                return { x: j, y: i };
            }
        }
    }
}

function isSamePuzzle(puzzle, goal) {
    for (var i = 0; i < puzzle.size; i++) {
        for (var j = 0; j < puzzle.size; j++) {
            if (puzzle.puzzle[i][j] !== goal.puzzle[i][j]) {
                return false;
            }
        }
    }
    return true;
}

function myHash(npuzzle) {
    return npuzzle.puzzle.join('');
}

module.exports = {
    arrayClone : arrayClone,
    isSamePuzzle : isSamePuzzle,
    myHash     : myHash,
    getIndexOf : getIndexOf
};