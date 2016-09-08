/**
 * Created by antoinetamano on 08/11/15.
 */
var _ = require('lodash')
    , utils = require('../lib/utils');

function getNeighbors(puzzle) {
    var neighbors = [];

    var inc = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    for (var i = 0; i < puzzle.size; i++) {
        for (var j = 0; j < puzzle.size; j++) {
            if (puzzle.puzzle[i][j] === 0 ) {
                for (var k = 0; k < inc.length; k++) {
                    var neighbor = _.map(puzzle.puzzle, utils.arrayClone);
                    if (neighbor[i + inc[k][0]] && neighbor[i + inc[k][0]][j + inc[k][1]]) {
                        neighbor[i][j] = neighbor[i + inc[k][0]][j + inc[k][1]];
                        neighbor[i + inc[k][0]][j + inc[k][1]] = 0;
                        neighbors.push({
                                size: puzzle.size,
                                puzzle: neighbor,
                                xy: { x: i + inc[k][0], y: j + inc[k][1] }
                            });
                    }

                }
                break;
            }
        }
    }
    return neighbors;
}

module.exports = {
    getNeighbors : getNeighbors
};