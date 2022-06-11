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
  console.log(secretaria.mesa);
  let template = '';

  if (secretaria.sensor == "Livre") {
    template += `<p class="estado_green"> ${secretaria.sensor} </p>`;
  } else {
    template += `<p class="estado_red"> ${secretaria.sensor} </p>`;
  }

  var element = "led"+secretaria.mesa;
  console.log(element);
  document.getElementById(element).innerHTML = template;
}
