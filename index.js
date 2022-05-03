const http = require('http');
const fs = require('fs');
const port = 8000
//(with path)


var server = http.createServer(function(request, response) {
  
  fs.readFile('./index.html', function(err, html) {
    response.writeHeader(200, {"Content-Type": "text/html"});  
    response.write(html);
    response.end();
  })
})

server.listen(port, function() {
  console.log(`Server running at http://localhost:${port}/`);
})
  