var _         = require('lodash');
var utils     = require('../lib/utils');

function sortForInversions(array, size){
    var save = size;
    var arr = [];
    var x = 0;
    var y = 0;
    var total = size * size--;
    var dx = 1;
    var dy = 0;
    var i = 0;
    var j = 0;
    while (i < total){
        arr.push(array[y * save + x]);
        x += dx;
        y += dy;
        if (++j === size){
            if (dy < 0){
                x++;
                y++;
                size -= 2;
            }
            j = dx;
            dx = -dy;
            dy = j;
            j = 0;
        }
        i++;
    }
    return arr;
}

function countInversions(array, size) {
    array = sortForInversions(array, size);
    var invCount = 0;

    for (var i = 0; i < array.length; i++) {
        if (array[i] === '0') {
            continue ;
        }
        for (var j = i + 1; j < array.length; j++) {
            if (parseInt(array[i]) > parseInt(array[j]) && array[j] !== '0') {
                invCount++;
            }
        }
    }
    return invCount;
}

function isSolvable(initial, goal) {
    var initialInversion = countInversions(initial.puzzle.join().split(','), initial.size);
    var goalInversion = countInversions(goal.puzzle.join().split(','), goal.size);
    if (initial.size % 2 === 0) {
        initialInversion += Math.floor(utils.getIndexOf(0, initial).x / initial.size);
        goalInversion += Math.floor(utils.getIndexOf(0, goal).x / initial.size);
    }
    return (initialInversion % 2 === goalInversion % 2);
}

module.exports = {
    isSolvable : isSolvable
};
