/**
 * Created by antoinetamano on 07/11/15.
 */
var _         = require('lodash');
var utils     = require('../lib/utils');

var orientation = {
    'North' : 0,
    'South' : 1,
    'East' : 2,
    'West' : 3
};

function incByDir(goal, dir, xy, nb, inc) {
    while (xy.y >= 0 && xy.y < goal.size && xy.x >= 0 && xy.x < goal.size) {
        if (xy.x === parseInt(goal.size / 2) && xy.y === parseInt(goal.size / 2) && dir === orientation.South)
            return ;
        if (xy.x === parseInt(goal.size / 2) - 1 && xy.y === parseInt(goal.size / 2) && dir === orientation.North)
            return ;
        if (goal.puzzle[xy.y][xy.x] != 0) {
            createGoalReccursive(goal, dir, {x: xy.x + inc[0], y: xy.y + inc[1]}, nb);
            return ;
        }
        goal.puzzle[xy.y][xy.x] = nb++;
        xy.y += inc[2];
        xy.x += inc[3];
    }
    createGoalReccursive(goal, dir, {x: xy.x + inc[0], y: xy.y + inc[1]}, nb);
}

function createGoalReccursive(goal, dir, xy, nb) {
    switch (dir) {
        case (orientation.South):
            incByDir(goal, orientation.West, xy, nb, [-1, -1, 1, 0]);
            break;
        case (orientation.North):
            incByDir(goal, orientation.East, xy, nb, [1, 1, -1, 0]);
            break;
        case (orientation.West):
            incByDir(goal, orientation.North, xy, nb, [1, -1, 0, -1]);
            break;
        case (orientation.East):
            incByDir(goal, orientation.South, xy, nb, [-1, 1, 0, 1]);
            break;
    }
}

function createGoal (initial, dir, xy, nb) {
    var goal = _.clone(initial);
    goal.puzzle = _.map(goal.puzzle, function(n) {
        return _.map(n, function() { return 0; });
    });
    createGoalReccursive(goal, dir, xy, nb);
    goal.xy = utils.getIndexOf(0, goal);
    return goal;
}

module.exports = {
    createGoal : createGoal
};