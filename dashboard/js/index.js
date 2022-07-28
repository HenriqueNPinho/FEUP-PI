function refreshTime() {
  var dateString = new Date().toLocaleString("pt-PT", {
    timeZone: "Europe/Lisbon",
  });
  var formattedString = dateString.replace(", ", " - ");
  document.getElementById("time").innerHTML = formattedString;
}

setInterval(refreshTime, 1000);


function switchNext(table) {
  
  var element = document.getElementById("color" + table)
  console.log(element.className)
  if(element.className == "estado_green") {
    renderLeic(`{ "desk": "${table}", "sensor": "Unavailable" }`)
  }

  if(element.className == "estado_red") {
    renderLeic(`{ "desk": "${table}", "sensor": "Away" }`)
  }

  if(element.className == "estado_yellow") {
    renderLeic(`{ "desk": "${table}", "sensor": "Free" }`)
  }
}

function renderLeic(message) {
  secretaria = JSON.parse(message);
  console.log(secretaria);
  console.log(secretaria.desk);
  let template = '';
  
  let sensorPT = "Ocupado";
  if(secretaria.sensor == "Free") sensorPT = "Livre";
  if(secretaria.sensor == "Away") sensorPT = "Ausente";

  if (secretaria.sensor == "Free") {
    template += `<p id= "color${secretaria.desk}" class="estado_green"> <i class="fa-solid fa-circle-check fa-bounce" style="font-size:30px;color: #34ace0;"></i> ${sensorPT} </p>`;
  } else if (secretaria.sensor == "Unavailable") {
    template += `<p id= "color${secretaria.desk}" class="estado_red"> <i class="fa-solid fa-hourglass fa-spin" style="font-size:30px;color: #2c2c54;margin-right: 10px"></i> ${sensorPT} </p>`;
  } else if (secretaria.sensor == "Away") {
    template += `<p id= "color${secretaria.desk}" class="estado_yellow"> <i class="fa-solid fa-hourglass fa-spin" style="font-size:30px;color: #2c2c54;margin-right: 10px"></i> ${sensorPT} </p>`;
  }

  var element = "led"+secretaria.desk;
  console.log(element);
  document.getElementById(element).innerHTML = template;
}
