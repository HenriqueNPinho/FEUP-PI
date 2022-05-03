var myserver = 'http://localhost:5000/';

function start() {
    setInterval(fds, 5000);
  }

function fds() {
    let object = {};
    serveRequest('load', object);
}

function serveRequest(command, object) {
  const xhr = new XMLHttpRequest();
  xhr.open('POST', myserver.concat(command), true); 
  xhr.onreadystatechange = function() {
    if (xhr.readyState == 4) {
      const data = JSON.parse(xhr.responseText);
      switch(command) {
        case 'load':
            console.log("NIGGER");
        if (data.error) {
          alert(JSON.stringify(data.error));
        } else {
          load(data.leic);
        }
        break;
    }
  }
}
  xhr.send(JSON.stringify(object));
}

function load(data){
    var table = document.getElementById('load');
    let result = data.reduce((acc,cur) =>
    acc.push(Object.values(cur)) && acc, [Object.keys(data[0])])

    var html = '<table class="pont">';
    html += '<tr">';
    html += '<th>' + "mesa" + '</th>';
    html += '<th>' + "sensor" + '</th>';
    html += '<th>' + "name" + '</th>';
    html += '</tr>';

    for( var i = 1; i < result.length; i++) {
        html += '<tr>';
        for( var j in result[i] ) {
            html += '<td>' + result[i][j] + '</td>';
        }
        html += '</tr>';
    }
    html += '</table>';
    table.innerHTML = html;
  }
