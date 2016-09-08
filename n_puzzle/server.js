var express = require('express');
var session = require('cookie-session'); // Charge le middleware de sessions
var bodyParser = require('body-parser'); // Charge le middleware de gestion des paramètres
var urlencodedParser = bodyParser.urlencoded({ extended: false });
var make = require('./lib/makePuzzle');
var createGoal = require('./lib/createGoal');
var npuzzle = require('./lib/nPuzzle');
var utils = require('./lib/utils');
var _ = require('lodash');
var Q = require('q');

var app = express();

function generatePuzzle(size) {
    return make.makePuzzle(size);
}

app.use(session({secret: 'todotopsecret'}))
    .use(function(req, res, next){
        if (_.isEmpty(req.session.puzzle)) {
            req.session.puzzle = [];
            req.session.goal = [];
            req.session.results = [];
        }
        next();
    })
    .get('/', function(req, res) {
        res.redirect('/puzzle');
    })
    .get('/puzzle', function(req, res) {
        res.render('puzzle.ejs', {
            puzzle: req.session.puzzle,
            goal: req.session.goal,
            results: req.session.results
        });
    })
    .post('/puzzle/ajouter/', urlencodedParser, function(req, res) {
        if (req.body.newtodo != '' && !isNaN(parseInt(req.body.newtodo))) {
            req.session.results = [];
            req.session.size = parseInt(req.body.newtodo);
            var size = req.session.size;
            if (size && size < 11 && size > 2) {
                req.session.puzzle = generatePuzzle(size);
                req.session.goal = createGoal.createGoal({
                    'size': size,
                    'puzzle': req.session.puzzle
                }, 2, {x: 0, y: 0}, 1).puzzle;
            }
        }
        res.redirect('/puzzle');
    })
    .post('/puzzle/solve/', urlencodedParser, function(req, res) {
        var initial = { 'size': req.session.size, 'puzzle': req.session.puzzle };
        var goal = { 'size': req.session.size, 'puzzle': req.session.goal };
        initial.xy = utils.getIndexOf(0, initial);
        goal.xy = utils.getIndexOf(0, goal);
        Q.resolve(npuzzle.solve(initial, goal)).then(function(data) {
            req.session.results = data;
            res.render('puzzle.ejs', {
                puzzle: req.session.puzzle,
                goal: req.session.goal,
                results: req.session.results
            });
        });
    })
    .post('/puzzle/clear/', urlencodedParser, function(req, res) {
        req.session.puzzle = [];
        req.session.goal = [];
        req.session.results = [];
        res.redirect('/puzzle');
    })
    .get('*', function(req, res) {
        res.redirect('/puzzle');
    })
    .listen(4242);
