#!/usr/bin/env node
var common = require('../lib/nPuzzle.js');
var make = require('../lib/makePuzzle.js');
var _ = require('lodash');

var args = process.argv;

function printPuzzle(puzzle)
{
	var i;
	var j;

	i = 0;
	while (i < puzzle.length)
	{
		j = 0;
		console.log(puzzle[i].join(" "));
		i++;
	}
}

function main () {
    if (typeof args[2] === 'undefined') {
        console.log('usage: ./bin/main.js file [-m -h -e] [-g -u]');
        return ;
    }
    var arguments = [];
    for (var i = 3; i < args.length; i++) {
        arguments.push(args[i]);
    }
    var result = common.nPuzzle(args[2], arguments.join());
    if (result) {
        _.forEach(result.path, function(n) {

			printPuzzle(n.puzzle);
            console.log('-----------------');
        });
        console.log('Time complexity:', result.timeComplexity);
        console.log('Size complexity:', result.sizeComplexity);
        console.log('Number of moves:', result.numberMoves);
    }
}

main();
