// This is the server. It will only take vales from the 'Module' and provide the webpage.
// Exactly how will  it provide the webpage??
// That is yet to be figured out

var http = require('https');
var fs = require('fs');
var express = require('express');
var app = express();
app.use(express.static('libraries'));

app.set('view engine', 'ejs');

var level = 5;
app.get('/level', function(req, res){
    console.log(req.query);
    level = req.query.level;
    console.log(level);
    res.end();
});

app.get('/', function(req,res) {
    res.render('templet', {lev: level});
});


app.listen(8000, '192.168.0.110');
console.log('Bro! Im listening on port: 8000');
