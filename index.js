const http = require('http');
const fs = require('fs');
const port = 8000
var json = require('./data.json'); //(with path)
var obj = JSON.parse(json);


var server = http.createServer(function(request, response) {
  console.log(obj)
  fs.readFile('./index.html', function(err, html) {
    response.writeHeader(200, {"Content-Type": "text/html"});  
    response.write(html);
    response.end();
  })
})

server.listen(port, function() {
  console.log(`Server running at http://localhost:${port}/`);
})
  