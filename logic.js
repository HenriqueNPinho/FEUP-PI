function ranking_fill(data){ // TRABALHO 2
    var table = document.getElementById('pontt');
  
    //console.log(data.ranking);
    //console.log(scoreboard);
    let result = data.reduce((acc,cur) =>
    acc.push(Object.values(cur)) && acc, [Object.keys(data[0])])
    var html = '<table class="pont">';
    html += '<tr">';
    html += '<th>' + "utilizador" + '</th>';
    html += '<th>' + "Vitórias" + '</th>';
    html += '<th>' + "Jogos" + '</th>';
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
  
  