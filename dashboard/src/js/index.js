function refreshTime() {
  var dateString = new Date().toLocaleString("pt-PT", {
    timeZone: "Europe/Lisbon",
  });
  var formattedString = dateString.replace(", ", " - ");
  document.getElementById("time").innerHTML = formattedString;
}

setInterval(refreshTime, 1000);

function renderLeic(message) {
  secretaria = JSON.parse(message);
  console.log(secretaria);
  console.log(secretaria.desk);
  let template = '';
  
  let sensorPT = "Ocupado";
  if(secretaria.sensor == "Free") sensorPT = "Livre";

  if (secretaria.sensor == "Free") {
    template += `<p class="estado_green"> ${sensorPT} </p>`;
  } else {
    template += `<p class="estado_red"> ${sensorPT} </p>`;
  }

  var element = "led"+secretaria.desk;
  console.log(element);
  document.getElementById(element).innerHTML = template;
}
