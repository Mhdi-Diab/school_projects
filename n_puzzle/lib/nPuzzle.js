var _ = require('lodash')
    , fs = require('fs')
    , read = require('../lib/readFile')
    , solvable = require('../lib/isSolvable')
    , aStar = require('../lib/aStar')
    , createGoal = require('../lib/createGoal')
    , utils = require('../lib/utils')
    , heuristics = require('../lib/heuristics')
    , neighbor = require('../lib/neighbor');

function solve(initial, goal, args) {
    if (solvable.isSolvable(initial, goal)) {
    var weight = {};
    var heur;

    weight.g = 1;
    weight.h = 4;
    heur = heuristics.manhattan;

    if (typeof args !== 'undefined') {
        if (args.indexOf('u') !== -1) {
            weight.g = 1;
            weight.h = 0;
        }
        else if (args.indexOf('g') !== -1 ) {
            weight.g = 0;
            weight.h = 1;
        }
        if (args.indexOf('h') !== -1 ) {
            heur = heuristics.hamming;
        } else if (args.indexOf('e') !== -1 ) {
            heur = heuristics.euclidian;
        } else if (args.indexOf('o') !== -1 ) {
           heur = heuristics.octile;
       }
    }

    return aStar.aStar({
        'startPuzzle': initial,
        'endPuzzle': goal,
        'isEnd': utils.isSamePuzzle,
        'getNeighbors': neighbor.getNeighbors,
        'getDistance': heuristics.getDistance,
        'getHeuristic': heur,
        'weight': weight,
        'getHash': utils.myHash
    });
    } else {
       console.log('No solution');
    }
}

function nPuzzle(file, args) {
    try {
        var data = fs.readFileSync(file, 'utf8');
        var initial = read.getArgs(data.split('\n'));
        if (initial){
            var goal = createGoal.createGoal(initial, 2, {x: 0, y: 0}, 1);
            return solve(initial, goal, args);
        }
    } catch (err) {
        console.log(err);
        return null;
    }
}

module.exports = {
    nPuzzle : nPuzzle,
    solve : solve
};
