const http = require('http');
const url = require('url');
const fs = require('fs');

const server = http.createServer(function (request, response) {
  const parsedUrl = url.parse(request.url,true);
  switch(parsedUrl.pathname) {
    case '/leic_gui':
    if(request.method == "POST"){
      rquestRanking(request, response);
    }
    break;
  }
});


function rquestRanking(request,response){
  fs.readFile('ranking.json',function(err,data) {
    if(! err) {
      dados = JSON.parse(data.toString());
      response.writeHead(200, {'Content-Type': 'application/javascript','Cache-Control': 'no-cache','Access-Control-Allow-Origin': '*'})
      response.write(JSON.stringify(data));
      response.end();
    }
  });
}

server.listen(8141);
