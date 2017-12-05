var fs = require('fs');
var famliyTree = require('./build/Release/familyTree');
var express = require('express');
var bodyParser = require('body-parser');
var app = express();
var urlencodedParser = bodyParser.urlencoded({ extended: false });

app.use(express.static('../public'));

app.get("/", function(req, res){
  res.status(200).type('html');
  fs.readFile('../public/html/index.html', function(err, data) {
    if (err) {
      console.log('Error loading home page.');
      res.end();
      return;
    }
    res.end(data);
  })
  console.log('Page visited.');
});

app.post('/func', urlencodedParser, function(req, res) {
  var data = req.body;
  console.log('Data received: ');
  console.log(data);
  
  res.status(200)
    .type('json')
    .json({
      isError: false,
      data: "success!"
    }).end();
  
});

var server = app.listen(8888, function () {
  console.log('Listening...');
});