const http = require('http');
const url = require('url');
const fs = require('fs');

const server = http.createServer(function (request, response) {
  const parsedUrl = url.parse(request.url,true);
  switch(parsedUrl.pathname) {
    case '/load':
    if(request.method == "POST"){
      requestRanking(request, response);
    }
    break;
  }
});


function requestRanking(request,response){
  fs.readFile('data1.json',function(err,data) {
    if(! err) {
      dados = JSON.parse(data.toString());
      response.writeHead(200, {'Content-Type': 'application/javascript','Cache-Control': 'no-cache','Access-Control-Allow-Origin': '*'})
      response.write(JSON.stringify(dados));
      response.end();
    }
  });
}

server.listen(5000);
