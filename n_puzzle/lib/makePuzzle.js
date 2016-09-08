/**
 * Created by antoinetamano on 08/11/15.
 */
var _ = require('lodash');

function swapEmpty(p, s) {
    var idx = _.indexOf(p, 0);
    var poss = [];
    if (parseInt(idx % s) > 0) {
        poss.push(idx - 1)
    }
    if (parseInt(idx % s)  < s - 1) {
        poss.push(idx + 1)
    }
    if (parseInt(idx / s) > 0) {
        poss.push(idx - s)
    }
    if (parseInt(idx / s) < s - 1) {
        poss.push(idx + s)
    }
    var swi = poss[Math.floor((Math.random() * poss.length))];
    p[idx] = p[swi];
    p[swi] = 0;
    return p;
}

function makePuzzle(s) {
    s = parseInt(s);
    var iterations = 100;
    var p = makeGoal(s);
    for (var i = 0; i < iterations; i++) {
        swapEmpty(p, s)
    }
    var result = [];
    var a = 0;
    for (var k = 0; k < s; k++) {
        result[k] = [];
        for (var j = 0; j < s; j++) {
            result[k][j] = p[a++];
        }
    }
    return result;
}

function makeGoal(s) {
    var ts = s * s;
    var puzzle = [];
    for (var i = 0; i < ts; i++) {
        puzzle[i] = -1;
    }
    var cur = 1, x = 0, ix = 1, y = 0, iy = 0;
    while (1) {
        puzzle[x + y * s] = cur;
        if (cur == 0) {
            break;
        }
        cur += 1;
        if (x + ix == s || x + ix < 0 || (ix != 0 && puzzle[x + ix + y * s] != -1)) {
            iy = ix;
            ix = 0;
        }
        else if (y + iy == s || y + iy < 0 || (iy != 0 && puzzle[x + (y + iy) * s] != -1)) {
            ix = -iy;
            iy = 0;
        }
        x += ix;
        y += iy;
        if (cur == s * s) {
            cur = 0
        }
    }
    return puzzle
}

module.exports = {
    makePuzzle: makePuzzle
};
