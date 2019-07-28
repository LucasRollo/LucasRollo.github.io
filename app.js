//jshint esversion:6

const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");

const app = express();
app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static(__dirname + '/public'));
app.set('view engine', 'ejs');

app.get("/", function(req,res){

  res.render("home");
});




app.listen(3000, function(){
  console.log("server started on port 3000");
});
