var _         = require('lodash');
var utils     = require('../lib/utils');

function getArgs(puzzleInfo) {
  var size = _.filter(puzzleInfo, function(info) {
    return info.match(/^\d{1,2}$/) !== null;
  });
  size = parseInt(size[0]);
  if (isNaN(size) || size < 2) {
    console.log('Error: Could not parse size, expected integer between 2 and 99');
    return ;
  }
  var removeCommentMap = _.filter(puzzleInfo, function(n) { //Remove global comment
	 	if (n[0] != "#")
   			return n;
 		});
  removeCommentMap.splice(0,1); //Remove size
  if (removeCommentMap.length != size)
  {
 	 console.log('Error: Size does not match the real size');
 	 return null;
  }

  var tab = [];
  var storedNumbers = []
  for (i in removeCommentMap){
	  var splitLine = removeCommentMap[i].trim();
	  splitLine = splitLine.replace(/\s\s+/g, ' ');
	  splitLine = splitLine.split(" ");
	  for (j in splitLine)
	  {
		  if ((isNaN(parseInt(splitLine[j])) && j < size) || (splitLine[j][0] !== "#" && j == size))
		  {
			console.log('Error: Parsing error in file, at puzzle row ' + i);
		  	return null;
		  }
		  splitLine[j] = parseInt(splitLine[j]);
		  if (splitLine[j] < 0 || splitLine[j] >= size * size)
		  {
			  console.log('Error: Number must between 0 and ' + parseInt(size*size) + ', at puzzle row ' + i);
  		  	  return null;
		  }
		  if (storedNumbers.indexOf(splitLine[j]) === -1)
		  	storedNumbers[storedNumbers.length] = splitLine[j];
		  else {
			  console.log('Error: Number ' + splitLine[j] + ' was already in the puzzle');
  			  return null;
		  }
	  }
	  if (splitLine[splitLine.length - 1][0] == "#")
	  {
		  splitLine.splice(splitLine.length - 1,1);
	  }
	  tab[tab.length] = splitLine;
  }

    for (i in tab){
		if (tab[i].length != size)
		{
			console.log('Error: At least one line does not have a matching size');
			return null;
		}
	}
  var result = {
    'size': size,
    'puzzle': tab
  };
  result.xy = {x: utils.getIndexOf(0, result, false), y: utils.getIndexOf(0, result, true)};
  return result;
}

module.exports = {
  getArgs : getArgs
};
